#include <Wire.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

//read using bme280

Adafruit_BME280 bme(0x76);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int BUZZ_PIN = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUZZ_PIN, OUTPUT);
  digitalWrite(BUZZ_PIN, HIGH);

  lcd.init();
  lcd.backlight();

  // Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("Temperature Read");
  lcd.setCursor(0,1);
  lcd.print("Pressure Read");
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int temperature = bme.readTemperature();
  int pressure = bme.readPressure();
  Serial.println("Temperature Reading: " + temperature);
  Serial.println("Pressure Reading: " + pressure);
  delay(500);
  
}
