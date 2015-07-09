/*
Force Table controler by Joakim Christoffersson
Based on HC-SR04 Ping distance sensor trollmaker.com/article3/arduino-and-hc-sr04-ultrasonic-sensor
 */

#define trigPin 13
#define echoPin 12
#define down 10
#define up 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(down, OUTPUT);
  pinMode(up, OUTPUT);
  }

void loop() {
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 12) {
    // lower table
    Serial.println("DOWN");
    digitalWrite(down,HIGH);
     digitalWrite(up,LOW);
    }
    else if (distance > 12 && distance <50) {
    // raise table
    Serial.println("UP");
    digitalWrite(up,HIGH);
    digitalWrite(down,LOW);
    }
  else {
    digitalWrite(up,LOW);
    digitalWrite(down,LOW);
  }
  if (distance >= 300 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(250);
}
  
