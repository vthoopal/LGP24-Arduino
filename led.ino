//Shows different colours based on distance
int r = 2;
int w = 3;
int b = 4;
int g = 5;
int y = 6;
int a = 13;


 int colour[6]={a,r,w,b,g,y};
int state[6]={0, 0, 0,0,0,0};
void setup() {
 pinMode(r, OUTPUT);
 pinMode(w, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(g, OUTPUT);
 pinMode(y, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, INPUT);
Serial.begin(9600);
Serial.print("hi");
}

void loop() {
  // put your main code here, to run repeatedly:
  int di = dist(9,10);
  Serial.println(di);
   // digitalWrite(colour[a], LOW);
    a = round(di/20);
    if(digitalRead(11)==0){
     digitalWrite(colour[2], HIGH);
    digitalWrite(colour[3], HIGH);
    digitalWrite(colour[4], HIGH);
    digitalWrite(colour[5], HIGH);
    digitalWrite(colour[1], HIGH); 
    }
    else if (colour[a] == r){
    digitalWrite(colour[2], LOW);
    digitalWrite(colour[3], LOW);
    digitalWrite(colour[4], LOW);
    digitalWrite(colour[5], LOW);
    digitalWrite(colour[a], HIGH);
    }
     else   if (colour[a] == w){
    digitalWrite(colour[1], LOW);
    digitalWrite(colour[3], LOW);
    digitalWrite(colour[4], LOW);
    digitalWrite(colour[5], LOW);
    digitalWrite(colour[a], HIGH);
    }
     else   if (colour[a] == b){
    digitalWrite(colour[1], LOW);
    digitalWrite(colour[2], LOW);
    digitalWrite(colour[4], LOW);
    digitalWrite(colour[5], LOW);
    digitalWrite(colour[a], HIGH);
    }
     else   if (colour[a] == g){
    digitalWrite(colour[1], LOW);
    digitalWrite(colour[2], LOW);
    digitalWrite(colour[3], LOW);
    digitalWrite(colour[5], LOW);
    digitalWrite(colour[a], HIGH);
    state[a]=1;}
     else   if (colour[a] == y){
    digitalWrite(colour[1], LOW);
    digitalWrite(colour[3], LOW);
    digitalWrite(colour[4], LOW);
    digitalWrite(colour[2], LOW);
    digitalWrite(colour[a], HIGH);
    state[a]=1;}
    

    delay(250);
    Serial.println(a);

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
