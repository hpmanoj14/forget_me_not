/*
  This example reads audio data from the on-board PDM microphones, and prints
  out the samples to the Serial console. The Serial Plotter built into the
  Arduino IDE can be used to plot the audio data (Tools -> Serial Plotter)

  Circuit:
  - Arduino Nano 33 BLE Sense board

  This example code is in the public domain.
*/

#define CAPTURE_SIZE 1500
#define PIN_IN_0       A0   // For analog read
uint16_t input[CAPTURE_SIZE+2];

int delimeter_length=4;
uint8_t delimiter[]={0xde, 0xad, 0xbe, 0xef};


#include <PDM.h>

// buffer to read samples into, each sample is 16-bits
// short sampleBuffer[256];
short sampleBuffer[1];

short sampleBuffer_super[CAPTURE_SIZE+2];

// number of samples read
volatile int samplesRead;
volatile int counter;
unsigned long t1,t2;

void setup() {
  pinMode(PIN_IN_0, INPUT);
  analogReadResolution(12);


  Serial.begin(115200);
  while (!Serial);

  PDM.setBufferSize(2);

  // configure the data receive callback
  PDM.onReceive(onPDMdata);

  // optionally set the gain, defaults to 20
  // PDM.setGain(30);

  // initialize PDM with:
  // - one channel (mono mode)
  // - a 16 kHz sample rate
  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1);
  }

  counter=0;
}

void loop() {
  // wait for samples to be read
  if (samplesRead) {
    // Serial.println("---");
    // Serial.println(sampleBuffer[0]);
    // Serial.print("  ");
    // input[counter]=analogRead(PIN_IN_0);
    // Serial.println(input[counter]);
  
    // sampleBuffer_super[counter]=sampleBuffer[0];
    t1 = millis();
    sampleBuffer_super[counter]=sampleBuffer[0]+32768;
    input[counter]=analogRead(PIN_IN_0);
    t2 = millis();
    Serial.println(t2-t1);


    counter++;

    // // print samples to the serial monitor or plotter
    // for (int i = 0; i < samplesRead; i++) {
    //   Serial.println(sampleBuffer[i]);
    //   Serial.print("  ");
    //   input[0]=analogRead(PIN_IN_0);
    //   Serial.println(input[0]);
    //   // check if the sound value is higher than 500
    //   if (sampleBuffer[i]>=500){
    //     digitalWrite(LEDR,LOW);
    //     digitalWrite(LEDG,HIGH);
    //     digitalWrite(LEDB,HIGH);
    //   }
    //   // check if the sound value is higher than 250 and lower than 500
    //   if (sampleBuffer[i]>=250 && sampleBuffer[i] < 500){
    //     digitalWrite(LEDB,LOW);
    //     digitalWrite(LEDR,HIGH);
    //     digitalWrite(LEDG,HIGH);
    //   }
    //   //check if the sound value is higher than 0 and lower than 250
    //   if (sampleBuffer[i]>=0 && sampleBuffer[i] < 250){
    //     digitalWrite(LEDG,LOW);
    //     digitalWrite(LEDR,HIGH);
    //     digitalWrite(LEDB,HIGH);
    //   }
    // }

    // clear the read count
    samplesRead = 0;
  }

  if(counter==1500)
  {
    //
    send_sample();
    counter=0;
  }

}

void onPDMdata() {
  // query the number of bytes available
  int bytesAvailable = PDM.available();

  // read into the sample buffer
  PDM.read(sampleBuffer, bytesAvailable);
  // input[0]=analogRead(PIN_IN_0);

  // 16-bit, 2 bytes per sample
  samplesRead = bytesAvailable / 2;
}

void send_sample()
{   
   Serial.write(delimiter, sizeof(delimiter));
   input[CAPTURE_SIZE]  =0;
   input[CAPTURE_SIZE+1]=0;
   Serial.write((uint8_t *)input, sizeof(input));   

 Serial.write(delimiter, sizeof(delimiter));
   sampleBuffer_super[CAPTURE_SIZE]  =1;
   sampleBuffer_super[CAPTURE_SIZE+1]=1;
   Serial.write((uint8_t *)sampleBuffer_super, sizeof(sampleBuffer_super));       
}
