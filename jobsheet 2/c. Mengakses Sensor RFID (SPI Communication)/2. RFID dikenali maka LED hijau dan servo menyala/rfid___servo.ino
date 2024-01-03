// AISYAH NURUL AINI               (4.31.21.0.03)
// BRIAN RAHMADITYA                (4.31.21.0.09)
// SABRINA VIRRY TALITHA MEIRILLA  (4.31.21.0.23)
#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>

#define SS_PIN 21 // ESP32 pin GIO21
#define RST_PIN 22 // ESP32 pin GIO22

MFRC522 rfid(SS_PIN, RST_PIN);
byte keyTagUID[4] = {0x71, 0xD3, 0x47, 0x27};
Servo myservo; // Menggunakan library ESP32Servo

const int greenLEDPin = 12;
const int redLEDPin = 32;

void setup() {
  Serial.begin(9600);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522
  myservo.attach(33); // Attach servo to pin 32 menggunakan library ESP32Servo
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  Serial.println("Tap RFID/NFC Tag on reader");
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(redLEDPin, LOW);
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      if (rfid.uid.uidByte[0] == keyTagUID[0] &&
          rfid.uid.uidByte[1] == keyTagUID[1] &&
          rfid.uid.uidByte[2] == keyTagUID[2] &&
          rfid.uid.uidByte[3] == keyTagUID[3]) {
        Serial.println("Access is granted");
        digitalWrite(greenLEDPin, HIGH); // Turn on green LED
        myservo.write(90); // Move servo to the right
        delay(3000); // Wait for 3 seconds
        myservo.write(0); // Move servo back to initial position
        digitalWrite(greenLEDPin, LOW); // Turn off green LED
      } else {
        Serial.print("Access denied for user with UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();
        digitalWrite(redLEDPin, HIGH); // Turn on red LED
        delay(2000); // Wait for 2 seconds
        digitalWrite(redLEDPin, LOW); // Turn off red LED
      }
      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
