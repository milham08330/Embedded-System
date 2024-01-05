// AISYAH NURUL AINI               (4.31.21.0.03)
// BRIAN RAHMADITYA                (4.31.21.0.09)
// SABRINA VIRRY TALITHA MEIRILLA  (4.31.21.0.23)
#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER'S MAC ADDRESS
uint8_t receiverAddress[] = {0xC8, 0xF0, 0x9E, 0xF5, 0x2E, 0x6C};

typedef struct test_struct1 {
  int x;
  int y;
} test_struct1;

typedef struct test_struct2 {
  float a;
  float b;
} test_struct2;

typedef struct test_struct3 {
  char message[20];
} test_struct3;

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  // Check if the received data is from the expected sender
  if (memcmp(mac_addr, receiverAddress, 6) == 0) {
    if (data_len == sizeof(test_struct1)) {
      test_struct1 *receivedData = (test_struct1 *)data;
      Serial.print("Received data1: x=");
      Serial.print(receivedData->x);
      Serial.print(", y=");
      Serial.println(receivedData->y);
    } else if (data_len == sizeof(test_struct2)) {
      test_struct2 *receivedData = (test_struct2 *)data;
      Serial.print("Received data2: a=");
      Serial.print(receivedData->a);
      Serial.print(", b=");
      Serial.println(receivedData->b);
    } else if (data_len == sizeof(test_struct3)) {
      test_struct3 *receivedData = (test_struct3 *)data;
      Serial.print("Received data3: message=");
      Serial.println(receivedData->message);
    } else {
      Serial.println("Received unknown data");
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  // Add sender as a peer
  esp_now_peer_info_t peerInfo;
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, receiverAddress, 6);

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add sender as a peer");
    return;
  }
}

void loop() {
  // The data will be received and processed in the OnDataRecv callback
  delay(1000);
}
