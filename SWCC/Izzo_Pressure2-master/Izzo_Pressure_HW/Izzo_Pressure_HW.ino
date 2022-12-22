#include <Wire.h>
#include <LiquidCrystal_I2C.h>

unsigned int sensor = A0, button = 8, state = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
    lcd.init();
    Serial.begin(9600);
    lcd.setBacklight(HIGH);
    Serial.setTimeout(50);
    lcd.clear();
    lcd.setCursor(0, 0);
    while(!Serial){};
}

void loop()
{
    if (Serial.available())
    {
        delay(10);
        char read = 0;
        read = Serial.read();
        switch (read) //verify the command type
        {
        case 'A':
            Serial.print('O');
            break;
        case 'R':
            Serial.print(analogRead(sensor));
            break;
        default:
            Serial.print("U");
            break;
        }
        lcd.write(read);
    }
    while (Serial.available())Serial.read();
    //printdata();
}

void printdata() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TESTE !!");
    lcd.setCursor(0, 1);
    lcd.print("Aasfert");
    delay(1000);
}
