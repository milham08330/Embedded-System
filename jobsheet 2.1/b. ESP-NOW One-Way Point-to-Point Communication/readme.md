# B. ESP-NOW One-Way Point-to-Point Communication

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

1. Program ESP32 sebagai sender dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/b.%20ESP-NOW%20One-Way%20Point-to-Point%20Communication/1.%20Send%20dan%20receive%20mac%20address/sendd_mac_address.ino">disini
2. Program ESP32 sebagai receiver dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/b.%20ESP-NOW%20One-Way%20Point-to-Point%20Communication/1.%20Send%20dan%20receive%20mac%20address/receive_mac_address.ino">disini
3. Program ESP32 data dummy dengan ukuran yang terbaca oleh receiver ± 250 byte dapat dilihat disini <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/b.%20ESP-NOW%20One-Way%20Point-to-Point%20Communication/2.%20data%20dummy%20250/send_mac_address.ino">disini

## 3. Hasil dan Pembahasan

### A. ANALISIS PROGRAM SENDER DAN RECEIVER
**PROGRAM SENDER**
1. Include Library dan Header
```c
#include <esp_now.h>
#include <WiFi.h>
```
>Program ini menggunakan dua library, yaitu `esp_now` untuk ESP-NOW dan `WiFi` untuk mengonfigurasi mode WiFi.
<br>

2. Inisialisasi Broadcast Address
```c
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
```
>Menginisialisasi alamat broadcast yang digunakan untuk mengirim data ke semua perangkat di jaringan.
<br>

  3. Deklarasi Struktur Pesan
```c
typedef struct struct_message {
    char a[32];
    int b;
    float c;
    bool d;
} struct_message;
```
>Mendefinisikan struktur pesan yang akan dikirim. Struktur ini memiliki empat elemen, yaitu array karakter, integer, float, dan boolean.
<br>

  4. Deklarasi Variabel dan Fungsi Callback
```c
struct_message myData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("\r\nStatus Paket Terakhir :\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Sukses Terkirim" : "Gagal Terkirim");
}
```
>Menyediakan variabel untuk menyimpan data yang akan dikirim dan struktur peer info untuk informasi penerima. Fungsi `OnDataSent` adalah callback yang dipanggil setelah data terkirim.
<br>

  5. Setup Function
```c
void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Gagal menginisialisasi ESP-NOW");
        return;
    }

    esp_now_register_send_cb(OnDataSent);

    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Gagal menambahkan peer");
        return;
    }
}
```
 > - Menginisialisasi Serial Monitor dan mode WiFi sebagai station.
 > - Menginisialisasi ESP-NOW dan mendaftarkan callback untuk meng-handle status pengiriman.
 > - Mendaftarkan alamat peer yang akan menerima data.
<br>

  6. Loop Function
```c
void loop() {
    strcpy(myData.a, "INI ADALAH CHAR");
    myData.b = random(1,20);
    myData.c = 1.2;
    myData.d = false;

    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

    if (result == ESP_OK) {
        Serial.println("Data berhasil terkirim");
    }
    else {
        Serial.println("Gagal mengirim data");
    }

    delay(2000);
}
```
 > - Mengisi data dalam struktur pesan.
 > - Mengirim data menggunakan `esp_now_send`.
 > - Menampilkan status pengiriman data melalui Serial Monitor.
 > - Menunggu selama 2 detik sebelum mengulang proses pengiriman.
Dengan demikian, program ini secara berulang mengirim data menggunakan protokol ESP-NOW ke perangkat penerima yang telah ditentukan.
<br>

**PROGRAM RECEIVER**
 1. Include Library dan Header
```c
#include <esp_now.h>
#include <WiFi.h>
```
>Seperti pada program sender, library yang digunakan adalah `esp_now` untuk ESP-NOW dan `WiFi` untuk mengonfigurasi mode WiFi.
<br>
  
  2. Deklarasi Struktur Pesan
```c
typedef struct struct_message {
    char a[32];
    int b;
    float c;
    bool d;
} struct_message;
```
>Mendefinisikan struktur pesan yang harus sama dengan struktur pesan pada program sender untuk memastikan konsistensi data yang dikirim dan diterima.
<br>
  
  3. Deklarasi Variabel dan Fungsi Callback Penerima
