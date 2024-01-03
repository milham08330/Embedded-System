// AISYAH NURUL AINI               (4.31.21.0.03)
// BRIAN RAHMADITYA                (4.31.21.0.09)
// SABRINA VIRRY TALITHA MEIRILLA  (4.31.21.0.23)
// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
int touch = 4;
int baca;

void setup() {
  pinMode (touch, INPUT);
Serial.begin(115200);
delay(1000); // give me time to bring up serial monitor
Serial.println("ESP32 Touch Test");
}
void loop() {
  baca = digitalRead (touch);
Serial.println(baca); // get value of Touch 0 pin = GPIO 4
delay(1000);
}
