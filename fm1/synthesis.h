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
