#include <LibPrintf.h>

int HVpADC = A0;      // Analog Pin for reading HV+
int HVnADC = A1;      // Analog Pin for reading HV-
int VbattADC = A2;    // Analog Pin for reading Battery voltage
int HVpdig = 0;       // Positive but reading (digital)
int HVndig = 0;       // Negative bus reading (digital)
int HVdig = 0;        // Digital HV reading
//int HV = 0;           // Analog HV reading
int flag = 0;         // Used for setting precharge states
int Vref = 5;         // Max voltage the ADC can read
int ADCres = 1023;    // 10 bit ADC
int Vbattdig = 0;
int Vbatt = 0;

//float Conv = float(Vref)/float(ADCres);
float HVpA=0;
float HVnA=0;
float HVA=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVoltage();
  /*
  while (flag = 0);
  while (flag = 1){
    SafetyCheck();
  }
  */
  //printf("Digital Measurments\r\nHVp: %u HVn: %u Final Value = %d\r\n",HVpdig, HVndig, HVdig);
  printf("Analog Measurements:\r\nHVp: %f HVn: %f Final Value = %f\r\n",HVpA, HVnA,HVA);
  //Serial.print("Serial digital value =");
  //Serial.print(HVpdig);
  //Serial.print("\r\n");
  delay(1000);
}

void readVoltage(){
  // Function outputs the tractive system voltage as a number between 0 and 1023 (resolution of the 10bit ADC)
  // Function also returns the HV reaing as an analog voltage
  // The positive and negative rails are read via ADCs, inverter voltage is calculated by subtractive HV- from HV+
  HVpdig = analogRead(HVpADC);
  HVndig = analogRead(HVnADC);
  HVdig = HVpdig-HVndig;
  Vbattdig = analogRead(VbattADC);
  Vbattdig = Vbattdig-HVndig;
  
  // Analog to digital value conversions
  // *Needs to be adjusted for voltage divider
  //HV = (Vref/ADCres)*HVdig;
  Vbatt = float(Vref)/float(ADCres)*float(Vbattdig);
  HVpA = (float(Vref)/float(ADCres)*float(HVpdig));
  HVnA = (float(Vref)/float(ADCres)*float(HVndig));
  HVA = (float(Vref)/float(ADCres)*float(HVdig));
}

/*
void SafetyCheck(void){
}
*/