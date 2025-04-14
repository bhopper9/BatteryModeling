/*****************************************************

              Prechage V1 Firmware
  
*****************************************************/
  
  int Vinvdig = 0;        // Tracks the inverter voltage (direct value from ADC)
  int Vbattdig = 0;       // Tracks the battery voltage (direct value from ADC)
  int VinvPIN = A2;       // Analog Pin for reading Inverter Voltage 
  int VbattPIN = A7;      // Analog Pin for reading Battery Voltage
  int RelayPIN = 3;       // CHEK LAURENS WIRING
  int AIRPIN = 2;         // CHECK LAURENS WIRING
  int State=0;            // Tracks the State of the Precharge board, State 0 is ready to precharge, State 1 is Precharged, State 3 is fault
  int Vdiff;
  int Vthresh = 500;



void setup() {
  Serial.begin(9600);     // For reading through Serial Monitor

  pinMode(RelayPIN,OUTPUT);   // Initialize Precharge Relay Pin 
  pinMode(AIRPIN,OUTPUT);
  digitalWrite(RelayPIN, HIGH);
}

void loop() {
  //digitalWrite(RelayPIN, LOW);
  //digitalWrite(AIRPIN,LOW);

  Vinvdig = analogRead(VinvPIN);
  Vbattdig = analogRead(VbattPIN);
  Vdiff = abs(Vinvdig-Vbattdig);

  if(Vbattdig<=Vthresh){
    digitalWrite(AIRPIN, LOW);
    digitalWrite(RelayPIN, LOW);
    State=3;
  }
  
  if (Vdiff>=0.05*Vinvdig && Vbattdig>Vthresh){
    digitalWrite(AIRPIN, LOW);
    digitalWrite(RelayPIN, HIGH);
    State=0;
  }
  if (Vdiff<=0.05*Vinvdig && Vinvdig>Vthresh){
    digitalWrite(AIRPIN, HIGH);
    State=1;
  }


  Serial.print("Vinv: ");
  Serial.print(Vinvdig);
  Serial.print("\n");
  Serial.print("Vbatt: ");
  Serial.print(Vbattdig);
  Serial.print("\n");
  Serial.print("State: ");
  Serial.print(State);
  Serial.print("\n");
  delay(100);
}
