//include libraries
#include <DHT.h>;
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;

#define DHTPIN A0
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);
//#define I2C_ADDR 0x27
//#define BACKLIGHT_PIN A5

//define veriables
int chk;
float humd;
float temp;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("Booting Up");
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,1);
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  //reading the data from DHT sensor
  humd = dht.readHumidity();
  temp = dht.readTemperature();
  //printing the input data to serial monitor in computer
  Serial.print("Humidity: ");
  Serial.print(humd);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  //print the input data in LCD
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(humd);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp: "); 
  lcd.print(temp);
  lcd.println("Celsius");
  delay(2000); //2000= 2sec delay update

}