```c
struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    // Mengkopi data yang diterima ke dalam struktur myData
    memcpy(&myData, incomingData, sizeof(myData));

    // Menampilkan data yang diterima melalui Serial Monitor
    Serial.print("Bytes received: ");
    Serial.println(len);
    Serial.print("Char: ");
    Serial.println(myData.a);
    Serial.print("Int: ");
    Serial.println(myData.b);
    Serial.print("Float: ");
    Serial.println(myData.c);
    Serial.print("Bool: ");
    Serial.println(myData.d);
    Serial.println();
}
```
>`OnDataRecv`: Callback yang dieksekusi ketika ada data yang diterima. Menggunakan `memcpy` untuk menyalin data yang diterima ke dalam struktur `myData`. Kemudian, menampilkan informasi mengenai data yang diterima melalui Serial Monitor.
<br>
  
  4. Setup Function
```c
void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);
    
    // Set ESP32 sebagai station
    WiFi.mode(WIFI_STA);

    // Inisialisasi ESP-NOW dan mendaftarkan callback untuk proses penerimaan data
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_recv_cb(OnDataRecv);
}
```
 > - Menginisialisasi Serial Monitor dan mode WiFi sebagai station.
 > - Inisialisasi ESP-NOW dan mendaftarkan callback `OnDataRecv` untuk menangani proses penerimaan data.
<br>
  
  5. Loop Function
```c
void loop() {
    // Loop kosong, karena penerima hanya menangani data yang diterima secara asinkron.
}
```
>Loop utama tidak melakukan apa-apa karena penerima hanya menangani data yang diterima secara asinkron melalui callback.
Program ini, ketika dijalankan, akan terus mendengarkan dan menampilkan informasi mengenai data yang diterima melalui protokol ESP-NOW. Program sender yang sesuai akan mengirimkan data ke ESP32 yang berperan sebagai receiver, dan callback OnDataRecv akan dieksekusi untuk menangani data yang diterima.
<br>

### B. MEMBUAT DATA DUMMY DENGAN UKURAN YANG TERBACA OLEH RECEIVER ± 250 BYTE
Untuk membuat data dummy dengan ukuran yang terbaca oleh receiver $\pm$ 250 byte, yang harus dilakukan adalah dengan mengubah nilai `char a[]` menjadi 236
```c
typedef struct struct_message {
 char a[236];
 int b;
 float c;
 bool d;
}
```

### C. TUGAS
<p align="justify">Pada percobaan ini, pengiriman Point-to-Point dilakukan dalam beberapa kondisi. Pertama, ada 3 kondisi jarak transmisi yaitu 1 meter, 2 meter, dan 3 meter. Kemudian, pada masing-masing jarak diberikan 3 kondisi ketinggian yaitu ground, 30cm, dan 1 meter diatas permukaan tanah. Hasil pemantauan jumlah data yang berhasil terkirim dan diterima adalah sebagai berikut
   
### D. HASIL PERCOBAAN
 **SENDER**
 
 <img src="https://github.com/brianrahma/system-embedded/assets/82065700/ee92c070-9fb3-4093-9d87-cf48b8585908" width="600"><br>
 
 **RECEIVER**
 
 <img src="https://github.com/brianrahma/system-embedded/assets/82065700/d989991a-0409-4333-97ac-cb4b9c6e869c" width="600"><br>

 **DATA DUMMY DENGAN UKURAN YANG TERBACA OLEH RECEIVER ± 250 BYTE**

 <img src="https://github.com/brianrahma/system-embedded/assets/82065700/ed8bb6c4-a8fc-4ca2-b108-6fa27b39e9a9" width="600"><br>

 **TABEL PERCOBAAN PENGIRIMAN POINT-TO-POINT DALAM 3 KONDISI**
   
 <img src="https://github.com/brianrahma/system-embedded/assets/82065700/ab72bf2b-0a6c-4cae-bd10-c6600ad77533" width="600"><br>
 <p align="justify">Melalui percobaan ini dapat diketahui bahwa semakin jauh jangkauan ESP32 receiver maka delay untuk menerima data semakin besar. Berdasarkan tabel diatas dapat dilihat bahwa pengiriman paket berjalan dengan baik dalam segala kondisi. Persentase packet loss adalah 0% dengan keberhasilan pengiriman 100%.
