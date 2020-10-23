// Menambahkan Library IR Remote by Ken Shirriff
#include <IRremote.h>

// Set pin dalam Arduino ke IR Remote dan Relay
int IR_PIN = 2; // Pin Digital No. 2 untuk Signal IR Receiver
int R1 = 3; // Pin Digital No. 3 untuk IN Relay

// Set code source IR Receiver
int Code1 = 0xFFA25D; // Kode tombol 1

IRrecv irDetect(IR_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irDetect.enableIRIn();
  pinMode(R1, OUTPUT);
  digitalWrite(R1,HIGH);
}

void loop() 
{
   
  if (irDetect.decode(&results)) 
    {
      Eksekusi();
      Serial.println(results.value);
      irDetect.resume();
    }
}

void Eksekusi(){
  switch(results.value){
    case (Code1):
      digitalWrite(R1,!digitalRead(R1));
      break;
      default:
      break;
  }
  delay(200);
}
