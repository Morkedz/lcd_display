#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); 

int i = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("LCD Display Ready");
  
  Serial.begin(9600);
}

void loop() {
  i++;
  Serial.print(i);
  delay(1000);
}