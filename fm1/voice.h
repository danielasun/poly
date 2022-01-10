// Voice class
class Voice {
  public:
    Voice(AudioSynthWaveformModulated* wave1,
          AudioSynthWaveformModulated* wave2,  
          AudioEffectEnvelope* env, 
          AudioEffectEnvelope* fenv, 
          AudioFilterStateVariable* filter,
          AudioMixer4* oscmixer,
          AudioMixer4* fmodmixer,
          AudioMixer4* fmixer
          ) {
      
      m_osc1 = wave1;
      m_osc2 = wave2; 
      m_env = env;
      m_fenv = fenv;
      m_filter = filter;
      m_oscmixer = oscmixer;
      m_fmodmixer = fmodmixer;
      m_fmixer = fmixer;

      // initialize voice
      this->m_env->attack(5);
      this->m_env->decay(25);
      this->m_env->sustain(0.25);
      this->m_env->release(1000);
      this->m_fenv->attack(50);
      this->m_fenv->decay(1000);
      this->m_fenv->sustain(0);
      this->m_fenv->release(250);
      this->m_filter->frequency(noteToFreq(100));
      this->m_filter->octaveControl(2);
      this->m_osc1->begin(WAVEFORM_SINE); //0.4, 220, WAVEFORM_SAWTOOTH);
      this->m_osc2->begin(WAVEFORM_SINE); //0.4, 220, WAVEFORM_SAWTOOTH);
      this->m_oscmixer->gain(2, 0);
      this->m_fmodmixer->gain(0, 1);
    }

    void set_osc_frequency(float note_freq, int coarse_detune, float fine_detune){
      this->m_osc1->frequency(note_freq*(1));
      this->m_osc2->frequency(note_freq*detune_ratios[coarse_detune]*(1+fine_detune));
    }

    void noteOn(float note_freq){
      this->set_osc_frequency(note_freq, coarse_detune, fine_detune);
      this->m_env->noteOn();
      this->m_fenv->noteOn();
    }

    void noteOff(){
      this->m_env->noteOff();
    }

    AudioSynthWaveformModulated* m_osc1;
    AudioSynthWaveformModulated* m_osc2;
    AudioEffectEnvelope* m_env;
    AudioEffectEnvelope* m_fenv;
    AudioFilterStateVariable* m_filter;
    AudioMixer4* m_oscmixer;
    AudioMixer4* m_fmodmixer;
    AudioMixer4* m_fmixer;
};

const int nvoices = 1;
Voice voices[nvoices] = {v1, v2, v3, v4};
int freqtable[nvoices] = {-1, -1, -1, -1}; // holds frequencies
int voicenum = 0;

void voice_set_filter_frequency(int voicenum, float fc_freq, float keytrack_amt){
  
  if (freqtable[voicenum] != -1){ // set freq if voice is playing
    // offset frequency according to note that's being played.
    float freq_offset = keytrack_amt*(freqtable[voicenum] - keytrack_pivot);
    float filter_freq = noteToFreq(freqToNote(fc_freq) + freq_offset);
    voices[voicenum].m_filter->frequency(min(filter_freq, FILTER_MAX_FREQ));
    sprintf(buff, "%f %f", freq_offset, filter_freq);
    Serial.print(buff);
  }

}

void voice_noteOn(int voicenum, float note_freq, int note, int velocity){
  voices[voicenum].noteOn(note_freq);
  freqtable[voicenum] = note;
  voices[voicenum].m_osc1->amplitude(velocityToAmplitude[velocity]);
  voices[voicenum].m_osc2->amplitude(velocityToAmplitude[velocity]);
  if (keytrack_amt > 0){
    voice_set_filter_frequency(voicenum, fc_freq, keytrack_amt);
  }
}

