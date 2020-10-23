// Menambahkan Library IR Remote by Ken Shirriff
#include <IRremote.h>

// Set pin dalam Arduino ke IR Remote
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
    irDetect.resume(); // Melanjutkan Code
  }
}
