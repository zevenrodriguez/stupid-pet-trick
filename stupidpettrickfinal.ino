#include <Servo.h>
Servo servoMotor;

int fsrPin = 0;    // Analog input pin that the potentiometer is attached to
int fsrValue = 0;   // value read from the pot
int fsrRef = 10;   // value read from the pot
int redLed = 4;
int yellowLed = 3;
int greenLed = 2;
int servoPin = 9;

int freq = 440;
long time = 0;

long lastTime = 0;

boolean setTime=true;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // declare the led pin as an output:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
   //pinMode(speakerPin, OUTPUT);
    pinMode(servoPin, OUTPUT);  // Set servo pin as an output pin
 // pulse = minPulse;
  servoMotor.attach(servoPin);
  //noiseMaker.begin(9);

}

void loop() {

  fsrValue = analogRead(fsrPin); // read the pot value
     Serial.println(fsrValue);
  if(fsrValue < 60){
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    // Serial.println("this is when the fsr is not pressed");
    //Serial.println(time);
   servoMotor.write(180);
    setTime=true;
   // Serial.println(lastTime);

   
  }

  if(fsrValue > 60 && setTime == true){
      lastTime= millis();
      //Serial.println("START TIMER");
      setTime=false;
      //Serial.println(lastTime);
  } 
 
  if(fsrValue > 60) {
if(millis() - lastTime < 2000){
    digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
     servoMotor.write(117);
    //   tone = 1136;
      // playTone(tone, 100);
       

}
  if((millis() - lastTime >= 2000) && (millis() - lastTime <5000)){

       //tone = 1136;
       //playTone(tone, 100);
        digitalWrite(greenLed, LOW);
        digitalWrite(redLed, LOW);
        digitalWrite(yellowLed, HIGH);
       servoMotor.write(90);
        // Serial.println("TEN SECOND LOOP");
         //Serial.println(lastTime);
    }
 
  
    if (millis() - lastTime >= 5000 ){
      //Serial.println("20 SECOND LOOP");

      //tone = 1014;
      // playTone(tone, 100);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
      servoMotor.write(70);
      //Serial.println(lastTime);
     }
     delay(100);
  }

  //Serial.println(lastTime);
  }
 /* 
  int lastToneTime = 0;
  
  void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
         
        digitalWrite(speakerPin, HIGH);
      // delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
     // delayMicroseconds(tone);
    }
  }
  */
