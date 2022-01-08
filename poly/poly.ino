#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   lfoosc1;        //xy=425.01903533935547,749.6667976379395
AudioMixer4              fmmixer;        //xy=599.0190353393555,706.6667976379395
AudioSynthNoisePink      pink1;          //xy=603.0190353393555,928.6667976379395
AudioSynthWaveformDc     pulsewidth_dc;  //xy=613.0190353393555,884.6667976379395
AudioMixer4              pulsewidth_mixer; //xy=620.0190353393555,823.6667976379395
AudioSynthWaveformModulated waveformMod4;   //xy=889.0190353393555,949.6667976379395
AudioSynthWaveformModulated waveformMod8;   //xy=891.0190353393555,985.6667976379395
AudioSynthWaveformModulated waveformMod6;   //xy=892.0190353393555,743.6667976379395
AudioSynthWaveformModulated waveformMod2;   //xy=894.0190353393555,706.6667976379395
AudioSynthWaveformModulated waveformMod5;   //xy=895.0190353393555,637.6667976379395
AudioSynthWaveformModulated waveformMod1;   //xy=896.0190353393555,600.6667976379395
AudioSynthWaveformModulated waveformMod7;   //xy=895.0190353393555,857.6667976379395
AudioSynthWaveformModulated waveformMod3;   //xy=897.0190353393555,822.6667976379395
AudioMixer4              oscmixer2;      //xy=1060.0190353393555,719.6667976379395
AudioMixer4              oscmixer1;      //xy=1062.0190353393555,618.6667976379395
AudioMixer4              oscmixer3;      //xy=1065.0190353393555,838.6667976379395
AudioMixer4              oscmixer4;      //xy=1066.0190353393555,970.6667976379395
AudioEffectWaveFolder    wavefolder3;    //xy=1273.0190353393555,853.6667976379395
AudioEffectWaveFolder    wavefolder2;    //xy=1280.0190353393555,735.6667976379395
AudioSynthWaveformDc     wavefold_dc;    //xy=1285.0190353393555,554.6667976379395
AudioEffectWaveFolder    wavefolder1;    //xy=1292.0190353393555,621.6667976379395
AudioEffectWaveFolder    wavefolder4;    //xy=1291.0190353393555,973.6667976379395
AudioSynthWaveformDc     filter_dc;      //xy=1488.0190353393555,406.66679763793945
AudioEffectEnvelope      envelope7;      //xy=1525.0190353393555,818.6667976379395
AudioEffectEnvelope      envelope6;      //xy=1536.0190353393555,669.6667976379395
AudioEffectEnvelope      envelope8;      //xy=1539.0190353393555,954.6667976379395
AudioEffectEnvelope      envelope5;      //xy=1545.0190353393555,508.66679763793945
AudioMixer4              filter_mod_mixer3; //xy=1552.0190353393555,874.6667976379395
AudioMixer4              filter_mod_mixer2; //xy=1555.0190353393555,747.6667976379395
AudioMixer4              filter_mod_mixer1; //xy=1560.0190353393555,562.6667976379395
AudioMixer4              filter_mod_mixer4; //xy=1564.0190353393555,1012.6667976379395
AudioFilterStateVariable filter1;        //xy=1713.0190353393555,628.6667976379395
AudioFilterStateVariable filter3;        //xy=1714.0190353393555,834.6667976379395
AudioFilterStateVariable filter2;        //xy=1715.0190353393555,715.6667976379395
AudioFilterStateVariable filter4;        //xy=1721.0190353393555,961.6667976379395
AudioMixer4              filter_mixer2;  //xy=1890.0190353393555,714.6667976379395
AudioMixer4              filter_mixer1;  //xy=1891.0190353393555,636.6667976379395
AudioMixer4              filter_mixer3;  //xy=1891.0190353393555,834.6667976379395
AudioMixer4              filter_mixer4;  //xy=1892.0190353393555,965.6667976379395
AudioEffectEnvelope      envelope4;      //xy=2090.685779571533,966.000165939331
AudioEffectEnvelope      envelope3;      //xy=2098.685779571533,838.000165939331
AudioEffectEnvelope      envelope2;      //xy=2106.685779571533,716.000165939331
AudioEffectEnvelope      envelope1;      //xy=2113.685779571533,633.000165939331
AudioMixer4              voicemixer;     //xy=2319.0190353393555,719.6667976379395
AudioAmplifier           amp1;           //xy=2456.0190353393555,719.6667976379395
AudioEffectBitcrusher    bitcrusher1;    //xy=2467.0190353393555,758.6667976379395
AudioEffectWaveshaper    waveshape1;     //xy=2474.0190353393555,803.6667976379395
AudioMixer4              mixer4;         //xy=2640.0190353393555,614.6667976379395
AudioEffectChorus        chorus1;        //xy=2644.0190353393555,907.6667976379395
AudioAmplifier           reverbamp;      //xy=2648.0190353393555,516.6667976379395
AudioEffectFreeverbStereo freeverbs1;     //xy=2649.0190353393555,558.6667976379395
AudioAmplifier           chorusamp;      //xy=2654.0190353393555,862.6667976379395
AudioEffectFreeverbStereo freeverbs2;     //xy=2785.0190353393555,615.6667976379395
AudioMixer4              mixerL;         //xy=2897.0190353393555,689.6667976379395
AudioMixer4              mixerR;         //xy=2897.0190353393555,759.6667976379395
AudioOutputI2S           i2s1;           //xy=3249.0190353393555,710.6667976379395
AudioConnection          patchCord1(lfoosc1, 0, fmmixer, 0);
AudioConnection          patchCord2(lfoosc1, 0, pulsewidth_mixer, 1);
AudioConnection          patchCord3(lfoosc1, 0, filter_mod_mixer1, 1);
AudioConnection          patchCord4(lfoosc1, 0, filter_mod_mixer4, 1);
AudioConnection          patchCord5(lfoosc1, 0, filter_mod_mixer3, 1);
AudioConnection          patchCord6(lfoosc1, 0, filter_mod_mixer2, 1);
AudioConnection          patchCord7(fmmixer, 0, waveformMod1, 0);
AudioConnection          patchCord8(fmmixer, 0, waveformMod2, 0);
AudioConnection          patchCord9(fmmixer, 0, waveformMod3, 0);
AudioConnection          patchCord10(fmmixer, 0, waveformMod4, 0);
AudioConnection          patchCord11(fmmixer, 0, waveformMod8, 0);
AudioConnection          patchCord12(fmmixer, 0, waveformMod7, 0);
AudioConnection          patchCord13(fmmixer, 0, waveformMod5, 0);
AudioConnection          patchCord14(fmmixer, 0, waveformMod6, 0);
AudioConnection          patchCord15(pink1, 0, oscmixer1, 2);
AudioConnection          patchCord16(pink1, 0, oscmixer2, 2);
AudioConnection          patchCord17(pink1, 0, oscmixer3, 2);
AudioConnection          patchCord18(pink1, 0, oscmixer4, 2);
AudioConnection          patchCord19(pulsewidth_dc, 0, pulsewidth_mixer, 0);
AudioConnection          patchCord20(pulsewidth_mixer, 0, waveformMod1, 1);
AudioConnection          patchCord21(pulsewidth_mixer, 0, waveformMod5, 1);
AudioConnection          patchCord22(pulsewidth_mixer, 0, waveformMod2, 1);
AudioConnection          patchCord23(pulsewidth_mixer, 0, waveformMod6, 1);
AudioConnection          patchCord24(pulsewidth_mixer, 0, waveformMod3, 1);
AudioConnection          patchCord25(pulsewidth_mixer, 0, waveformMod7, 1);
AudioConnection          patchCord26(pulsewidth_mixer, 0, waveformMod4, 1);
AudioConnection          patchCord27(pulsewidth_mixer, 0, waveformMod8, 1);
AudioConnection          patchCord28(waveformMod4, 0, oscmixer4, 0);
AudioConnection          patchCord29(waveformMod8, 0, oscmixer4, 1);
AudioConnection          patchCord30(waveformMod6, 0, oscmixer2, 1);
AudioConnection          patchCord31(waveformMod2, 0, oscmixer2, 0);
AudioConnection          patchCord32(waveformMod5, 0, oscmixer1, 1);
AudioConnection          patchCord33(waveformMod1, 0, oscmixer1, 0);
AudioConnection          patchCord34(waveformMod7, 0, oscmixer3, 1);
AudioConnection          patchCord35(waveformMod3, 0, oscmixer3, 0);
AudioConnection          patchCord36(oscmixer2, 0, wavefolder2, 0);
AudioConnection          patchCord37(oscmixer1, 0, wavefolder1, 0);
AudioConnection          patchCord38(oscmixer3, 0, wavefolder3, 0);
AudioConnection          patchCord39(oscmixer4, 0, wavefolder4, 0);
AudioConnection          patchCord40(wavefolder3, 0, filter3, 0);
AudioConnection          patchCord41(wavefolder2, 0, filter2, 0);
AudioConnection          patchCord42(wavefold_dc, 0, wavefolder3, 1);
AudioConnection          patchCord43(wavefold_dc, 0, wavefolder1, 1);
AudioConnection          patchCord44(wavefold_dc, 0, wavefolder2, 1);
AudioConnection          patchCord45(wavefold_dc, 0, wavefolder4, 1);
AudioConnection          patchCord46(wavefolder1, 0, filter1, 0);
AudioConnection          patchCord47(wavefolder4, 0, filter4, 0);
AudioConnection          patchCord48(filter_dc, envelope5);
AudioConnection          patchCord49(filter_dc, envelope6);
AudioConnection          patchCord50(filter_dc, envelope7);
AudioConnection          patchCord51(filter_dc, envelope8);
AudioConnection          patchCord52(envelope7, 0, filter_mod_mixer3, 0);
AudioConnection          patchCord53(envelope6, 0, filter_mod_mixer2, 0);
AudioConnection          patchCord54(envelope8, 0, filter_mod_mixer4, 0);
AudioConnection          patchCord55(envelope5, 0, filter_mod_mixer1, 0);
AudioConnection          patchCord56(filter_mod_mixer3, 0, filter3, 1);
AudioConnection          patchCord57(filter_mod_mixer2, 0, filter2, 1);
AudioConnection          patchCord58(filter_mod_mixer1, 0, filter1, 1);
AudioConnection          patchCord59(filter_mod_mixer4, 0, filter4, 1);
AudioConnection          patchCord60(filter1, 0, filter_mixer1, 0);
AudioConnection          patchCord61(filter1, 1, filter_mixer1, 1);
AudioConnection          patchCord62(filter1, 2, filter_mixer1, 2);
AudioConnection          patchCord63(filter3, 0, filter_mixer3, 0);
AudioConnection          patchCord64(filter3, 1, filter_mixer3, 1);
AudioConnection          patchCord65(filter3, 2, filter_mixer3, 2);
AudioConnection          patchCord66(filter2, 0, filter_mixer2, 0);
AudioConnection          patchCord67(filter2, 1, filter_mixer2, 1);
AudioConnection          patchCord68(filter2, 2, filter_mixer2, 2);
AudioConnection          patchCord69(filter4, 0, filter_mixer4, 0);
AudioConnection          patchCord70(filter4, 1, filter_mixer4, 1);
AudioConnection          patchCord71(filter4, 2, filter_mixer4, 2);
AudioConnection          patchCord72(filter_mixer2, envelope2);
AudioConnection          patchCord73(filter_mixer1, envelope1);
AudioConnection          patchCord74(filter_mixer3, envelope3);
AudioConnection          patchCord75(filter_mixer4, envelope4);
AudioConnection          patchCord76(envelope4, 0, voicemixer, 3);
AudioConnection          patchCord77(envelope3, 0, voicemixer, 2);
AudioConnection          patchCord78(envelope2, 0, voicemixer, 1);
AudioConnection          patchCord79(envelope1, 0, voicemixer, 0);
AudioConnection          patchCord80(voicemixer, amp1);
AudioConnection          patchCord81(amp1, bitcrusher1);
AudioConnection          patchCord82(bitcrusher1, waveshape1);
AudioConnection          patchCord83(waveshape1, reverbamp);
AudioConnection          patchCord84(waveshape1, 0, mixerL, 0);
AudioConnection          patchCord85(waveshape1, 0, mixerR, 0);
AudioConnection          patchCord86(waveshape1, chorusamp);
AudioConnection          patchCord87(mixer4, freeverbs2);
AudioConnection          patchCord88(chorus1, 0, mixerR, 2);
AudioConnection          patchCord89(chorus1, 0, mixerL, 2);
AudioConnection          patchCord90(reverbamp, freeverbs1);
AudioConnection          patchCord91(freeverbs1, 0, mixer4, 1);
AudioConnection          patchCord92(freeverbs1, 1, mixer4, 0);
AudioConnection          patchCord93(chorusamp, chorus1);
AudioConnection          patchCord94(freeverbs2, 0, mixerL, 1);
AudioConnection          patchCord95(freeverbs2, 1, mixerR, 1);
AudioConnection          patchCord96(mixerL, 0, i2s1, 0);
AudioConnection          patchCord97(mixerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1215.0190353393555,468.66679763793945
// GUItool: end automatically generated code





/* 
Current abilities @ 1/4/21
-polyphony, not quite round-robin but close
-amplitude envelope
-filter envelope
-output waveshaping
-reverb
-velocity sensitivity
-chorus but that doesn't work
-oscillator modifications: dc offset, pulse width, wavefolder
-dual oscillators
-coarse detune
-LFO detune
-noise into oscillator mixer
-fine detune
-oscillator mix
-loading patch, parameter names (for now, just from an array)
- filter keytrack

TODO: 
- fm between operators? 
- patch saving?

- use isActive() vs. freqtable[i] == -1 to detect if voices are done playing.
*/

#include "MIDIUSB.h"
#include <math.h> //<cmath> in case of c++
#include "patch.h"
// util //
const int ledPin = 13;
int midi_counter = 0;
char buff[100];
void poly_debug(char * buff, int voicenum, int nvoices, int * freqtable){
  sprintf(buff, "voicenum: %2d, [ ", voicenum);
  Serial.print(buff);
  for (int i=0; i<nvoices; i++){
    if (freqtable[i] == -1){
      Serial.print("_");
    }
    else{
      Serial.print("x");
    }
    Serial.print(" ");
  }
  Serial.println("]");
}


// helper functions
void midi_monitor(midiEventPacket_t rx) {
    Serial.print("Received: ");
    Serial.print(rx.header, HEX);
    Serial.print("-");
    Serial.print(rx.byte1, HEX);
    Serial.print("-");
    Serial.print(rx.byte2, HEX);
    Serial.print("-");
    Serial.println(rx.byte3, HEX);
}


// midi & synthesis
float noteToFreq(int note) {
  float a = 440; //frequency of A (common value is 440Hz)
  return (a / 32) * pow(2, ((note - 9) / 12.0));
}

float noteToFreq(float note){
  return pow(2, (note-69)/12)*440.0;
}

float noteToFreqRatio(float note){
  return pow(2, note/12.0);
}

float freqToNote(float freq){
  return 12*log(freq/440.0)/log(2) + 69;
}

const float e=exp(1);

const float velocityToAmplitude[127] = {
0.01778,0.01966,0.02164,0.02371,0.02588,0.02814,0.03049,0.03294,0.03549,0.03812,
0.04086,0.04369,0.04661,0.04963,0.05274,0.05594,0.05924,0.06264,0.06613,0.06972,
0.07340,0.07717,0.08104,0.08500,0.08906,0.09321,0.09746,0.10180,0.10624,0.11077,
0.11539,0.12011,0.12493,0.12984,0.13484,0.13994,0.14513,0.15042,0.15581,0.16128,
0.16685,0.17252,0.17828,0.18414,0.19009,0.19613,0.20227,0.20851,0.21484,0.22126,
0.22778,0.23439,0.24110,0.24790,0.25480,0.26179,0.26887,0.27605,0.28333,0.29070,
0.29816,0.30572,0.31337,0.32112,0.32896,0.33690,0.34493,0.35306,0.36128,0.36960,
0.37801,0.38651,0.39511,0.40381,0.41260,0.42148,0.43046,0.43953,0.44870,0.45796,
0.46732,0.47677,0.48631,0.49595,0.50569,0.51552,0.52544,0.53546,0.54557,0.55578,
0.56609,0.57648,0.58697,0.59756,0.60824,0.61902,0.62989,0.64085,0.65191,0.66307,
0.67432,0.68566,0.69710,0.70863,0.72026,0.73198,0.74380,0.75571,0.76771,0.77981,
0.79201,0.80430,0.81668,0.82916,0.84174,0.85440,0.86717,0.88003,0.89298,0.90602,
0.91917,0.93240,0.94573,0.95916,0.97268,0.98629,1.00000
};

float cc_to_millis(byte cc){
  return pow(2.71828, 0.07*(float)cc);
}

float cc_to_01(byte cc){
  return (float)cc*(1/127.0);
}

float map_cc_to_range_linear(byte cc, float low, float high){
  float alpha = cc_to_01(cc);
  return alpha*high + (1-alpha)*low;
}

float map_cc_sigmoid(byte cc, float low, float high){
   float val = map_cc_to_range_linear(cc, 0, 1);
   return (high-low)*((1-1/(1+val/3)) + low);
}

float exp_map(float x){ // 0-1 -> 0, 1, exponential
  return (1/(e-1)*(exp(x/127)-1));
}

float pow_map(float x, int n = 3){ // 0-1 -> 0, 1, polynomial
  return pow(x, n);
}

float tri_map(float x, int i){ // 0 - pi -> 0-1
  float out;
  if (i == 0){
    out = max(cos(x), 0);
  }
  else if (i == 1){
    out = max(sin(x), 0);
  }
  else if (i == 2){
    out = max(-sin(x+PI/2), 0);
  }
  else{
    out = 0;
  }
  return out;
}

int WAVEFORM_TYPE[] = {WAVEFORM_BANDLIMIT_SAWTOOTH, WAVEFORM_BANDLIMIT_PULSE, WAVEFORM_TRIANGLE_VARIABLE, WAVEFORM_SINE};


// Global params
const int n_osc = 2;
float fine_detune = 0;
int coarse_detune = 0;
float detune_ratios[25] = {1/2.0, 1/1.888, 1/1.782, 1/1.682, 1/1.587, 1/1.498, 1/1.414, 1/1.334, 1/1.260, 1/1.189, 1/1.122,  1/1.059,
                            1.0, 1.059, 1.122, 1.189, 1.260, 1.334, 1.414, 1.498, 1.587, 1.682, 1.782, 1.888, 2};
float SEMITONE_RATIO = (pow(2, 1.0/12.0));
float fine_detune_map(byte cc){// semitones
  return  (SEMITONE_RATIO-1)*pow(map_cc_to_range_linear(cc, -1, 1), 3);
}

// filter //
float fc_freq = noteToFreq(127); // filter cutoff frequency
float keytrack_amt = 0; // number from 0 to 1 setting how much the filter tracks the note.
int keytrack_pivot = 60;
float FILTER_MAX_FREQ = 10000.0;

// LFO //
float mults[8] = {1, 2, 4, 8, 16, 32, 64, 128};
float LFO_MULT = 0.01; // allows really low frequencies
int freq_multiplier = 1;

// FX //
const int waveshape_len = 129;
float waveshape_arr[waveshape_len];

const int CHORUS_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES); // Number of samples in each delay line
short delayline[CHORUS_DELAY_LENGTH]; // Allocate the delay line
int n_chorus = 2;

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
      this->m_osc1->begin(0.4, 220, WAVEFORM_SAWTOOTH);
      this->m_osc2->begin(0.4, 220, WAVEFORM_SAWTOOTH);
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

