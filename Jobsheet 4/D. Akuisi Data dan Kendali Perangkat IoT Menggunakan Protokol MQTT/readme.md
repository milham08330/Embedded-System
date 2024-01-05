# D. Akuisi Data dan Kendali Perangkat IoT Menggunakan Protokol MQTT
   
## 1. Alat dan Bahan
1. Node-RED
2. ESP32
3. Kabel jumper
4. LED
5. XAMPP

## 2. Source Code

1. Code JSON Multi-Protocol IoT Server dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/flow%20program%20Multi-Protocol%20IoT.json">disini</a>
2. Program ESP32 kontrol nyala LED melalui dashboard Node-RED dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/D.%20Akuisi%20Data%20dan%20Kendali%20Perangkat%20IoT%20Menggunakan%20Protokol%20MQTT/akuisisi/akuisisi.ino">disini</a>

## 3. Flow Program

![flow4_1](https://github.com/milham08330/Embedded-System/assets/42812745/a9b25cc2-a2e2-4976-b62d-733cdc63d523)

## 4. Hasil & Penjelasan Percobaan Kontrol Nyala LED Melalui Dashboard Node-RED
### Dokumentasi Percobaan

a. Flow chart 
   
   ![flow4_2](https://github.com/milham08330/Embedded-System/assets/42812745/91a0a88e-dfbd-4875-8999-4591f2c19311)

b. Dokumentasi
   
   ![dok1](https://github.com/milham08330/Embedded-System/assets/42812745/46082cd1-d876-4eab-9e78-64b92beb2f7a)
     
   ![dok11](https://github.com/milham08330/Embedded-System/assets/42812745/a573fbb7-bc45-42cd-b3c7-0dd3636a33a2)

c. Debug Node-RED
   
   ![dok3](https://github.com/milham08330/Embedded-System/assets/42812745/99343b28-b50a-4856-b952-ea73ca4bef24)

   
d. Dashboard Node-RED

   ![dok4](https://github.com/milham08330/Embedded-System/assets/42812745/3eb2e393-ff7d-4ebb-b5c1-0713874b8bd1)
   
### Kode

![code4](https://github.com/milham08330/Embedded-System/assets/42812745/6750115b-9c65-4274-839c-f2cd0ceb7f81)

### Pembahasan
1. Bagian Awal:
   * Memasukkan library yang diperlukan:
     * `WiFi.h` untuk mengakses fungsi Wi-Fi.
     * `Adafruit_MQTT.h` dan `Adafruit_MQTT_Client.h` untuk komunikasi MQTT dengan server Adafruit IO.
   * Deklarasi variabel:
     *`WLAN_SSID`, `WLAN_PASS`, `AIO_SERVER`, `AIO_SERVERPORT`, `AIO_USERNAME`, dan `AIO_KEY` untuk konfigurasi koneksi Wi-Fi dan MQTT.
     * `output` untuk menyimpan pin output yang akan dikendalikan.
     * `client` untuk membuat koneksi TCP/IP ke server MQTT.
     * `mqtt` untuk komunikasi MQTT.
     * `led` untuk berlangganan topic "led" pada server MQTT.

2. Fungsi `setup()`:
   * Menginisialisasi Serial Monitor untuk menampilkan pesan.
   * Mengatur pin 2 sebagai output.
   * Menghubungkan board Arduino ke jaringan Wi-Fi.
   * Menampilkan informasi IP Address yang didapatkan oleh board Arduino.
   * Berlangganan topic "led" pada server MQTT.
     
3. Fungsi `loop()`:
   * Mencoba menghubungkan board Arduino ke server MQTT jika belum terhubung.
   * Membaca pesan yang diterima dari topic yang dilanggan setiap 5 detik.
   * Jika pesan diterima dari topic "led":
     * Menampilkan nilai pesan yang diterima.
     * Jika nilai pesan adalah "1", menyalakan LED pada pin 2.
     * Jika nilai pesan bukan "1", mematikan LED pada pin 2.

4. Fungsi `MQTT_connect()`:
   * Mencoba menghubungkan board Arduino ke server MQTT.
   * Jika gagal, mencoba kembali hingga maksimal 3 kali dengan jeda 5 detik.
   * Jika gagal terhubung setelah 3 kali, menghentikan program.
     
Catatan:
   * Kode ini menggunakan protokol MQTT untuk mengendalikan perangkat IoT (dalam hal ini, menyalakan dan mematikan LED) dari jarak jauh melalui server Adafruit IO.
   * Server MQTT yang digunakan adalah `io.adafruit.com`.
   * Kode ini dapat dimodifikasi untuk mengendalikan berbagai macam perangkat IoT lainnya.
