#include"arduino.h"
const int  M1A = 5;
const int  M1B = 18;
const int  M2A = 19;
const int  M2B = 21;
const int Sprint1 = 16;
const int Sprint2 = 17;
const int move_up = 22;
const int move_down = 23;
const int move_right = 32;
const int move_left = 33;
const int sprint = 26;
const int stop_sprint = 25;
int counter_sprint = 0;
void setup() {
  Serial.begin(115200);
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(Sprint1, OUTPUT);
  pinMode(Sprint2, OUTPUT);
  pinMode(move_up, INPUT_PULLUP);
  pinMode(move_down, INPUT_PULLUP);
  pinMode(move_right, INPUT_PULLUP);
  pinMode(move_left, INPUT_PULLUP);
  pinMode(sprint, INPUT_PULLUP);
  pinMode(stop_sprint, INPUT_PULLUP);
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
  digitalWrite(Sprint1, LOW);
  digitalWrite(Sprint2, LOW);}
  
void loop() {
  if (digitalRead(move_down) == LOW){
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
  } else if (digitalRead(move_up) == LOW){
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
  } else if (digitalRead(move_right) == LOW){
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
  } else if (digitalRead(move_left) == LOW){
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);}
  else if (digitalRead(sprint) == LOW){
    counter_sprint = (counter_sprint + 1) % 3;
    Serial.println(counter_sprint);
    delay(500);} 
  else if (digitalRead(stop_sprint) == LOW){
    digitalWrite(Sprint1, LOW); 
    digitalWrite(Sprint2, LOW);
    counter_sprint = 0;} 
  else {
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);}
  if (counter_sprint == 1){
    digitalWrite(Sprint1, LOW);
    digitalWrite(Sprint2, HIGH);} 
  else if (counter_sprint == 2){
    digitalWrite(Sprint1, HIGH);
    digitalWrite(Sprint2, LOW);}}