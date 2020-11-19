#include "Ultrasonic.h" 

const int echoPin = 6; 
const int trigPin = 7; 

const int pinoBuzzer = 2; 

Ultrasonic ultrasonic(trigPin,echoPin); 

int distancia; 

void setup(){
pinMode(echoPin, INPUT); 
pinMode(trigPin, OUTPUT); 
pinMode(pinoBuzzer, OUTPUT); 
}
void loop(){

hcsr04(); 

if(distancia <= 30){
tone(pinoBuzzer,1500);
}else{
noTone(pinoBuzzer);
}
}

void hcsr04(){
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);

distancia = (ultrasonic.Ranging(CM)); 
delay(500); 
}
