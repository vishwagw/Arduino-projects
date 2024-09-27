int speaker = 9; //9th pin in output of UNO
int frequency = 31000; //frequency for mosquitos
int speaker2 = 11; //11th pin in output of UNO
int frequency2 = 31000; //frequency for mosquitos
void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(speaker2, OUTPUT);
}

void loop() {
  tone(speaker, frequency, 1000);
  tone(speaker2, frequency2, 1000);

}
