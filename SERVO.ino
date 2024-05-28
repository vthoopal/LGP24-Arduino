//moves motor to a specific angle based on distance
#include <Servo.h>;
Servo myservo;
Servo MYservo; 
void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
MYservo.attach(3);
pinMode(12, OUTPUT);
pinMode(13, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int d= dist(12,13);
  int angle = map(d,0, 400, 0, 180);
  MYservo.write(0);
  myservo.write(0);
  delay(1000);
  myservo.write(angle);
  MYservo.write(180-angle);
  delay(1000);
}
int dist(int trigPin, int echoPin){
      digitalWrite(trigPin, LOW);
    delayMicroseconds(2); // wait for 2 ms to avoid
                          // collision in serial monitor
 
    digitalWrite(
        trigPin,
        HIGH); // turn on the Trigger to generate pulse
    delayMicroseconds(
        10); // keep the trigger "ON" for 10 ms to generate
             // pulse for 10 ms.
 
    digitalWrite(trigPin,
                 LOW); // Turn off the pulse trigger to stop
                       // pulse generation
 
    // If pulse reached the receiver echoPin
    // become high Then pulseIn() returns the
    // time taken by the pulse to reach the
    // receiver
 
  long  duration = pulseIn(echoPin, HIGH);
   int  distance
        = duration * 0.0344 / 2; // Expression to calculate
                                 // distance using time
        delay(50);


    return distance;
}//distance calculation
