#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioMixer4              fmmixerA1;         //xy=585.0071144104004,351.7116451263428
AudioMixer4              fmmixerB1;         //xy=585.0071258544922,447.96163177490234
AudioMixer4              fmmixerC1;         //xy=588.7571258544922,544.2116546630859
AudioMixer4              fmmixerD1;         //xy=590.0071258544922,632.9616432189941
AudioSynthWaveformSineModulated oscD1;       //xy=745.0070571899414,611.711597442627
AudioEffectEnvelope      envC1; //xy=748.7570877075195,554.2117385864258
AudioEffectEnvelope      envD1; //xy=748.7570877075195,650.461597442627
AudioSynthWaveformSineModulated oscC1;       //xy=750.0070571899414,517.9617710113525
AudioSynthWaveformSineModulated oscA1;       //xy=752.5070571899414,336.257116317749
AudioSynthWaveformSineModulated oscB1;       //xy=753.7570571899414,429.21163177490234
AudioEffectEnvelope      envA1;      //xy=755.0071449279785,369.21166038513184
AudioEffectEnvelope      envB1;      //xy=756.2571411132812,466.71163177490234
AudioMixer4              oscmixer1;         //xy=938.2571716308594,470.46158599853516
AudioOutputI2S           i2s1;           //xy=1326.5057640075684,469.4999599456787
AudioConnection          patchCord1(fmmixerA1, oscA1);
AudioConnection          patchCord2(fmmixerB1, oscB1);
AudioConnection          patchCord3(fmmixerC1, oscC1);
AudioConnection          patchCord4(fmmixerD1, oscD1);
AudioConnection          patchCord5(oscD1, envD1);
AudioConnection          patchCord6(envC1, 0, fmmixerC1, 2);
AudioConnection          patchCord7(envC1, 0, fmmixerB1, 2);
AudioConnection          patchCord8(envC1, 0, fmmixerA1, 2);
AudioConnection          patchCord9(envC1, 0, fmmixerD1, 2);
AudioConnection          patchCord10(envC1, 0, oscmixer1, 2);
AudioConnection          patchCord11(envD1, 0, fmmixerD1, 3);
AudioConnection          patchCord12(envD1, 0, fmmixerB1, 3);
AudioConnection          patchCord13(envD1, 0, fmmixerA1, 3);
AudioConnection          patchCord14(envD1, 0, fmmixerC1, 3);
AudioConnection          patchCord15(envD1, 0, oscmixer1, 3);
AudioConnection          patchCord16(oscC1, envC1);
AudioConnection          patchCord17(oscA1, envA1);
AudioConnection          patchCord18(oscB1, envB1);
AudioConnection          patchCord19(envA1, 0, fmmixerA1, 0);
AudioConnection          patchCord20(envA1, 0, fmmixerB1, 0);
AudioConnection          patchCord21(envA1, 0, fmmixerC1, 0);
AudioConnection          patchCord22(envA1, 0, fmmixerD1, 0);
AudioConnection          patchCord23(envA1, 0, oscmixer1, 0);
AudioConnection          patchCord24(envB1, 0, fmmixerB1, 1);
AudioConnection          patchCord25(envB1, 0, fmmixerA1, 1);
AudioConnection          patchCord26(envB1, 0, fmmixerC1, 1);
AudioConnection          patchCord27(envB1, 0, fmmixerD1, 1);
AudioConnection          patchCord28(envB1, 0, oscmixer1, 1);
AudioConnection          patchCord29(oscmixer1, 0, i2s1, 0);
AudioConnection          patchCord30(oscmixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=921.0056915283203,239.99999237060547
// GUItool: end automatically generated code

#include "MIDIUSB.h"
#include <math.h> //<cmath> in case of c++
#include "patch.h"
#include "synthesis.h"

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

// patchdata //
int patch_i = 0;
char patchname[] = "init_patch";

//// filter //
//float fc_freq = noteToFreq(127); // filter cutoff frequency
//float keytrack_amt = 0; // number from 0 to 1 setting how much the filter tracks the note.
//int keytrack_pivot = 60;
//float FILTER_MAX_FREQ = 10000.0;
//
//// LFO //
//float mults[8] = {1, 2, 4, 8, 16, 32, 64, 128};
//float LFO_MULT = 0.01; // allows really low frequencies
//int freq_multiplier = 1;
//
//// FX //
//const int waveshape_len = 129;
//float waveshape_arr[waveshape_len];
//
//const int CHORUS_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES); // Number of samples in each delay line
//short delayline[CHORUS_DELAY_LENGTH]; // Allocate the delay line
//int n_chorus = 2;

//// polyphony //
//Voice v1(&waveformMod1, &waveformMod5, &envelope1, &envelope5, &filter1, &oscmixer1, &filter_mod_mixer1, &filter_mixer1);
//Voice v2(&waveformMod2, &waveformMod6, &envelope2, &envelope6, &filter2, &oscmixer2, &filter_mod_mixer2, &filter_mixer2);
//Voice v3(&waveformMod3, &waveformMod7, &envelope3, &envelope7, &filter3, &oscmixer3, &filter_mod_mixer3, &filter_mixer3);
//Voice v4(&waveformMod4, &waveformMod8, &envelope4, &envelope8, &filter4, &oscmixer4, &filter_mod_mixer4, &filter_mixer4);

const int nosc = 4;
const int nalgo = 8;
int algorithm = 3;
AudioSynthWaveformSineModulated * osc[nosc] = {&oscA1, &oscB1, &oscC1, &oscD1};
AudioEffectEnvelope * osc_env[nosc] = {&envA1, &envB1, &envC1, &envD1};
AudioMixer4 * fmmixer[nosc] = {&fmmixerA1, &fmmixerB1, &fmmixerC1, &fmmixerD1};
int feedback_osc[nalgo] = {0, 0, 0, 2, 0, 0, 3};
float osc_ratios[nosc] = {1., 1, 2, 2};

void noteOn(float freq){
  for(int i=0; i<nosc; i++){
      osc[i]->frequency(freq*osc_ratios[i]);
      osc_env[i]->noteOn();
  }
}

void noteOff(){
  for(int i=0; i<nosc; i++){
    osc_env[i]->noteOff();
  }
}

void init_oscillators(){
    //voice init
  float freq = 440;
  for(int i=0; i<nosc; i++){
      oscmixer1.gain(i, 0.1);
      osc[i]->frequency(freq);
      osc_env[i]->noteOn();

      // turn off all modulators
      for (int j; j<nosc; j++){
          fmmixer[j]->gain(j, 0);  
      }
  }
}

void set_envelope(AudioEffectEnvelope* env, float a, float d, float s, float r){
  env->delay(0); // defaults to no delay
  env->hold(2.5); // defaults
  env->attack(a);
  env->decay(d);
  env->sustain(s);
  env->release(r);
}

void set_feedback(int algo, float val){
  int fb_osc = feedback_osc[algo];
  fmmixer[fb_osc]->gain(fb_osc, 1);
}

void set_algorithm(int algo){
  // reset all modulators
  for (int i; i<nosc; i++){
    for (int j; j<nosc; j++){
      fmmixer[i]->gain(j, 0);  
    }
  }

  switch(algo){
  case 0: // A*->B->C->D->Mixer
    fmmixer[1]->gain(0, 1);
    fmmixer[2]->gain(1, 1);
    fmmixer[3]->gain(2, 1);
    oscmixer1.gain(0, 0);
    oscmixer1.gain(1, 0);
    oscmixer1.gain(2, 0);
    oscmixer1.gain(3, 1);
    break;
  case 3: // ((D->C) + A*)->B)->Mixer
    fmmixer[2]->gain(3, 1);
    fmmixer[1]->gain(2, 1);
    fmmixer[1]->gain(0, 1);
    oscmixer1.gain(0, 0);
    oscmixer1.gain(1, 1);
    oscmixer1.gain(2, 0);
    oscmixer1.gain(3, 0);
    break;
  case 5: // (A->B) + (C*->D)->Mixer
    fmmixer[1]->gain(0, 1);
    fmmixer[2]->gain(2, 1);
    fmmixer[3]->gain(2, 1);
    oscmixer1.gain(0, 0);
    oscmixer1.gain(1, 1);
    oscmixer1.gain(2, 0);
    oscmixer1.gain(3, 1);
    break;
  }
}

void modifyPatch(int cc, int val){
  if (cc == 16){ // modulator 1 level
    fmmixer[1]->gain(1, map_cc_to_range_linear(val, 0, 10));
  }
  if (cc == 17){ // modulator 2 level
    fmmixer[1]->gain(2, map_cc_to_range_linear(val, 0, 10));
    fmmixer[2]->gain(3, map_cc_to_range_linear(val, 0, 10));
  }
}


void setup() {
  // put your setup code here, to run once:
  AudioMemory(100);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  init_oscillators();

  set_envelope(osc_env[2], 0, 100, 0, 200);
  set_envelope(osc_env[3], 0, 100, 0, 200);
  set_envelope(osc_env[0], 0, 400, 0.25, 200);
  set_envelope(osc_env[1], 0, 100, 0.1, 200);

  // algorithm
  set_algorithm(algorithm);
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
        noteOn(note_freq);
        
        continue;
      }

      // synth note off
      else if (rx.header == 8){
        noteOff();
        continue;
      }

      else if (rx.header == 0x0B){ // control change
        modifyPatch((int)rx.byte2, (int)rx.byte3);
      }
    }
      
    midi_counter++;
    if (midi_counter > 1000){
      digitalWrite(ledPin, LOW);   // set the LED off
      midi_counter = 0;
    }    
  } while (rx.header != 0);
}
