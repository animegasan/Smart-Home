/*
Project 01  : Membuat Sensor Infrared di Server
Tujuan      : Agar server dapat di ON/OFF secara online via Bardi Smart Universal IR Remote
Fungsi Code : Test IR Remote ke Arduino dengan Boud Rate ke 9600
*/

// Menambahkan Library IR Remote by Ken Shirriff
#include <IRremote.h>

// Set pin Digital dalam Arduino ke IR Remote
int IR_PIN = 2;

IRrecv irDetect(IR_PIN);
decode_results irIn;

void setup()
{
  Serial.begin(9600);
  irDetect.enableIRIn(); // Memulai IR Receiver
}

void loop() {
  if (irDetect.decode(&irIn)) {
    Serial.println(irIn.value, HEX);
    irDetect.resume(); // Melanjutkan source code
  }
}
