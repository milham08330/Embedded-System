// AISYAH NURUL AINI               (4.31.21.0.03)
// BRIAN RAHMADITYA                (4.31.21.0.09)
// SABRINA VIRRY TALITHA MEIRILLA  (4.31.21.0.23)
// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
const int led = 16;

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  pinMode (led, OUTPUT);
}
void loop() {
  if (touchRead(4) < 20) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
  else {
    digitalWrite(led, LOW);
  }
}
