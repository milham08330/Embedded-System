#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t broadcastAddress1[] = {0xC8, 0xF0, 0x9E, 0xF4, 0x32, 0x7C};
uint8_t broadcastAddress2[] = {0xC8, 0xF0, 0x9E, 0xF4, 0x4D, 0xD0};
uint8_t broadcastAddress3[] = {0xC8, 0xF0, 0x9E, 0xF5, 0x3B, 0xAC};

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

test_struct1 data1;
test_struct2 data2;
test_struct3 data3;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4],
           mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);

  // register first peer
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer 1");
    return;
  }

  // register second peer
  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer 2");
    return;
  }

  // register third peer
  memcpy(peerInfo.peer_addr, broadcastAddress3, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer 3");
    return;
  }
}

void loop() {
  // Generate random data for each struct
  data1.x = random(0, 20);
  data1.y = random(0, 20);

  data2.a = random(0.0, 1.0);
  data2.b = random(0.0, 1.0);

  snprintf(data3.message, sizeof(data3.message), "Hello %d", random(1, 10));

  // Send data to each receiver
  esp_err_t result1 = esp_now_send(broadcastAddress1, (uint8_t *)&data1, sizeof(test_struct1));
  if (result1 == ESP_OK) {
    Serial.println("Sent data1 with success");
  } else {
    Serial.println("Error sending data1");
  }

  esp_err_t result2 = esp_now_send(broadcastAddress2, (uint8_t *)&data2, sizeof(test_struct2));
  if (result2 == ESP_OK) {
    Serial.println("Sent data2 with success");
  } else {
    Serial.println("Error sending data2");
  }

  esp_err_t result3 = esp_now_send(broadcastAddress3, (uint8_t *)&data3, sizeof(test_struct3));
  if (result3 == ESP_OK) {
    Serial.println("Sent data3 with success");
  } else {
    Serial.println("Error sending data3");
  }

  delay(2000);
}