void modifyPatch(int cc, byte val, byte * patchdata){
  
  // set patch data
  patchdata[cc] = val;

  AudioNoInterrupts();
  if (cc == 7){ // volume
        amp1.gain(map_cc_to_range_linear(val, 0.0, 1.0));
  }
  if (cc == 8){ // pan
    // constant power panning (https://www.cs.cmu.edu/~music/icm-online/readings/panlaws/)
    float theta = map_cc_to_range_linear(val, 0.0, PI/2);
    mixerL.gain(0, cos(theta));
    mixerR.gain(0, sin(theta));
  }
  if (cc == 20){ // filter env atk
        for(int i=0; i < nvoices; i++){
      voices[i].m_fenv->attack(cc_to_millis(val));
    }
  }
  if (cc == 21){ // filter env decay
        for(int i=0; i < nvoices; i++){
      voices[i].m_fenv->decay(cc_to_millis(val));
    }
  }
  if (cc == 22){ // filter env sustain
    for(int i=0; i < nvoices; i++){
      voices[i].m_fenv->sustain(map_cc_to_range_linear(val, 0.0, 1.0));
    }
  }
  if (cc == 23){ // filter env release
    for(int i=0; i < nvoices; i++){
      voices[i].m_fenv->release(cc_to_millis(val));
    }
  }
  if (cc == 32){ // dc offset
    for(int i=0; i < nvoices; i++){
      float offset_amt = map_cc_to_range_linear(val, 0, 1.0);
      voices[i].m_osc1->offset(offset_amt); 
      voices[i].m_osc2->offset(offset_amt); 
    }
  }
  if (cc == 33){ // pulsewidth
    pulsewidth_dc.amplitude(map_cc_to_range_linear(val, 0.5, 1.0));
  }
  if (cc == 34){ // wavefolder dc
    wavefold_dc.amplitude(map_cc_to_range_linear(val, 0.1, 1.0));
  }
  if (cc == 35){ // coarse detune
    coarse_detune = (int)map_cc_to_range_linear(val, 0, 24.99);
    for (int i=0; i<nvoices; i++){
      if (freqtable[i] !=-1){ // if voice isn't playing
        voices[i].set_osc_frequency(noteToFreq(freqtable[i]), coarse_detune, fine_detune);
      }
    }
  }
  if (cc == 36){ // fine detune
    fine_detune = fine_detune_map(val);
    for (int i=0; i<nvoices; i++){
      if (freqtable[i] !=-1){ // if voice isn't playing
        voices[i].set_osc_frequency(noteToFreq(freqtable[i]), coarse_detune, fine_detune);
      }
    }
  }
  if (cc == 37){ // osc mix
    for(int i=0; i < nvoices; i++){
      // constant power blending (https://www.cs.cmu.edu/~music/icm-online/readings/panlaws/)
      float theta = map_cc_to_range_linear(val, 0.0, PI/2);
      voices[i].m_oscmixer->gain(0, cos(theta));
      voices[i].m_oscmixer->gain(1, sin(theta));
    }
  }
  if (cc == 39){ // pink noise
    float noise_amt = pow_map(map_cc_to_range_linear(val, 0, 1), 2);
    // pink1.amplitude(noise_amt);
    for (int i=0; i<nvoices; i++){
      voices[i].m_oscmixer->gain(2, noise_amt);
    }
  }
  if (cc == 48){ // LFO1 amplitude
    lfoosc1.amplitude(
      pow_map(map_cc_to_range_linear(val, 0.1, 1.0), 3));
  }
  if (cc == 49){ // LFO1 frequency
    lfoosc1.frequency(LFO_MULT*freq_multiplier*noteToFreq(map_cc_to_range_linear(val, 0.0, 100)));
  }
  if (cc == 50){ // LFO1 frequency multiplier
    freq_multiplier = mults[(int)map_cc_to_range_linear(val, 0, 7)];
    lfoosc1.frequency(LFO_MULT*freq_multiplier*noteToFreq(map_cc_to_range_linear(val, 0.0, 100)));
  }
  if (cc == 51){ // LFO1 frequency multiplier
    fmmixer.gain(0, map_cc_to_range_linear(val, 0.0, 1.0));
  }
  if (cc == 70){ // waveform
    for(int i=0; i < nvoices; i++){
      int wave_t = (int)map_cc_to_range_linear(val, 0.0, 3.99);
      voices[i].m_osc1->begin(WAVEFORM_TYPE[wave_t]);
      voices[i].m_osc2->begin(WAVEFORM_TYPE[wave_t]);
    }
  }
  if (cc == 71){ // filter resonance
    for(int i=0; i < nvoices; i++){
      voices[i].m_filter->resonance(map_cc_to_range_linear(val, 0.707, 5.0));
    }
  }
  if (cc == 72){ // sound release
    for(int i=0; i < nvoices; i++){
      voices[i].m_env->release(cc_to_millis(val));
    }
  }
  if (cc == 73){ // sound attack
    for(int i=0; i < nvoices; i++){
      voices[i].m_env->attack(cc_to_millis(val));
    }
  }
  if (cc == 74){ // filter cutoff
    fc_freq = noteToFreq(map_cc_to_range_linear(val, 0, 127)); // used to be 113
    for(int i=0; i < nvoices; i++){
      voice_set_filter_frequency(i, fc_freq, keytrack_amt);
    }
  }
  if (cc == 75){ // sustain
    for(int i=0; i < nvoices; i++){
      voices[i].m_env->sustain(map_cc_to_range_linear(val, 0.0, 1.0));
    }
  }
  if (cc == 76){ // fenv amt
    filter_dc.amplitude(map_cc_to_range_linear(val, -1.0, 3.0), 1);    
  }
  if (cc == 77){ // f type
    // three-way blend between LP, BP and HP
    float type_val = map_cc_to_range_linear(val, 0, PI);
    for(int channel=0; channel<3; channel++){
      float gain_val = tri_map(type_val, channel);
      sprintf(buff, "channel = %d, gain: %f", channel, gain_val);
      Serial.println(buff);
      for(int i=0; i < nvoices; i++){
        voices[i].m_fmixer->gain(channel, gain_val); 
      }
    }
  }
  if (cc == 78){ // f mod
    for(int i=0; i < nvoices; i++){
      voices[i].m_fmodmixer->gain(1, map_cc_to_range_linear(val, 0, 1.0)); // LFO1 mod
    }
  }
  if (cc == 79){ // keytrack
    keytrack_amt = map_cc_to_range_linear(val, 0, 1.0);
    for(int i=0; i < nvoices; i++){
      voice_set_filter_frequency(i, fc_freq, keytrack_amt);
    }
  }
  if (cc == 80){ // sound release
    for(int i=0; i < nvoices; i++){
      voices[i].m_env->decay(cc_to_millis(val));
    }
  }
  if (cc == 85){ // Reverb room size
      freeverbs1.roomsize(map_cc_to_range_linear(val, 0.1, 1));
      freeverbs2.roomsize(map_cc_to_range_linear(val, 0.1, 0.25));
  }
  if (cc == 86){ // Reverb damping
      freeverbs1.damping(map_cc_to_range_linear(val, 0.0, 1));
      freeverbs2.damping(map_cc_to_range_linear(val, 0.0, 0.5));
  }
  if (cc == 87){ // Bit depth
    bitcrusher1.bits((int)map_cc_to_range_linear(val, 0.0, 16.0));
  }
  if (cc == 88){ // sampling rate
    float sr = 4*noteToFreq(map_cc_to_range_linear(val, 0, 127));
    bitcrusher1.sampleRate((int)sr);
  }
  if (cc == 91){ // Reverb send 
    reverbamp.gain(map_cc_to_range_linear(val, 0, 0.5));
  }
  if (cc == 93){ // chorus amount
    mixerL.gain(3,map_cc_to_range_linear(val, 0, 1.0));
    mixerR.gain(3,map_cc_to_range_linear(val, 0, 1.0));
  }
  AudioInterrupts();
}

void setPatchData(byte curr_patch[], byte patch_data[]){ // load patch_data into current patch
  for (int i =0; i<patch::nparams; i++){
    // sprintf(buff, "i: %d, param: %s val: %d", i, patch::parameter_names[i], patch::initpatch[i]);
    // Serial.println(buff);
    modifyPatch(i, patch_data[i], curr_patch);
  }
}
