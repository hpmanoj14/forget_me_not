// #define PIN_IN_0       A0   // For analog read
// #define PIN_IN_1       A1   // For analog read
// #define PIN_IN_2       A2   // For analog read
// #define PIN_IN_3       A3   // For analog read

#define PIN_IN_0       0   // For analog read
#define PIN_IN_1       1   // For analog read
#define PIN_IN_2       2   // For analog read
#define PIN_IN_3       3   // For analog read

#define CAPTURE_SIZE 600
#define BAUD_RATE    115200
#define channel 4

// Buffer
uint16_t input[channel][CAPTURE_SIZE+2];

uint16_t input0[CAPTURE_SIZE+2];
uint16_t input1[CAPTURE_SIZE+2];
uint16_t input2[CAPTURE_SIZE+2];
uint16_t input3[CAPTURE_SIZE+2];

// 
int delimeter_length=4;
uint8_t delimiter[]={0xde, 0xad, 0xbe, 0xef};


void setup()
{
//    pinMode(PIN_IN_0, INPUT);
//    pinMode(PIN_IN_1, INPUT);
//    pinMode(PIN_IN_2, INPUT);
//    pinMode(PIN_IN_3, INPUT);

    Serial.begin(BAUD_RATE);

    // Set ADC resolution to 12-bit 
    analogReadResolution(12);
}

void loop()
{
    collect_sample();
    send_sample();
}

void collect_sample()
{
    // Reset the index for the input buffer
    int i=0;

    while(i<CAPTURE_SIZE)
    {
       input[0][i]=analogRead(PIN_IN_0);
       delayMicroseconds(50);
       input[1][i]=analogRead(PIN_IN_1);
       delayMicroseconds(50);
       input[2][i]=analogRead(PIN_IN_2);
       delayMicroseconds(50);
       input[3][i]=analogRead(PIN_IN_3);
       delayMicroseconds(50);

        // input0[i]=analogRead(PIN_IN_0);
        // delayMicroseconds(50);
        // input1[i]=analogRead(PIN_IN_1);
        // delayMicroseconds(50);
        // input2[i]=analogRead(PIN_IN_2);
        // delayMicroseconds(50);
        // input3[i]=analogRead(PIN_IN_3);
        // delayMicroseconds(50);
        
        i++;
    }
}

void send_sample()
{   
    for(int i=0; i<channel; i++)
    {
        Serial.write(delimiter, sizeof(delimiter));
        // Channel number (one at the end of each channel's transmission)
        input[i][CAPTURE_SIZE]=i;

        // Frame completion byte (only after all channels sent)
        input[i][CAPTURE_SIZE+1]=0;

        if(i==(channel-1))input[i][CAPTURE_SIZE+1]=1;

        Serial.write((uint8_t *)input[i], sizeof(input[i]));      
    }


    // Serial.write(delimiter, sizeof(delimiter));
    // input0[CAPTURE_SIZE]  =0;
    // input0[CAPTURE_SIZE+1]=0;
    // Serial.write((uint8_t *)input0, sizeof(input0));

    // Serial.write(delimiter, sizeof(delimiter));
    // input1[CAPTURE_SIZE]  =1;
    // input1[CAPTURE_SIZE+1]=0;
    // Serial.write((uint8_t *)input1, sizeof(input1));

    // Serial.write(delimiter, sizeof(delimiter));
    // input2[CAPTURE_SIZE]  =2;
    // input2[CAPTURE_SIZE+1]=0;
    // Serial.write((uint8_t *)input2, sizeof(input2));

    // Serial.write(delimiter, sizeof(delimiter));
    // input3[CAPTURE_SIZE]  =3;
    // input3[CAPTURE_SIZE+1]=1;
    // Serial.write((uint8_t *)input3, sizeof(input3));
    
}
