/*
Project 01  : Membuat Sensor Infrared di Server
Tujuan      : Agar server dapat di ON/OFF secara online via Bardi Smart Universal IR Remote
Fungsi Code : Print Out source code dari IR Remote ke Arduino dengan Boud Rate ke 9600
*/

// Menambahkan Library IR Remote by Ken Shirriff
#include <IRremote.h>

// Set pin Digital dalam Arduino ke IR Remote
int IR_PIN = 2;

// Set source code IR Receiver Boud Rate ke 9600
int Code0 = 0xFF4AB5; // Tombol 0
int Code1 = 0xFF6897; // Tombol 1
int Code2 = 0xFF9867; // Tombol 2
int Code3 = 0xFFB04F; // Tombol 3
int Code4 = 0xFF30CF; // Tombol 4
int Code5 = 0xFF18E7; // Tombol 5
int Code6 = 0xFF7A85; // Tombol 6
int Code7 = 0xFF10EF; // Tombol 7
int Code8 = 0xFF38C7; // Tombol 8
int Code9 = 0xFF5AA5; // Tombol 9
int CodeStar = 0xFF42BD; // Tombol *
int CodeTagar = 0xFF52AD; // Tombol #
int CodeOk = 0xFF02FD; // Tombol OK
int CodeUp = 0xFF629D; // Tombol Atas
int CpdeDown = 0xFFA857; // Tombol Bawah
int CodeRight = 0xFFC23D; // Tombol Kanan
int CodeLeft = 0xFF22DD; // Tombol Kiri

IRrecv irDetect(IR_PIN);
decode_results irIn;

void setup()
{
  Serial.begin(9600);
  
  irDetect.enableIRIn(); // Memulai IR Receiver
}

void loop() {
  if (irDetect.decode(&irIn)) {
    decodeIR();
    irDetect.resume(); 
  }
}

void decodeIR() // Menunjukkan tombol apa yang ditekan

{

  switch(irIn.value)

  {

  case (Code0):  
    Serial.println("0"); 
    break;
    
  case (Code1):  
    Serial.println("1");
    break;

  case (Code2):  
    Serial.println("2"); 
    break;

  case (Code3):  
    Serial.println("3"); 
    break;

  case (Code4):  
    Serial.println("4"); 
    break;

  case (Code5):  
    Serial.println("5"); 
    break;

  case (Code6):  
    Serial.println("6"); 
    break;

  case (Code7):  
    Serial.println("7"); 
    break;

  case (Code8):  
    Serial.println("8"); 
    break;

  case (Code9):  
    Serial.println("9"); 
    break;

  case (CodeStar):  
    Serial.println("*"); 
    break;

  case (CodeTagar):  
    Serial.println("#"); 
    break; 
    
  case (CodeOk):  
    Serial.println("OK"); 
    break;
    
  case (CodeUp):  
    Serial.println("Atas"); 
    break;
    
  case (CpdeDown):  
    Serial.println("Bawah"); 
    break;
  
  case (CodeRight):  
    Serial.println("Kanan"); 
    break;
    
  case (CodeLeft):  
    Serial.println("Kiri"); 
    break;
    
  default: 
   break;

  }
}
