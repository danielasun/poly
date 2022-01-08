// patch functionality

/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file   
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11, pin 7 on Teensy with audio board
 ** MISO - pin 12
 ** CLK - pin 13, pin 14 on Teensy with audio board
 ** CS - pin 4, pin 10 on Teensy with audio board
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
   
 */
 
#include <SD.h>
#include <SPI.h>

namespace patch {

File myFile;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// Teensy audio board: pin 10
// Teensy 3.5 & 3.6 & 4.1 on-board: BUILTIN_SDCARD
// Wiz820+SD board: pin 4
// Teensy 2.0: pin 0
// Teensy++ 2.0: pin 20
const int chipSelect = 10;

void printDirectory(File dir, int numTabs) {
  while (true) {
    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }

    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

void ls_root(){
  // list directories
  myFile = SD.open("/");
  printDirectory(myFile, 0); 
  myFile.close();
}

// filesystem sizes
const int nparams = 128;
const int npatches = 64;
float patchdata[npatches][nparams];
float patchdata2[npatches][nparams];
int patchesfilesize = sizeof(float)*nparams*npatches;

const int npatchchar = 16;
char patchnames[npatches][npatchchar];

// util //
// char buff[1000];

byte initpatch[nparams] = {
  0,0,0,0,0,0,0,127, // 0-7
  64,0,0,0,0,0,0,0, // 8-15
  0,0,0,0,0,0,0,0, // 16-23
  0,0,0,0,0,0,0,0, // 24-31
  0,0,0,64,64,64,0,0, // 32-39
  0,0,0,0,0,0,0,0, // 40-47
  0,0,0,0,0,0,0,0, // 48-55
  0,0,0,0,0,0,0,0, // 56-63
  64,0,0,0,0,0,127,0, // 64-71
  0,3,127,127,0,0,0,0, // 72-79
  0,0,0,0,0,0,0,127, // 80-87
  127,0,0,0,0,0,0,0, // 88-95
  0,0,0,0,0,0,0,0, // 96-103
  0,0,0,0,0,0,0,0, // 104-111
  0,0,0,0,0,0,0,0, // 112-119
  0,0,0,0,0,0,0,0, // 120-127
};


char parameter_names[nparams][6]={
  "","","","","","","","VOL", // 0-7
  "BAL","","","","","","","", // 8-15
  "","","","","F_ATK","F_DEC","F_SUS","F_REL", // 16-23
  "","","","","","","","", // 24-31
  "DCOFF","PWM","WFOLD","C_DET","F_DET","O_MIX","-","NOISE", // 32-39
  "","","","","","","","", // 40-47
  "LFO_A","LFO_F","LFO_M","","","","","", // 48-55
  "","","","","","","","", // 56-63
  "","","","","","","WAVET","F_RES", // 64-71
  "A_REL","A_ATK","F_CUT","A_SUS","F_ENV","F_TYP","F_MOD","KEYTR", // 72-79
  "A_DEC","","","","","ROOM","DAMP","BIT_D", // 80-87
  "SRR","","","REV_S","","","","", // 88-95
  "","","","","","","","", // 96-103
  "","","","","","","","", // 104-111
  "","","","","","","","", // 112-119
  "","","","","","","","", // 120-127
};


void initSDCard(){
  SPI.setMOSI(7);  // Audio shield has MOSI on pin 7
  SPI.setSCK(14);  // Audio shield has SCK on pin 14
}

// create patch storage directory if it's not there already
int initPatchStorage(){
  int status = 0;
  if(!SD.exists("patchstorage")){
    if (SD.mkdir("patchstorage")){
      Serial.println("Succeeded to create directory 'patchstorage'");
      status = 0;
    } else {
      Serial.println("Failed to create directory 'patchstorage'");
      status = 1;
    }
    
  }
  else{
    status = 2;
  }
  return status;
}

void printPatch(byte patch[], char buff[]){
  for (int i=0; i < nparams; i++){
    sprintf(buff, "i: %d, param: %s val: %d", i, parameter_names[i], patch[i]);
    Serial.println(buff);
  }
}



//void setup()
//{
// //UNCOMMENT THESE TWO LINES FOR TEENSY AUDIO BOARD:
// SPI.setMOSI(7);  // Audio shield has MOSI on pin 7
// SPI.setSCK(14);  // Audio shield has SCK on pin 14
//  
// // Open serial communications and wait for port to open:
//  Serial.begin(9600);
//   while (!Serial) {
//    ; // wait for serial port to connect.
//  }
//
//
//  Serial.print("Initializing SD card...");
//
//  if (!SD.begin(chipSelect)) {
//    Serial.println("initialization failed!");
//    return;
//  }
//  Serial.println("initialization done.");
//
//  // patch storage
//  for(int patchnum = 0; patchnum<npatches; patchnum++){
//      for(int i=0; i<nparams; i++){
//        patchdata[patchnum][i] = i+3 + patchnum;
//      }    
//  }
//
//  // patch names
//  for (int patchnum=0; patchnum<npatches; patchnum++){
//    sprintf(patchnames[patchnum], "init patch");
//  }
//
//
//  // create patch storage directory if it's not there already
//  if(!SD.exists("patchstorage")){
//    if (SD.mkdir("patchstorage")){
//      Serial.println("Succeeded to create directory 'patchstorage'");
//    } else {
//      Serial.println("Failed to create directory 'patchstorage'");
//    }  
//  }
//  
//  // write patch
//  myFile = SD.open("patchstorage/patches.dat", FILE_WRITE);
//  if (myFile){
//    
//    myFile.write(patchdata, patchesfilesize);
//    Serial.print("patchsize: ");
//    Serial.println(patchesfilesize);
//  }
//  myFile.close();
//
//  // list directories
//  ls_root();
//
//  myFile = SD.open("patchstorage/patches.dat");
//  if (myFile){
//    Serial.println("opened patches.dat");
//
//    Serial.println("reading...");
//    while(myFile.available()){
//      myFile.read(patchdata2, patchesfilesize);
//    }
//
//    for(int patchnum=0; patchnum<npatches; patchnum++){
//      sprintf(buff, "Patch %d, \"%s\": ", patchnum, patchnames[patchnum]);
//      Serial.print(buff);
//      for(int j=0; j<nparams;j++){
//        Serial.print(patchdata2[patchnum][j]);
//        Serial.print(" ");
//      }
//      Serial.println();
//    }
//    myFile.close();
//  } 
//  else{
//    Serial.println("error opening patches.dat");
//  }
//  
//  
//
//  SD.remove("patchstorage/patches.dat");
//  SD.rmdir("patchstorage");
//}
}