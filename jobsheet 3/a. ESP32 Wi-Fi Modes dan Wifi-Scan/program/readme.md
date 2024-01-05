# A. ESP32 Wi-Fi Modes dan Wifi-Scan

## 1. Rangkaian

![rangkaian](https://github.com/milham08330/Embedded-System/assets/42812745/156a362f-a2c8-4d84-af9c-24e99dff72e4)

## 2. Source Code
```cpp
#include "WiFi.h"

void setup() {
  // Memulai komunikasi serial dengan baud rate 115200
  Serial.begin(115200);
  
  // Mengatur mode WiFi ke mode STA (station) dan memutuskan koneksi jika sudah terhubung sebelumnya
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  // Mencetak pesan setup selesai ke Serial Monitor
  Serial.println("Setup done");
}

void loop() {
  // Mencetak pesan "scan start" ke Serial Monitor
  Serial.println("scan start");
  
  // WiFi.scanNetworks akan mengembalikan jumlah jaringan yang ditemukan
  int n = WiFi.scanNetworks();
  
  // Mencetak pesan "scan done" ke Serial Monitor
  Serial.println("scan done");
  
  if (n == 0) {
    // Mencetak pesan "no networks found" jika tidak ada jaringan yang ditemukan
    Serial.println("no networks found");
  } else {
    // Mencetak jumlah jaringan yang ditemukan
    Serial.print(n);
    Serial.println(" networks found");
    
    for (int i = 0; i < n; ++i) {
      // Mencetak SSID dan RSSI untuk setiap jaringan yang ditemukan
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      
      // Mencetak tanda "*" jika jaringan memiliki enkripsi (WPA/WPA2)
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      
      // Menambahkan delay 10ms
      delay(10);
    }
  }
  
  // Mencetak baris kosong untuk memisahkan hasil pemindaian
  Serial.println("");
  
  // Menunggu 5 detik sebelum melakukan pemindaian lagi
  delay(5000);
}
```

## 3. Flowchart

![flow_a](https://github.com/milham08330/Embedded-System/assets/42812745/879b41ef-6dca-44d8-96a0-ad7d86f16c6b)

 ## 4. Hasil dan Pembahasan

 **Hasil percobaan :**
 
![Uploading hasil_a.gif…]()

<p align="justify">Dalam percobaan ini ESP32 akan digunakan untuk melakukan pemindaian (scanning) jaringan WiFi di sekitar perangkat ESP32 menggunakan modul WiFi. Tujuan dari percobaan ini adalah untuk menampilkan daftar jaringan WiFi yang terdeteksi berserta dengan informasi seperti nama SSID, kekuatan sinyal (RSSI), dan apakah jaringan tersebut memiliki enkripsi (WPA/WPA2) atau tidak.

<p align="justify">Hasilnya dapat dilihat pada serial monitor, pertama akan mencetak "scan start" sebagai tanda dimulainya pemindaian. Jika tidak ada jaringan yang ditemukan, maka program akan mencetak "no networks found". Jika ada jaringan yang ditemukan, program akan mencetak daftar jaringan beserta informasinya, yaitu SSID, kekuatan sinyal, dan tanda "*" jika jaringan tersebut memiliki enkripsi. Program dalam percobaan ini akan terus berjalan secara berulang dengan interval waktu 5 detik untuk scan berikutnya.
