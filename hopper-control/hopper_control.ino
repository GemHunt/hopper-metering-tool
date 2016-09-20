int hopperSignalPin = 0;
int motorPin = 9;
unsigned long startTime;
unsigned long delayTime = 35;
unsigned long coinEnterTime = 0;
unsigned long coinExitTime = 0;
unsigned long coinPassTime = 0;
unsigned long betweenTime = 200;
unsigned long pennyCount = 0;
int lastSignalLow = 0;
int lastSignalHigh = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(hopperSignalPin, INPUT);
  pinMode(motorPin, OUTPUT);

  betweenTime -= coinPassTime;
  startTime = millis();
  //Turn the motor on:
  digitalWrite(motorPin,LOW);
  startTime = millis();
}

void loop() {
  int signalReading = analogRead(hopperSignalPin);
    //Serial.print("sig");
    //Serial.println(signalReading);
  if (signalReading < 20) {
    if (coinPassTime == 0){
      coinPassTime = 1;
      coinEnterTime = millis();
      Serial.print("Enter");
      Serial.println(coinEnterTime);
      delay(10);
    }
  }
  
  if (signalReading >= 20){
    if (coinPassTime != 0){
      coinPassTime = millis() - coinEnterTime;
      Serial.print("Pass");
      Serial.println(coinPassTime);
      if (coinExitTime == 0){
        coinPassTime = 1;
        coinExitTime = millis();
        Serial.print("Exit");
        Serial.println(coinExitTime);
      }
      if (coinExitTime >= 20){
        digitalWrite(motorPin,HIGH);
        delay(betweenTime - coinPassTime);
        coinExitTime = 0;
        coinPassTime = 0;
        pennyCount ++;
        Serial.print("$");
        Serial.println(pennyCount);
        digitalWrite(motorPin,LOW);
      }    
    }
  }
}