// polyphony //
Voice v1(&waveformMod1, &waveformMod5, &envelope1, &envelope5, &filter1, &oscmixer1, &filter_mod_mixer1, &filter_mixer1);
Voice v2(&waveformMod2, &waveformMod6, &envelope2, &envelope6, &filter2, &oscmixer2, &filter_mod_mixer2, &filter_mixer2);
Voice v3(&waveformMod3, &waveformMod7, &envelope3, &envelope7, &filter3, &oscmixer3, &filter_mod_mixer3, &filter_mixer3);
Voice v4(&waveformMod4, &waveformMod8, &envelope4, &envelope8, &filter4, &oscmixer4, &filter_mod_mixer4, &filter_mixer4);

const int nvoices = 4;
int voicenum = 0;
Voice voices[nvoices] = {v1, v2, v3, v4};
int freqtable[nvoices] = {-1, -1, -1, -1}; // holds frequencies

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

void modifyPatch(int cc, byte val){
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

void setup() {
  // put your setup code here, to run once:
  AudioMemory(400);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  amp1.gain(1);

  for (int i = 0; i<128; i++){
    sprintf(buff, "%f, %f", noteToFreq((float)i), noteToFreq(i));
    Serial.println(buff);
  }

  //voices init
  for(int i=0; i<nvoices; i++){
      voicemixer.gain(i, 0.25);
  }

  // load init patch
  patch::initSDCard();


  for (int i =0; i<patch::nparams; i++){
    sprintf(buff, "i: %d, param: %s val: %d", i, patch::parameter_names[i], patch::initpatch[i]);
    Serial.println(buff);
    modifyPatch(i, patch::initpatch[i]);
  }

  patch::printPatch(patch::initpatch, buff);
  
  fmmixer.gain(0, 0.0);
  pulsewidth_mixer.gain(1, 0);
  pink1.amplitude(1.0);


  // audio rate modulation // 
  wavefold_dc.amplitude(1.0); // wavefold
  filter_dc.amplitude(1.0); // filter env amt
  // filter_mod_mixer.gain(1, 0.0); // filter LFO1 mod

  // init waveshaper
  float shape_inc = 2*PI/waveshape_len;
  for(int i = 0; i<waveshape_len; i++){
    waveshape_arr[i] = tanh(0.5*(-PI+i*shape_inc));
  }
  waveshape1.shape(waveshape_arr, waveshape_len);

  // init bitcrusher
  bitcrusher1.bits(16);
  bitcrusher1.sampleRate(44100);

  // init chorus
  chorusamp.gain(1.0);
  chorus1.begin(delayline, CHORUS_DELAY_LENGTH, n_chorus);
  mixerL.gain(3, 0.2);
  mixerR.gain(3, 0.2);

  // init reverb
  reverbamp.gain(0.0);
  freeverbs1.roomsize(1);
  freeverbs1.damping(0.25);
  freeverbs2.roomsize(0.25);
  freeverbs2.damping(0.5);
  mixerL.gain(2, 0.2);
  mixerR.gain(2, 0.2);

  // LFO1
  lfoosc1.amplitude(0);
  lfoosc1.frequency(1);
  lfoosc1.phase(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      midi_monitor(rx);
      digitalWrite(ledPin, HIGH);  // set the LED on
      midi_counter = 0;
      
      // Synth note on
      if (rx.header == 9){
        float note_freq = noteToFreq((int)rx.byte2);
        for(int i = 0; i<=nvoices; i++){
          if(i == nvoices){  // out of voices, steal
            // voices[voicenum].noteOff();
            voice_noteOn(voicenum, note_freq, (int)rx.byte2, (int)rx.byte3);
            voicenum++;
            voicenum = voicenum % nvoices;
            break;
          }
          else if (freqtable[i] == -1){  // otherwise, look for unused voices
            voice_noteOn(i, note_freq, (int)rx.byte2, (int)rx.byte3);
            break;
          }
        }
        poly_debug(buff, voicenum, nvoices, freqtable);
        continue;
      }

      // synth note off
      else if (rx.header == 8){
        for(int i=0; i<nvoices; i++){
          if (freqtable[i] == (int)rx.byte2){ // if freq matches, note it off
            voices[i].noteOff();
            freqtable[i] = -1;
            break;
          }
        }
        continue;
      }

      else if (rx.header == 0x0B){ // control change
        modifyPatch((int)rx.byte2, rx.byte3);
      }
    }
      
    midi_counter++;
    if (midi_counter > 1000){
      digitalWrite(ledPin, LOW);   // set the LED off
      midi_counter = 0;
    }    
  } while (rx.header != 0);
}
