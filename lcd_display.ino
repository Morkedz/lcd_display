#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pins for HC SR04
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

// Initialize the LCD. 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  // Configure sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize the LCD screen
  lcd.init();
  lcd.backlight();

  // Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // 10 ms pulse to trigger sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Bounce-back pulse duration
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters using conversion .0343 cm/mu second 
  //divided by 2 accounting for back and forth travel
  int distance = duration * 0.0343 / 2;

  // Display the data on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");
  lcd.setCursor(10, 0);
  
  // Out-of-range distances
  if (distance >= 400 || distance <= 0) {
    lcd.print("Out  ");
  } else {
    lcd.print(distance);
    lcd.print("cm ");
  }

  // Serial Monitor print for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait 250ms for next read
  delay(250);
}