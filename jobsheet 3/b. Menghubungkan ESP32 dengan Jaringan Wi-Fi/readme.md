# B. Menghubungkan ESP32 dengan Jaringan Wi-Fi

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

```cpp
#include <WiFi.h>

// Ganti dengan kredensial jaringan Anda (STATION)
const char* ssid = "P"; // Nama SSID WiFi Anda
const char* password = "12345678"; // Kata sandi WiFi Anda

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
  // Kode utama Anda akan berjalan berulang kali di sini
  // Anda dapat menambahkan perintah-perintah yang diperlukan di dalam loop ini
}
```


## 3. Flowchart

![flow_a](https://github.com/milham08330/Embedded-System/assets/42812745/2767a81e-a745-4fd7-bfd1-38b264a098cd)


## 4. Hasil dan Pembahasan

 **Hasil percobaan :**
 
![hasil_a](https://github.com/milham08330/Embedded-System/assets/42812745/cb949224-eaa1-47fe-b4dd-ce6fb54fd477)

<p align="justify">Pada percobaan ini ESP32 digunakan sebagai client yang terhubung ke jaringan WiFi yang telah ditentukan SSID dan passwordnya pada program. Hasil dari percobaan ini adalah terbentuknya koneksi WiFi antara perangkat ESP32 (client) dan jaringan WiFi yang ditentukan, dengan informasi koneksi yang ditampilkan di Serial Monitor yaitu alamat IP lokal dan nilai RSSI. Nilai RSSI memberikan indikasi kekuatan sinyal WiFi yang diterima, dan ini dapat memberikan informasi tentang seberapa baik atau buruk kualitas koneksi WiFi.</p>
<br>
