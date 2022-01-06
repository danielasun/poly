#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   lfoosc1;          //xy=148.00568771362305,256.0056343078613
AudioMixer4              fmmixer;         //xy=149.00570678710938,328.00563621520996
AudioSynthWaveformModulated waveformMod4;   //xy=341.0056686401367,596.0056018829346
AudioSynthWaveformModulated waveformMod8;   //xy=343.0057067871094,632.0056743621826
AudioSynthWaveformModulated waveformMod6;   //xy=344.00569915771484,390.0056667327881
AudioSynthWaveformModulated waveformMod2;   //xy=346.0056915283203,353.005651473999
AudioSynthWaveformModulated waveformMod5;   //xy=347.00569915771484,284.00567054748535
AudioSynthWaveformModulated waveformMod1;   //xy=348.00566482543945,247.0056438446045
AudioSynthWaveformModulated waveformMod7;   //xy=347.0056915283203,504.0056552886963
AudioSynthWaveformModulated waveformMod3;   //xy=349.0056610107422,469.0056552886963
AudioMixer4              oscmixer2;         //xy=512.9147567749023,366.005672454834
AudioMixer4              oscmixer1;         //xy=514.6420364379883,265.0056495666504
AudioMixer4              oscmixer3;         //xy=517.9148216247559,485.0056571960449
AudioMixer4              oscmixer4;         //xy=518.9147796630859,617.0056762695312
AudioEffectWaveFolder    wavefolder3; //xy=785.5618591308594,481.117374420166
AudioEffectWaveFolder    wavefolder2; //xy=792.5618438720703,363.8951721191406
AudioSynthWaveformDc     wavefold_dc;            //xy=798.4507293701172,193.78402709960938
AudioEffectWaveFolder    wavefolder1;    //xy=804.5238342285156,249.6824836730957
AudioEffectWaveFolder    wavefolder4; //xy=803.4507255554199,601.6729278564453
AudioSynthWaveformDc     dc4;            //xy=890.9999580383301,663.9999885559082
AudioSynthWaveformDc     dc3;            //xy=893.9999618530273,526.9999713897705
AudioSynthWaveformDc     dc1;            //xy=895.7777633666992,305.66664028167725
AudioSynthWaveformDc     dc2;            //xy=899.9999618530273,422.99998474121094
AudioEffectEnvelope      envelope8;      //xy=1028.8571472167969,662.5714282989502
AudioEffectEnvelope      envelope5;      //xy=1036.8571472167969,306.5714282989502
AudioEffectEnvelope      envelope7;      //xy=1039.8571472167969,528.5714282989502
AudioEffectEnvelope      envelope6;      //xy=1041.8571472167969,420.5714282989502
AudioFilterStateVariable filter1;        //xy=1164.8571472167969,277.5714282989502
AudioFilterStateVariable filter3;        //xy=1166.8571472167969,481.5714282989502
AudioFilterStateVariable filter2;        //xy=1167.8571472167969,362.5714282989502
AudioFilterStateVariable filter4;        //xy=1173.8571472167969,608.5714282989502
AudioEffectEnvelope      envelope1;      //xy=1304.8571472167969,272.5714282989502
AudioEffectEnvelope      envelope3;      //xy=1305.8571472167969,475.5714282989502
AudioEffectEnvelope      envelope2;      //xy=1306.8571472167969,354.5714282989502
AudioEffectEnvelope      envelope4;      //xy=1314.8571472167969,600.5714282989502
AudioMixer4              voicemixer;         //xy=1505.8571472167969,358.5714282989502
AudioAmplifier           amp1;           //xy=1642.8571472167969,358.5714282989502
AudioEffectBitcrusher    bitcrusher1;    //xy=1653.8571472167969,397.5714282989502
AudioEffectWaveshaper    waveshape1;     //xy=1660.8571472167969,442.5714282989502
AudioMixer4              mixer4;         //xy=1826.9999694824219,253.99998950958252
AudioEffectChorus        chorus1;        //xy=1830.460075378418,546.9146976470947
AudioAmplifier           reverbamp;      //xy=1834.9999694824219,155.99998950958252
AudioEffectFreeverbStereo freeverbs1;     //xy=1835.9999694824219,197.99998950958252
AudioAmplifier           chorusamp;           //xy=1840.4601211547852,501.9147663116455
AudioEffectFreeverbStereo freeverbs2;     //xy=1971.9999694824219,254.99998950958252
AudioMixer4              mixerL;         //xy=2083.9999771118164,328.99999618530273
AudioMixer4              mixerR;         //xy=2083.9999771118164,398.99999618530273
AudioOutputI2S           i2s1;           //xy=2435.000015258789,349.9999713897705
AudioConnection          patchCord1(lfoosc1, 0, fmmixer, 0);
AudioConnection          patchCord2(fmmixer, 0, waveformMod1, 0);
AudioConnection          patchCord3(fmmixer, 0, waveformMod2, 0);
AudioConnection          patchCord4(fmmixer, 0, waveformMod3, 0);
AudioConnection          patchCord5(fmmixer, 0, waveformMod4, 0);
AudioConnection          patchCord6(waveformMod4, 0, oscmixer4, 0);
AudioConnection          patchCord7(waveformMod8, 0, oscmixer4, 1);
AudioConnection          patchCord8(waveformMod6, 0, oscmixer2, 1);
AudioConnection          patchCord9(waveformMod2, 0, oscmixer2, 0);
AudioConnection          patchCord10(waveformMod5, 0, oscmixer1, 1);
AudioConnection          patchCord11(waveformMod1, 0, oscmixer1, 0);
AudioConnection          patchCord12(waveformMod7, 0, oscmixer3, 1);
AudioConnection          patchCord13(waveformMod3, 0, oscmixer3, 0);
AudioConnection          patchCord14(oscmixer2, 0, wavefolder2, 0);
AudioConnection          patchCord15(oscmixer1, 0, wavefolder1, 0);
AudioConnection          patchCord16(oscmixer3, 0, wavefolder3, 0);
AudioConnection          patchCord17(oscmixer4, 0, wavefolder4, 0);
AudioConnection          patchCord18(wavefolder3, 0, filter3, 0);
AudioConnection          patchCord19(wavefolder2, 0, filter2, 0);
AudioConnection          patchCord20(wavefold_dc, 0, wavefolder3, 1);
AudioConnection          patchCord21(wavefold_dc, 0, wavefolder1, 1);
AudioConnection          patchCord22(wavefold_dc, 0, wavefolder2, 1);
AudioConnection          patchCord23(wavefold_dc, 0, wavefolder4, 1);
AudioConnection          patchCord24(wavefolder1, 0, filter1, 0);
AudioConnection          patchCord25(wavefolder4, 0, filter4, 0);
AudioConnection          patchCord26(dc4, envelope8);
AudioConnection          patchCord27(dc3, envelope7);
AudioConnection          patchCord28(dc1, envelope5);
AudioConnection          patchCord29(dc2, envelope6);
AudioConnection          patchCord30(envelope8, 0, filter4, 1);
AudioConnection          patchCord31(envelope5, 0, filter1, 1);
AudioConnection          patchCord32(envelope7, 0, filter3, 1);
AudioConnection          patchCord33(envelope6, 0, filter2, 1);
AudioConnection          patchCord34(filter1, 0, envelope1, 0);
AudioConnection          patchCord35(filter3, 0, envelope3, 0);
AudioConnection          patchCord36(filter2, 0, envelope2, 0);
AudioConnection          patchCord37(filter4, 0, envelope4, 0);
AudioConnection          patchCord38(envelope1, 0, voicemixer, 0);
AudioConnection          patchCord39(envelope3, 0, voicemixer, 2);
AudioConnection          patchCord40(envelope2, 0, voicemixer, 1);
AudioConnection          patchCord41(envelope4, 0, voicemixer, 3);
AudioConnection          patchCord42(voicemixer, amp1);
AudioConnection          patchCord43(amp1, bitcrusher1);
AudioConnection          patchCord44(bitcrusher1, waveshape1);
AudioConnection          patchCord45(waveshape1, reverbamp);
AudioConnection          patchCord46(waveshape1, 0, mixerL, 0);
AudioConnection          patchCord47(waveshape1, 0, mixerR, 0);
AudioConnection          patchCord48(waveshape1, chorusamp);
AudioConnection          patchCord49(mixer4, freeverbs2);
AudioConnection          patchCord50(chorus1, 0, mixerR, 2);
AudioConnection          patchCord51(chorus1, 0, mixerL, 2);
AudioConnection          patchCord52(reverbamp, freeverbs1);
AudioConnection          patchCord53(freeverbs1, 0, mixer4, 1);
AudioConnection          patchCord54(freeverbs1, 1, mixer4, 0);
AudioConnection          patchCord55(chorusamp, chorus1);
AudioConnection          patchCord56(freeverbs2, 0, mixerL, 1);
AudioConnection          patchCord57(freeverbs2, 1, mixerR, 1);
AudioConnection          patchCord58(mixerL, 0, i2s1, 0);
AudioConnection          patchCord59(mixerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=667.9999771118164,115.99999618530273
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

TODO: dual oscillators, detune
*/

#include "MIDIUSB.h"
#include <math.h> //<cmath> in case of c++

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

float pow_map(float x, int n = 3){ // 0-127 -> 0, 1, exponential
  return pow(x, n);
}

int WAVEFORM_TYPE[] = {WAVEFORM_BANDLIMIT_SAWTOOTH, WAVEFORM_BANDLIMIT_PULSE, WAVEFORM_TRIANGLE_VARIABLE, WAVEFORM_SINE};


// Voice class
const int n_osc = 2;
float fine_detune = 0;
int coarse_detune = 0;
float detune_ratios[25] = {1/2.0, 1/1.888, 1/1.782, 1/1.682, 1/1.587, 1/1.498, 1/1.414, 1/1.334, 1/1.260, 1/1.189, 1/1.122,  1/1.059,
                            1.0, 1.059, 1.122, 1.189, 1.260, 1.334, 1.414, 1.498, 1.587, 1.682, 1.782, 1.888, 2};

class Voice {
  public:
    Voice(AudioSynthWaveformModulated* wave1,
          AudioSynthWaveformModulated* wave2,  
          AudioEffectEnvelope* env, 
          AudioEffectEnvelope* fenv, 
          AudioSynthWaveformDc* fc,
          AudioFilterStateVariable* filter) {
      
      m_osc1 = wave1;
      m_osc2 = wave2;
      // m_osc[0] = m_osc1;
      // m_osc[1] = m_osc1;     
      m_env = env;
      m_fenv = fenv;
      m_fc = fc;
      m_filter = filter;
    }

    void set_osc_frequency(float note_freq, int coarse_detune){
      this->m_osc1->frequency(note_freq);
      this->m_osc2->frequency(note_freq*detune_ratios[coarse_detune]);
    }

    void noteOn(float note_freq){
      this->set_osc_frequency(note_freq, coarse_detune);
      // for(int i=0; i<n_osc; i++){
      //   this->m_osc[i]->frequency(note_freq);
      // }
      this->m_env->noteOn();
      this->m_fenv->noteOn();
    }

    void noteOff(){
      this->m_env->noteOff();
    }



    AudioSynthWaveformModulated* m_osc1;
    AudioSynthWaveformModulated* m_osc2;
    // AudioSynthWaveformModulated* m_osc[n_osc];
    AudioEffectEnvelope* m_env;
    AudioEffectEnvelope* m_fenv;
    AudioSynthWaveformDc* m_fc;
    AudioFilterStateVariable* m_filter;
    
};



// polyphony //
Voice v1(&waveformMod1, &waveformMod5, &envelope1, &envelope5, &dc1, &filter1);
Voice v2(&waveformMod2, &waveformMod6, &envelope2, &envelope6, &dc2, &filter2);
Voice v3(&waveformMod3, &waveformMod7, &envelope3, &envelope7, &dc3, &filter3);
Voice v4(&waveformMod4, &waveformMod8, &envelope4, &envelope8, &dc4, &filter4);

const int nvoices = 4;
int voicenum = 0;
Voice voices[nvoices] = {v1, v2, v3, v4};
int freqtable[nvoices] = {-1, -1, -1, -1}; // holds frequencies


void voice_noteOn(int voicenum, float note_freq, int note, int velocity){
  voices[voicenum].noteOn(note_freq);
  freqtable[voicenum] = note;
  voices[voicenum].m_osc1->amplitude(velocityToAmplitude[velocity]);
  voices[voicenum].m_osc2->amplitude(velocityToAmplitude[velocity]);
  // for (int ii=0; ii<n_osc; ii++){
  //   voices[voicenum].m_osc[ii]->amplitude(velocityToAmplitude[velocity]);
  // }
}

// LFO //
float mults[8] = {1, 2, 4, 8, 16, 32, 64, 128};
float MIN_LFO_FREQ = 0.01;
int freq_multiplier = 1;


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

// FX //
const int waveshape_len = 129;
float waveshape_arr[waveshape_len];

const int CHORUS_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES); // Number of samples in each delay line
short delayline[CHORUS_DELAY_LENGTH]; // Allocate the delay line
int n_chorus = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.print('hi');
  AudioMemory(200);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  amp1.gain(1);

  //voices init
  for(int i=0; i<nvoices; i++){
      voicemixer.gain(i, 0.25);
  }
  for (int i=0; i<nvoices; i++){
    voices[i].m_env->attack(5);
    voices[i].m_env->decay(25);
    voices[i].m_env->sustain(0.25);
    voices[i].m_env->release(1000);
    voices[i].m_fenv->attack(50);
    voices[i].m_fenv->decay(1000);
    voices[i].m_fenv->sustain(0);
    voices[i].m_fenv->release(250);
    voices[i].m_fc->amplitude(1);
    voices[i].m_filter->frequency(400);
    voices[i].m_filter->octaveControl(2);
    voices[i].m_osc1->begin(0.4, 220, WAVEFORM_SAWTOOTH);
    voices[i].m_osc2->begin(0.4, 220, WAVEFORM_SAWTOOTH);
    // for(int ii=0; ii<n_osc; i++){
    //   voices[i].m_osc[i]->begin(0.4, 220, WAVEFORM_SAWTOOTH); 
    // }

  }
  fmmixer.gain(0, 0.1);

  // init osc wavefolder
  wavefold_dc.amplitude(1.0);

  // init waveshaper
  float shape_inc = 2*PI/waveshape_len;
  for(int i = 0; i<waveshape_len; i++){
    waveshape_arr[i] = tanh(0.5*(-PI+i*shape_inc));
    Serial.println(waveshape_arr[i]);
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
            voices[voicenum].noteOff();
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
        if ((int)rx.byte2 == 7){ // volume
          AudioNoInterrupts();
          amp1.gain(map_cc_to_range_linear(rx.byte3, 0.0, 1.0));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 8){ // pan
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            // constant power panning (https://www.cs.cmu.edu/~music/icm-online/readings/panlaws/)
            float theta = map_cc_to_range_linear(rx.byte3, 0.0, PI/2);
            mixerL.gain(0, cos(theta));
            mixerR.gain(0, sin(theta));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 20){ // filter env atk
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_fenv->attack(cc_to_millis(rx.byte3));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 21){ // filter env decay
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_fenv->decay(cc_to_millis(rx.byte3));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 22){ // filter env sustain
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_fenv->sustain(map_cc_to_range_linear(rx.byte3, 0.0, 1.0));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 23){ // filter env release
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_fenv->release(cc_to_millis(rx.byte3));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 32){ // dc offset
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            float offset_amt = map_cc_to_range_linear(rx.byte3, 0, 1.0);
            voices[i].m_osc1->offset(offset_amt); 
            voices[i].m_osc2->offset(offset_amt); 
            // for (int ii=0; ii<n_osc; ii++){
            //   voices[i].m_osc[ii]->offset(offset_amt); 
            // }
          }
          AudioInterrupts();
        }
        
        if ((int)rx.byte2 == 34){ // wavefolder dc
          AudioNoInterrupts();
          wavefold_dc.amplitude(map_cc_to_range_linear(rx.byte3, 0.1, 1.0));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 35){ // coarse detune
          AudioNoInterrupts();
          coarse_detune = (int)map_cc_to_range_linear(rx.byte3, 0, 25);
          for (int i=0; i<nvoices; i++){
            voices[i].set_osc_frequency(noteToFreq(freqtable[i]), coarse_detune);
          }
          AudioInterrupts();
        }

        if ((int)rx.byte2 == 48){ // LFO1 amplitude
          AudioNoInterrupts();
          lfoosc1.amplitude(
            pow_map(map_cc_to_range_linear(rx.byte3, 0.1, 1.0), 3));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 49){ // LFO1 frequency
          AudioNoInterrupts();
          lfoosc1.frequency(MIN_LFO_FREQ*freq_multiplier*noteToFreq(map_cc_to_range_linear(rx.byte3, 0.0, 100)));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 50){ // LFO1 frequency
          AudioNoInterrupts();
          freq_multiplier = mults[(int)map_cc_to_range_linear(rx.byte3, 0, 7)];
          lfoosc1.frequency(MIN_LFO_FREQ*freq_multiplier*noteToFreq(map_cc_to_range_linear(rx.byte3, 0.0, 100)));
          AudioInterrupts();
        }
        
        if ((int)rx.byte2 == 70){ // waveform
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            int wave_t = (int)map_cc_to_range_linear(rx.byte3, 0.0, 3.99);
            voices[i].m_osc1->begin(WAVEFORM_TYPE[wave_t]);
            voices[i].m_osc2->begin(WAVEFORM_TYPE[wave_t]);
            // for (int ii=0; ii<n_osc; ii++){
            //   voices[i].m_osc[ii]->begin(
            //     WAVEFORM_TYPE[wave_t]);
            // }
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 71){ // filter resonance
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_filter->resonance(map_cc_to_range_linear(rx.byte3, 0.707, 5.0));
          }
          AudioInterrupts();
        }
        
        if ((int)rx.byte2 == 72){ // sound release
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_env->release(cc_to_millis(rx.byte3));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 73){ // sound attack
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_env->attack(cc_to_millis(rx.byte3));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 74){ // filter cutoff
          float note_freq = noteToFreq(map_cc_to_range_linear(rx.byte3, 0, 113));
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_filter->frequency(note_freq);
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 75){ // sustain
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_env->sustain(map_cc_to_range_linear(rx.byte3, 0.0, 1.0));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 76){ // fenv amt
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_fc->amplitude(map_cc_to_range_linear(rx.byte3, -1.0, 3.0), 1);
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 80){ // sound release
          AudioNoInterrupts();
          for(int i=0; i < nvoices; i++){
            voices[i].m_env->decay(cc_to_millis(rx.byte3));
          }
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 85){ // Reverb room size
          AudioNoInterrupts();
            freeverbs1.roomsize(map_cc_to_range_linear(rx.byte3, 0.1, 1));
            freeverbs2.roomsize(map_cc_to_range_linear(rx.byte3, 0.1, 0.25));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 86){ // Reverb damping
          AudioNoInterrupts();
            freeverbs1.damping(map_cc_to_range_linear(rx.byte3, 0.0, 1));
            freeverbs2.damping(map_cc_to_range_linear(rx.byte3, 0.0, 0.5));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 87){ // Bit depth
          AudioNoInterrupts();
          bitcrusher1.bits((int)map_cc_to_range_linear(rx.byte3, 0.0, 16.0));
          AudioInterrupts();
        }

        if ((int)rx.byte2 == 88){ // sampling rate
          AudioNoInterrupts();
          float sr = 4*noteToFreq(map_cc_to_range_linear(rx.byte3, 0, 127));
          bitcrusher1.sampleRate((int)sr);
          AudioInterrupts();
        }
        
        if ((int)rx.byte2 == 91){ // Reverb send 
          AudioNoInterrupts();
          reverbamp.gain(map_cc_to_range_linear(rx.byte3, 0, 0.5));
          AudioInterrupts();
        }
        if ((int)rx.byte2 == 93){ // chorus amount
          AudioNoInterrupts();
          mixerL.gain(3,map_cc_to_range_linear(rx.byte3, 0, 1.0));
          mixerR.gain(3,map_cc_to_range_linear(rx.byte3, 0, 1.0));
          AudioInterrupts();
        }

      }
    }
      
    midi_counter++;
    if (midi_counter > 1000){
      digitalWrite(ledPin, LOW);   // set the LED off
      midi_counter = 0;
    }    
  } while (rx.header != 0);

}
