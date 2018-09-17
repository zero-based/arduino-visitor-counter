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

    //LCD DISPLAY :
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay (1000);
    
    //LED LIGHT OFF/ON:
    if(count <= 0){
        lcd.clear();
        digitalWrite(led001Pin, LOW);
        digitalWrite(led01Pin , LOW);
        digitalWrite(led1Pin  , LOW);
        lcd.clear();
        lcd.print("Nobody In Room");
        lcd.setCursor(0,1);
        lcd.print("Light Is Off");
        delay(1000);
    }
    if(count >= 1 && count <= 5){
        digitalWrite(led001Pin, HIGH);
        digitalWrite(led01Pin , HIGH);
        digitalWrite(led1Pin  , HIGH);
        digitalWrite(led2Pin  , LOW);
    }
    if(count > 5 && count <= 10){
        digitalWrite(led001Pin, HIGH);
        digitalWrite(led01Pin , HIGH);
        digitalWrite(led1Pin  , HIGH);
        digitalWrite(led2Pin  , HIGH);
    }   
}