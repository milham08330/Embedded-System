// AISYAH NURUL AINI               (4.31.21.0.03)
// BRIAN RAHMADITYA                (4.31.21.0.09)
// SABRINA VIRRY TALITHA MEIRILLA  (4.31.21.0.23)
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
