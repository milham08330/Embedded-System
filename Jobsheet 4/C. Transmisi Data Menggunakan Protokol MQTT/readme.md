# C. Transmisi Data Menggunakan Protokol MQTT

## 1. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 2. Source Code

1. Code JSON Multi-Protocol IoT Server dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/flow%20program%20Multi-Protocol%20IoT.json">disini</a>
2. Program ESP32 dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/C.%20Transmisi%20Data%20Menggunakan%20Protokol%20MQTT/program%20transmisi%20mqtt/program%20transmisi%20mqtt.ino">disini</a>


## 3. Flow Program

![flow_job4](https://github.com/milham08330/Embedded-System/assets/42812745/f0cee5a9-c8f2-4eb3-9e08-18496695bea6)

## 4. Hasil & Pembahasan
### Dokumentasi Hasil

a. Flow chart 

   ![dok_1](https://github.com/milham08330/Embedded-System/assets/42812745/31368e1e-ba1f-472c-9bf5-12e7b628e0b8)
   
b. Output serial monitor
   
   ![dok_2](https://github.com/milham08330/Embedded-System/assets/42812745/93969556-efc6-48d4-b831-2b01a6bf3985)

c. Debug Node-RED
   
   ![dok_3](https://github.com/milham08330/Embedded-System/assets/42812745/e80de707-c905-467f-8dea-4fe0f02c3075)
   
d. Dashboard Node-RED

   ![dok_4](https://github.com/milham08330/Embedded-System/assets/42812745/7439ccb6-83d2-4724-b8b0-ad233bc2e942)
   
5. Tabel database MySQL
   
   ![dok_5](https://github.com/milham08330/Embedded-System/assets/42812745/9f1e6197-f9e4-4a53-b80e-f0946401972e)


### Source Code

![code4](https://github.com/milham08330/Embedded-System/assets/42812745/d691490a-86a7-488b-8bee-cb4d3a9a8d89)

### Pembahasan
1. Bagian Awal:
   * Memasukkan library yang diperlukan:
     * `WiFi.h` untuk mengakses fungsi Wi-Fi.
     * `PubSubClient.h` untuk komunikasi MQTT.
     * `ArduinoJson.h` untuk menangani format JSON.
   * Deklarasi variabel:
     * `ssid` dan `password` untuk menyimpan nama dan password Wi-Fi.
     * `mqtt_server` untuk menyimpan alamat server MQTT.
     * `espClient` untuk membuat koneksi TCP/IP ke server MQTT.
     * `client` untuk komunikasi MQTT.

2. Fungsi `setup_wifi()`:
   * Menghubungkan board Arduino ke jaringan Wi-Fi dengan nama dan password yang telah ditentukan.
   * Menampilkan informasi IP Address yang didapatkan oleh board Arduino.
     
3. Fungsi `reconnect()`:
   * Mencoba menghubungkan board Arduino ke server MQTT.
   * Jika gagal, mencoba kembali setiap 5 detik.

4. Fungsi `setup()`:
   * Menginisialisasi Serial Monitor untuk menampilkan pesan.
   * Menghubungkan board Arduino ke Wi-Fi.
   * Mengatur server MQTT yang akan dituju

5. Fungsi loop():
   * Memeriksa apakah koneksi MQTT masih tersambung.
   * Jika terputus, memanggil fungsi `reconnect()` untuk menyambung kembali.
   * Menangani proses MQTT secara berkala.
   * Mempersiapkan data yang akan dikirimkan dalam format JSON.
   * Menerbitkan data ke topic "flood/node1" pada server MQTT.
   * Menunggu 10 detik sebelum mengirimkan data berikutnya.

Catatan:
   * Kode ini menggunakan protokol MQTT untuk mengirimkan data sensor atau informasi lain dari board Arduino ke server secara berkala.
   * Interval pengiriman data diatur dalam fungsi `loop()` (10 detik dalam kode ini).
   * Data yang dikirimkan dalam format JSON.
   * Server MQTT yang digunakan adalah `broker.hivemq.com`.
   * Kode ini dapat digunakan untuk aplikasi IoT yang membutuhkan komunikasi dua arah yang ringan dan efisien.
