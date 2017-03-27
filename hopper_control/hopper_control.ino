int hopperSignalPin = A0;
int motorPin = 9;
unsigned long coinEnterTime = 0;
unsigned long coinExitTime = 0;
unsigned long coinPassTime = 0;
//OK just once and stop for now:
unsigned long betweenTime = 90000000;
unsigned long pennyCount = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(hopperSignalPin, INPUT);
  pinMode(motorPin, OUTPUT);

  digitalWrite(motorPin,LOW);
}

void loop() {
  int signalReading = analogRead(hopperSignalPin);
    Serial.print("sig");
    Serial.println(signalReading);
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
