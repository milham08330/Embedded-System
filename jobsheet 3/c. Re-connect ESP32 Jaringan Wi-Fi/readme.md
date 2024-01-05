# C. Menghubungkan Kembali (Re-connect) ESP32 dengan Jaringan Wi-Fi

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

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

![Menghubungkan Kembali (Re-connect) ESP32 dengan Jaringan Wi-Fi](https://github.com/brianrahma/brian-system-embedded/assets/82065700/210e62c2-9e58-4541-a2be-b5aecc71dba3)

## 4. Hasil dan Pembahasan

 **Hasil percobaan :**

 ![](https://github.com/brianrahma/tahunpertama/blob/main/C%20gif.gif)

<p align="justify">Pada percobaan ini mendapatkan pengembangan dari percobaan sebelumnya yakni ESP32 sebagai client dapat re-connect atau menghubungkan kembali ke jaringan WiFi apabila koneksi terputus. Hasilnya jika koneksi WiFi terputus dan telah melewati interval yang ditentukan (30 detik), maka ESP32 akan mencoba untuk menghubungkan WiFi kembali dengan menggunakan fungsi 'WiFi.reconnect()'
