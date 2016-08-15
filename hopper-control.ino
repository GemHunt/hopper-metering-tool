int hopperPin = 8;
int stopMotorPin = 9;
int inhibitMotorPin = 9;
unsigned long startTime;
unsigned long delayTime;

int offDelayTime = 90;

int betweenTime = 1000;
int pennyCount = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(hopperPin, INPUT);
  pinMode(stopMotorPin, OUTPUT);
  pinMode(inhibitMotorPin, OUTPUT);
  betweenTime -= offDelayTime;
  startTime = 0;
  
  
}

void loop() {


  //for timing
  if(millis()>60000){
    Serial.println("Done");
    while(1){
      delay(1000);
    }  
  }


  
 
  digitalWrite(stopMotorPin,HIGH);

  
  while(!digitalRead(hopperPin)){

    delay(offDelayTime);
    
    digitalWrite(stopMotorPin,LOW);
    
    delayTime = betweenTime-(millis()-startTime);
    
    if(delayTime > betweenTime + offDelayTime){
      delayTime = 0;  
    }
    
    Serial.print("Delay: ");
    Serial.println(delayTime);
    
    delay(delayTime);
    startTime = millis();
    pennyCount ++;
    Serial.print("Pennies: ");
    Serial.println(pennyCount);
    
  
    
    
  }
  
  

}
