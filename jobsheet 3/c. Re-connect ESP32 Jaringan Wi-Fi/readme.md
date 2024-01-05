# C. Menghubungkan Kembali (Re-connect) ESP32 dengan Jaringan Wi-Fi

## 1. Rangkaian

![rangkaian](https://github.com/milham08330/Embedded-System/assets/42812745/e0f5dd52-0ae0-4f63-bab0-c55417cac145)

## 2. Source Code

```cpp
#include <WiFi.h>

// Ganti dengan kredensial jaringan Anda (STATION)
const char* ssid = "REPLACE_WITH_YOUR_SSID"; // Nama SSID WiFi Anda
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; // Kata sandi WiFi Anda

unsigned long previousMillis = 0;
unsigned long interval = 30000; // Interval (dalam milidetik) untuk mencoba kembali koneksi WiFi

// Fungsi untuk menginisialisasi koneksi WiFi
void initWiFi() {
  // Mengatur mode WiFi ke mode STA (station)
  WiFi.mode(WIFI_STA);
  
  // Memulai koneksi WiFi dengan SSID dan kata sandi yang telah ditentukan
  WiFi.begin(ssid, password);
  
  // Mencetak pesan "Connecting to WiFi .." ke Serial Monitor
  Serial.print("Connecting to WiFi ..");
  
  // Menunggu hingga koneksi WiFi terhubung
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000); // Menunggu 1 detik sebelum mencoba lagi
  }
  
  // Mencetak alamat IP lokal yang telah diperoleh
  Serial.println(WiFi.localIP());
}

void setup() {
  // Memulai komunikasi serial dengan baud rate 115200
  Serial.begin(115200);
  
  // Menginisialisasi koneksi WiFi menggunakan fungsi initWiFi()
  initWiFi();
  
  // Mencetak nilai RSSI (Received Signal Strength Indicator) ke Serial Monitor
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Jika WiFi terputus (tidak terhubung) dan sudah melewati interval yang ditentukan
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval)) {
    // Mencetak waktu saat ini dan pesan "Reconnecting to WiFi..." ke Serial Monitor
    Serial.print(millis());
    Serial.println(" Reconnecting to WiFi...");
    
    // Memutuskan koneksi WiFi yang ada
    WiFi.disconnect();
    
    // Mencoba untuk menghubungkan WiFi kembali
    WiFi.reconnect();
    
    // Memperbarui previousMillis ke waktu saat ini
    previousMillis = currentMillis;
  }
}

```


## 3. Flowchart

![flow_c](https://github.com/milham08330/Embedded-System/assets/42812745/ef5fe496-02f4-48d6-93c4-f0b9545f4708)

## 4. Hasil dan Pembahasan

 **Hasil percobaan :**


<p align="justify">Pada percobaan ini mendapatkan pengembangan dari percobaan sebelumnya yakni ESP32 sebagai client dapat re-connect atau menghubungkan kembali ke jaringan WiFi apabila koneksi terputus. Hasilnya jika koneksi WiFi terputus dan telah melewati interval yang ditentukan (30 detik), maka ESP32 akan mencoba untuk menghubungkan WiFi kembali dengan menggunakan fungsi 'WiFi.reconnect()'
