// include the lcd library code:
#include <LiquidCrystal.h>

// INITIALIZE THE LCD LIBRARY WITH THE NUMBERS OF THE PINS:
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

//INITIALIZE SENSORS PINS;
int in = 6;
int out = 7;

//INITIALIZE LED PINS:
int led001Pin = 8;
int led01Pin = 9;
int led1Pin = 10;
int led2Pin = 13;

//INITIALIZE COUNTER :
int count = 0;

unsigned long millis = 0;

void setup(){
    //LCD SETTINGS:
    lcd.begin(16,2);
    lcd.print("Visitor Counter");
    delay(2000);

    //DECLARE SENSORS AS INPUT:
    pinMode(in , INPUT);
    pinMode(out, INPUT);

    //DECLARE LED AS OUTPUT:
    pinMode(led001Pin, OUTPUT);
    pinMode(led01Pin , OUTPUT);
    pinMode(led1Pin  , OUTPUT);
    pinMode(led2Pin  , OUTPUT);
}
void loop(){
    //SENSORS READING:
    if(digitalRead(in)){
        count++;
    }
    if(digitalRead(out)){
        count--;
    }
    
    if (millis() - millis >= 1000) {
        // if it has been a second more, update the display
        lcd.clear();
        lcd.print(count > 0 ? "People here: " : "Nobody here");
        lcd.setCursor(0, 1);
        lcd.print(count > 0 ? str(count) : "Lights are off");
        millis = millis();
    }
    
    digitalWrite(led001Pin, count > 0);
    digitalWrite(led01Pin, count > 0);
    digitalWrite(led1Pin, count > 0);
    digitalWrite(led2Pin, count > 5);  
}
