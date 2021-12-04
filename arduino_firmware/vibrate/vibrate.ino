#define PIN_IN_0       A0   // For analog read

#define CAPTURE_SIZE 1500
#define BAUD_RATE    115200
#define channel 1

// Buffer
uint16_t input[CAPTURE_SIZE+2];

// 
int delimeter_length=4;
uint8_t delimiter[]={0xde, 0xad, 0xbe, 0xef};


void setup()
{
   pinMode(PIN_IN_0, INPUT);

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
        input[i]=analogRead(PIN_IN_0);
        delayMicroseconds(300);
        
        i++;
    }
}

void send_sample()
{   
    Serial.write(delimiter, sizeof(delimiter));
    input[CAPTURE_SIZE]  =0;
    input[CAPTURE_SIZE+1]=1;
    Serial.write((uint8_t *)input, sizeof(input));   
}
