#include"arduino.h"
const int  M1A = 5;// ขามอเตอร์ 1A
const int  M1B = 18;// ขามอเตอร์ 1B
const int  M2A = 19;// ขามอเตอร์ 2A
const int  M2B = 21;// ขามอเตอร์ 2B
const int Sprint1 = 16; // ขามอเตอร์ หมุนลูกปิงปอง
const int Sprint2 = 17; // ขามอเตอร์ หมุนลูกปิงปอง
const int move_up = 22; // ปุ่มเดินหน้า
const int move_down = 23; // ปุ่มถอยหลัง
const int move_right = 32; // ปุ่มเลี้ยวขวา
const int move_left = 33; // ปุ่มเลี้ยวซ้าย
const int sprint = 26; // ปุ่มหมุนเพื่อเก็บลูกปิงปอง
const int stop_sprint = 25; // ปุ่มหยุดหมุนลูกปิงปอง
int counter_sprint = 0; // ตัวแปรนับสวิตในการหมุนลูกปิงปอง

void setup() {
  pinMode(M1A, OUTPUT); // กำหนด PIN 5 เป็น OUTPUT
  pinMode(M1B, OUTPUT); // กำหนด PIN 18 เป็น OUTPUT
  pinMode(M2A, OUTPUT); // กำหนด PIN 19 เป็น OUTPUT
  pinMode(M2B, OUTPUT); // กำหนด PIN 21 เป็น OUTPUT
  pinMode(Sprint1, OUTPUT); // กำหนด PIN 16 เป็น OUTPUT
  pinMode(Sprint2, OUTPUT); // กำหนด PIN 17 เป็น OUTPUT
  pinMode(move_up, INPUT_PULLUP); // กำหนด PIN 22 เป็น INPUT_PULLUP
  pinMode(move_down, INPUT_PULLUP); // กำหนด PIN 23 เป็น INPUT_PULLUP
  pinMode(move_right, INPUT_PULLUP); // กำหนด PIN 32 เป็น INPUT_PULLUP
  pinMode(move_left, INPUT_PULLUP); // กำหนด PIN 33 เป็น INPUT_PULLUP
  pinMode(sprint, INPUT_PULLUP); // กำหนด PIN 26 เป็น INPUT_PULLUP
  pinMode(stop_sprint, INPUT_PULLUP); // กำหนด PIN 25 เป็น INPUT_PULLUP
  digitalWrite(M1A, LOW); // กำหนดสถานะเริ่มต้นของมอเตอร์ 1A เป็น LOW
  digitalWrite(M1B, LOW); // กำหนดสถานะเริ่มต้นของมอเตอร์ 1B เป็น LOW
  digitalWrite(M2A, LOW); // กำหนดสถานะเริ่มต้นของมอเตอร์ 2A เป็น LOW
  digitalWrite(M2B, LOW); // กำหนดสถานะเริ่มต้นของมอเตอร์ 2B เป็น LOW
  digitalWrite(Sprint1, LOW); // กำหนดสถานะเริ่มต้นของมอเตอร์ หมุนลูกปิงปอง เป็น LOW
  digitalWrite(Sprint2, LOW); // กำหนดสถานะเริ่มต้นของมอเตอร์ หมุนลูกปิงปอง เป็น LOW
  }
void loop() {
  if (digitalRead(move_down) == LOW){ // ถ้าปุ่มเดินหน้าถูกกด
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
  } else if (digitalRead(move_up) == LOW){ // ถ้าปุ่มถอยหลังถูกกด
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
  } else if (digitalRead(move_right) == LOW){ // ถ้าปุ่มเลี้ยวขวาถูกกด
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
  } else if (digitalRead(move_left) == LOW){ // ถ้าปุ่มเลี้ยวซ้ายถูกกด
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);}
  else if (digitalRead(sprint) == LOW){ // ถ้าปุ่มหมุนถูกกด ให้ +1 ตัวแปรนับสวิตในการหมุนลูกปิงปองเพื่อเลือกทิศทางการหมุน
    counter_sprint = (counter_sprint + 1) % 3; // นับสวิตในการหมุนลูกปิงปอง
    delay(500);} // หน่วงเวลา 500 ms 
  else if (digitalRead(stop_sprint) == LOW){ // ถ้าปุ่มหยุดหมุนถูกกด ให้หยุดหมุน
    digitalWrite(Sprint1, LOW); 
    digitalWrite(Sprint2, LOW);
    counter_sprint = 0;} // ตัวแปรนับสวิตในการหมุนลูกปิงปอง เป็น 0
  else { // ถ้าไม่มีปุ่มถูกกด
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);}
  if (counter_sprint == 1){ // ถ้าตัวแปรนับสวิตในการหมุนลูกปิงปอง เป็น 1 ให้หมุนเข้า
    digitalWrite(Sprint1, LOW);
    digitalWrite(Sprint2, HIGH);} 
  else if (counter_sprint == 2){ // ถ้าตัวแปรนับสวิตในการหมุนลูกปิงปอง เป็น 2 ให้หมุนออก
    digitalWrite(Sprint1, HIGH);
    digitalWrite(Sprint2, LOW);}}