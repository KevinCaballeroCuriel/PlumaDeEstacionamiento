#include <Servo.h>
    Servo servo;
int const trigPin = 6;
int const echoPin = 5;
int const ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
    servo.attach(3);
}

void loop() {
  int distanciaMS, distanciaCM;
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  distanciaMS = pulseIn(echoPin, HIGH);
  // La distancia se mide en centimetros, a partir de los microsegundos obtenidos del sensor ultrasonico, con la siguiente formula
  distanciaCM = (distanciaMS/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
  if (distanciaCM <= 10 && distanciaCM >= 0) {
    delay(1000);
    servo.write(180);
      digitalWrite(ledPin, HIGH);
      delay(3000);
  } else {
    digitalWrite(ledPin, LOW);
    servo.write(80);
  }
  delay(60);
}
