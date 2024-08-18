// To find the I2C address of your 16x2 screen follow this tutorial: 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // in most of the screen the address is 0x27

int tempPin = A0; // the output pin of LM35
int fan = 11; // the pin where fan is
int led = 8; // led pin
int temp;
int tempMin = 30; // the temperature to start the fan 0%
int tempMax = 60; // the maximum temperature when fan is at 100%
// change Above values to change the start temperature and max speed of fan
int fanSpeed;
int fanLCD;
 
 
void setup() {
pinMode(fan, OUTPUT);
pinMode(led, OUTPUT);
pinMode(tempPin, INPUT);
 lcd.init();                      // initialize the lcd 
  lcd.init();                    // Print a message to the LCD.
  lcd.backlight();
Serial.begin(9600);
}
 
void loop()
{
temp = readTemp(); // get the temperature
Serial.print( temp );
if(temp < tempMin) // if temp is lower than minimum temp
{
fanSpeed = 0; // fan is not spinning
analogWrite(fan, fanSpeed);
fanLCD=0;
digitalWrite(fan, LOW);
}
if((temp >= tempMin) && (temp <= tempMax)) // if temperature is higher than minimum temp
{
fanSpeed = temp;//map(temp, tempMin, tempMax, 0, 100); // the actual speed of fan//map(temp, tempMin, tempMax, 32, 255);
fanSpeed=1.5*fanSpeed;
fanLCD = map(temp, tempMin, tempMax, 0, 100); // speed of fan to display on LCD100
analogWrite(fan, fanSpeed); // spin the fan at the fanSpeed speed
}
 
if(temp > tempMax) // if temp is higher than tempMax
{
digitalWrite(led, HIGH); // turn on led
}
else // else turn of led
{
digitalWrite(led, LOW);
}
 
lcd.print("TEMP: ");
lcd.print(temp); // display the temperature
lcd.print("C ");
lcd.setCursor(0,1); // move cursor to next line
lcd.print("FANS: ");
lcd.print(fanLCD); // display the fan speed
lcd.print("%");
delay(200);
lcd.clear();
}
 
int readTemp() { // get the temperature and convert it to celsius
temp = analogRead(tempPin);
return temp * 0.48828125;
}