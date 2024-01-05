# B. Transmisi Data Menggunakan Protokol HTTP
   
## 1. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 2. Source Code

1. Code JSON Multi-Protocol IoT Server dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/flow%20program%20Multi-Protocol%20IoT.json">disini</a>
2. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode GET dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/transmisi_data_dummy_keNode-Red_protokol_HTTP_metode_Get/transmisi_data_dummy_keNode-Red_protokol_HTTP_metode_Get.ino">disini</a>
3. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode POST dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/Jobsheet%204/B.%20Transmisi%20Data%20Menggunakan%20Protokol%20HTTP/transmisi_data_dummy_ke_Node-Red_protokol_HTTP_metode_POST/transmisi_data_dummy_ke_Node-Red_protokol_HTTP_metode_POST.ino">disini</a>

## 3. Flow Program

![flow_job4_a](https://github.com/milham08330/Embedded-System/assets/42812745/277c7d34-bb10-488f-9626-e68acc7ddaa0)


## 4. Hasil Percobaan Transmisi Data Dummy Menuju Node-Red Menggunakan Protokol HTTP Metode GET
### Dokumentasi Percobaan

1. Flow chart

   ![flow_job4_b](https://github.com/milham08330/Embedded-System/assets/42812745/00d36b92-cded-40eb-b1b0-40c633b8a8a6)
   
2. Output serial monitor

   ![flow_job4_2](https://github.com/milham08330/Embedded-System/assets/42812745/7f29c68e-2b0f-4fe1-b5d5-e29a0bf7e7e7)
   
3. Debug Node-RED
   
   ![flow_job4_3](https://github.com/milham08330/Embedded-System/assets/42812745/f1d5cb4e-11ad-499f-bb0a-0f802294660a)

4. Dashboard Node-RED

   ![flow_job4_4](https://github.com/milham08330/Embedded-System/assets/42812745/d9c4a964-6e98-4f3d-a330-b9d243a42ed9)
   
5. Tabel database MySQL
   
   ![flow_job4_5](https://github.com/milham08330/Embedded-System/assets/42812745/1e8bb1a0-595e-4ce1-9ff0-a1568130d9a5)


### Source Code

![job4_1](https://github.com/milham08330/Embedded-System/assets/42812745/fddc467f-10c6-4c76-80b2-4fa22da2a1bf)

### Pembahasan
1. Bagian Awal:
   * Memasukkan library yang diperlukan:
     * `WiFi.h` untuk mengakses fungsi Wi-Fi.
     * `HTTPClient.h` untuk membuat permintaan HTTP.
   * Deklarasi variabel:
     * `ssid` dan `password` untuk menyimpan nama dan password Wi-Fi.
     * `serverName` untuk menyimpan alamat server yang akan dituju.
     * `lastTime` untuk menyimpan waktu terakhir pengiriman data.
     * `timerDelay` untuk mengatur interval pengiriman data (dalam milisekon).
2. Fungsi `setup()`:
   * Inisialisasi Serial Monitor:
     * `Serial.begin(115200)` untuk menampilkan pesan di Serial Monitor.
   * Menghubungkan ke Wi-Fi:
     * `WiFi.begin(ssid, password)` untuk menghubungkan board Arduino ke jaringan Wi-Fi.
   * Menunggu hingga tersambung ke Wi-Fi:
     * Program akan menunggu hingga koneksi Wi-Fi berhasil sebelum melanjutkan.
   * Menampilkan informasi IP Address:
     * Program menampilkan IP Address yang didapatkan oleh board Arduino.
     * Menginformasikan pengaturan timer:
     * Program menampilkan pesan yang menunjukkan interval pengiriman data.
3. Fungsi `loop()`:
   * Mengirim data setiap interval tertentu:
     * Program akan memeriksa apakah waktu yang telah berlalu sejak pengiriman data terakhir melebihi timerDelay. Jika iya, maka akan dilakukan pengiriman data.
   * Memeriksa status koneksi Wi-Fi:
     * Jika board Arduino masih terhubung ke Wi-Fi, maka proses pengiriman data akan dilanjutkan.
   * Membuat client HTTP:
     * `WiFiClient client` membuat objek client untuk komunikasi HTTP.
     * `HTTPClient http` membuat objek untuk melakukan permintaan HTTP.
   * Menentukan server tujuan:
     * `http.begin(client, serverName`) menetapkan server yang akan dituju untuk pengiriman data.
   * Menentukan header Content-Type:
     * `http.addHeader("Content-Type", "application/json")` menetapkan format data yang dikirimkan adalah JSON.
   *Mempersiapkan data yang akan dikirimkan:
     * String `httpRequestData` menyimpan data dalam format JSON yang akan dikirimkan. Dalam kode ini, data yang dikirimkan berupa nilai `dev_id`, `level`, `rainfall`, dan `flow`.
   * Mengirim permintaan HTTP GET:
     * `int httpResponseCode = http.GET()` mengirimkan permintaan GET ke server dengan data yang telah disiapkan.
   * Menampilkan kode respons HTTP:
     * Program menampilkan kode respons yang diterima dari server untuk mengetahui status pengiriman data.
   * Menutup koneksi HTTP:
     * `http.end()` menutup koneksi HTTP.
   * Mencatat waktu pengiriman data terakhir:
     * `lastTime = millis()` menyimpan waktu saat ini sebagai waktu terakhir pengiriman data
       
Catatan:
   * Kode ini menggunakan metode GET.
   * Interval pengiriman data diatur dalam variabel `timerDelay` (5 detik dalam kode ini).
   * Data yang dikirimkan dalam format JSON.
   * Server yang dituju adalah `http://192.168.1.7:1880/flood/node1`.

## 5. Hasil Percobaan Transmisi Data Dummy Menuju Node-Red Menggunakan Protokol HTTP Metode POST
### Dokumentasi Percobaan

1. Flow chart 

   ![flow_job4_5](https://github.com/milham08330/Embedded-System/assets/42812745/2ac52550-c68f-4789-9a7a-5c1c1a72f9db)

2. Output serial monitor
 
   ![job_4_2](https://github.com/milham08330/Embedded-System/assets/42812745/0a88dc17-1deb-48a2-81f1-80a617bc652c)
   
3. Debug Node-RED

   ![job_4_3](https://github.com/milham08330/Embedded-System/assets/42812745/211e0a70-ab89-4db0-a41b-fa91ce3acbdb)
   
4. Dashboard Node-RED
   
   ![job_4_4](https://github.com/milham08330/Embedded-System/assets/42812745/a764285f-0441-48a6-ae99-dc3367a0475f)

### Source Code

![job_4_5](https://github.com/milham08330/Embedded-System/assets/42812745/dc6dde6d-0a71-420d-b6c6-61ad260b7f92)

### Pembahasan

1. Bagian Awal:
   * Memasukkan library yang diperlukan:
     * `WiFi.h` untuk mengakses fungsi Wi-Fi.
     * `HTTPClient.h` untuk membuat permintaan HTTP.
   * Deklarasi variabel:
     * `ssid` dan `password` untuk menyimpan nama dan password Wi-Fi.
     * `serverName` untuk menyimpan alamat server yang akan dituju.
     * `lastTime` untuk menyimpan waktu terakhir pengiriman data.
     * `timerDelay` untuk mengatur interval pengiriman data (dalam milisekon).
       
2. Fungsi `setup()`:
   * Inisialisasi Serial Monitor:
     * `Serial.begin(115200)` untuk menampilkan pesan di Serial Monitor.
   * Menghubungkan ke Wi-Fi:
     * `WiFi.begin(ssid, password)` untuk menghubungkan board Arduino ke jaringan Wi-Fi.
   * Menunggu hingga tersambung ke Wi-Fi:
     * Program akan menunggu hingga koneksi Wi-Fi berhasil sebelum melanjutkan.
   * Menampilkan informasi IP Address:
     * Program menampilkan IP Address yang didapatkan oleh board Arduino.
   * Menginformasikan pengaturan timer:
     * Program menampilkan pesan yang menunjukkan interval pengiriman data.
       
3. Fungsi `loop()`:
   * Mengirim data setiap interval tertentu:
     * Program akan memeriksa apakah waktu yang telah berlalu sejak pengiriman data terakhir melebihi `timerDelay`. Jika iya, maka akan dilakukan pengiriman data.
   * Memeriksa status koneksi Wi-Fi:
     * Jika board Arduino masih terhubung ke Wi-Fi, maka proses pengiriman data akan dilanjutkan.
   * Membuat client HTTP:
     * `WiFiClient client` membuat objek client untuk komunikasi HTTP.
     * `HTTPClient http` membuat objek untuk melakukan permintaan HTTP.
   * Menentukan server tujuan:
     * `http.begin(client, serverName)` menetapkan server yang akan dituju untuk pengiriman data.
   * Menentukan header Content-Type:
     * `http.addHeader("Content-Type", "application/json")` menetapkan format data yang dikirimkan adalah JSON.
   * Mempersiapkan data yang akan dikirimkan:
     * String `httpRequestData` menyimpan data dalam format JSON yang akan dikirimkan. Dalam kode ini, data yang dikirimkan berupa nilai `dev_id`, `level`, `rainfall`, dan `flow`.
   * Mengirim permintaan HTTP POST:
     * `int httpResponseCode = http.POST(httpRequestData)` mengirimkan permintaan POST ke server dengan data yang telah disiapkan.
   * Menampilkan kode respons HTTP:
     * Program menampilkan kode respons yang diterima dari server untuk mengetahui status pengiriman data.
   * Menutup koneksi HTTP:
     * `http.end()` menutup koneksi HTTP.
   * Mencatat waktu pengiriman data terakhir:
     * `lastTime = millis()` menyimpan waktu saat ini sebagai waktu terakhir pengiriman data.
       
Catatan:
   * Kode ini menggunakan metode POST untuk mengirimkan data ke server.
   * Interval pengiriman data diatur dalam variabel `timerDelay` (5 detik dalam kode ini).
   * Data yang dikirimkan dalam format JSON.
   * Server yang dituju adalah `http://192.168.1.7:1880/flood/node1`.
   * Kode ini dapat digunakan untuk mengirimkan data sensor atau informasi lain dari board Arduino ke server secara berkala.
