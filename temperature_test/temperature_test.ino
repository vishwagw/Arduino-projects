void setup() {
  // Begin serial communication at 9600 baud rate:
  serial.begin(9600);

}

void loop() {
  // Getting the outpur reading from sensor:
  int reading = analogRead(sensorPin)

  // Converting the output reading to voltage:
  float voltage = reading * (5.0 / 1024.0);
  Serial.print("Volatage: ");
 Serial.print/in(voltage);
  Serial.print("ADC VALUE: ");
 Serial.printIn(reading);

  // converting the voltage to tamperature in Celsius:
  float tempC = volatage * 100;

  // printing the tempreture:
  Serial.print("Temperature: ");
  Serial.print(TemperatureC);
  Serial.print("\xC2\xB0"); //This is for showing the degree symbol
  Serial.print("C");
 Serial.print("  ");
  delay(1000); // for the time delay between reading 
}
