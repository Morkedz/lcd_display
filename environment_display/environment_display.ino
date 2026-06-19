#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BMP280.h>

//read using bme280
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BMP280 bme;
const int BUZZ_PIN = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUZZ_PIN, OUTPUT);
  digitalWrite(BUZZ_PIN, HIGH);

  lcd.init();
  lcd.backlight();
  if (!bme.begin(0x77)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    lcd.print("BMP280 Error");
  }

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
  int temperature = int(bme.readTemperature());
  int pressure = int(bme.readPressure());

  Serial.print("Temperature Reading: ");
  Serial.println(temperature);
  Serial.print("Pressure Reading:");
  Serial.println(pressure);
  lcd.print(temperature);
  lcd.print(pressure);
  // condition for beep
  if(temperature > 32 || temperature < 0){
    digitalWrite(BUZZ_PIN, LOW);
  }else{
    digitalWrite(BUZZ_PIN, HIGH);
  }
  delay(500);
  
}