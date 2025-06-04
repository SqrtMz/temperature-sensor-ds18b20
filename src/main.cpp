#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

OneWire wire(7);
DallasTemperature sensor(&wire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp = 0.0;
String data;

void setup() {

  Serial.begin(9600);
  sensor.begin();

  lcd.init();
  lcd.backlight();
  
}

void loop() {
  
  sensor.requestTemperatures();

  temp = sensor.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(4, 1);
  lcd.print(temp);
  lcd.print(" C");

  delay(100);

}