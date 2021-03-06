#include <IRremote.h>      //including infrared remote header file
#include <LiquidCrystal.h>    //including LCD header file

#define code1  16582903   // code received from button 1
#define code2  16615543   // code received from button 2
#define code3  16580863   // code received from "power button"

LiquidCrystal lcd(12,10,7,6,5,4);

int RECV_PIN = 11;        // the pin where you connect the output pin of IR sensor 
IRrecv irrecv(RECV_PIN);
decode_results results;

int app1 = 3;         //fan pin
int app2 = 2;         //bulb pin
int status[] = {0,0,0,0};
/* the initial state of appliances is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
appliance to be ON when the board is powered */
 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);          // Start the LCD
  irrecv.enableIRIn();        // Start the IR receiver
  
  pinMode(app1, OUTPUT);
  pinMode(app2, OUTPUT);
  
  lcd.setCursor(0,0);     
  lcd.print("Made by Naman");   // Made by Naman Chauhan
  lcd.setCursor(0,1);
  lcd.print("Chauhan");
  delay(1500);
  lcd.clear();
  
  lcd.setCursor(3,0);
  lcd.print("Arduino IR");      //Arduino IR Switch Board
  lcd.setCursor(2,1);
  lcd.print("Switch Board");
  delay(1500);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("(1) Fan : OFF");     //Showing intial status on LCD
  lcd.setCursor(0,1);
  lcd.print("(2) Bulb : OFF");
  
}
 
void loop() 
{
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
      
       case code1:
         if(status[1] == 1) {           // if first app is ON then
            digitalWrite(app1, LOW);      // turn it off when button is pressed
            status[1] = 0;              // and set its state as off
            lcd.setCursor(10,0);      //printing status on LCD
            lcd.print("OFF");
          }
      
        else {                          // else if first app is OFF then
              digitalWrite(app1, HIGH);   // turn it on when the button is pressed
              status[1] = 1;            // and set its state as ON
              lcd.setCursor(10,0);    //printing status on LCD
              lcd.print("ON ");
           }
              break;
      
      
       case code2:
         if(status[2] == 1) {
            digitalWrite(app2, LOW);
            status[2] = 0;
            lcd.setCursor(11,1);      //printing status on LCD
            lcd.print("OFF");
         } 
      
        else {
              digitalWrite(app2, HIGH);
              status[2] = 1;
              lcd.setCursor(11,1);      //printing status on LCD
              lcd.print("ON ");
           }
              break;
              
       case code3:
         if(status[1] == 1 && status[2] == 1) {
            digitalWrite(app1, LOW);      
            status[1] = 0;              
            lcd.setCursor(10,0);      
            lcd.print("OFF");

            digitalWrite(app2, LOW);
            status[2] = 0;
            lcd.setCursor(11,1);      
            lcd.print("OFF");
           }

         else {
               digitalWrite(app1, HIGH);   
               status[1] = 1;            
               lcd.setCursor(10,0);    
               lcd.print("ON ");

               digitalWrite(app2, HIGH);
               status[2] = 1;
               lcd.setCursor(11,1);      
               lcd.print("ON ");
         }
      
    }
    Serial.println(value);      
    irrecv.resume();       // Receive the next value
  }
}
