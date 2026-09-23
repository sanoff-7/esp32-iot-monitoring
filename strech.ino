#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHT_PIN 23
#define DHT_TYPE DHT22

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if(isnan (temperature) || isnan (humidity)){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("error!");
   }else{
      lcd.setCursor(0,0);
      lcd.print("temp: ");
      lcd.print(temperature, 1);
      lcd.setCursor(0, 1);
      lcd.print("Humi: ");
      lcd.print(humidity, 1);
   }  
  delay(2000);
}
