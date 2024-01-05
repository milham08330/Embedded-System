# F. Pertanyaan dan Tugas

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/3876402d-90d7-48ed-95bc-ce86d775035d" alt="Girl in a jacket" width="500">

## 2. Source Code

Program dapat dilihat <a href="https://github.com/brianrahma/brian-system-embedded/blob/master/jobsheet%203/f.%20pertanyaan%20dan%20tugas/program/TUGAS_REAL.ino"> disini </a>

## 3. Hasil dan Pembahasan

 **Hasil percobaan :**
 
 Klik <a href="https://www.youtube.com/watch?v=lyHdP0j-NWQ">video</a> dibawah
[![Watch the video](https://img.youtube.com/vi/lyHdP0j-NWQ/maxresdefault.jpg)](https://www.youtube.com/watch?v=lyHdP0j-NWQ)

 
 <p align="justify">Tugas dalam percobaan ini adalah membuat program pada ESP32 dengan beberapa ketentuan yang diberikan terkait dengan ESP32 sebagai station mode. Hasil yang saya peroleh pertama yakni saat pertama kali booting, ESP32 dalam mode station (STA) dimana akan membaca SSID dan password pada jaringan sebelumnya. Tetapi karena ESP32 gagal terhubung ke jaringan maka ESP32 berubah menjadi mode Access Point yang membuat jaringan WiFi tanpa enkripsi supaya user dapat langsung terhubung. Kemudian saya hubungkan laptop dengan jaringan WiFi tersebut, kemudian akses IP address ESP32 atau ESP32 Web Server (IP dapat dilihat di serial monitor) pada browser untuk selanjutnya membuat konfigurasi SSID dan Password dan menyimpannya pada EEPROM. EEPROM digunakan untuk menyimpan SSID (nama jaringan Wi-Fi) dan Password. Data ini dapat diakses bahkan setelah ESP32 dimatikan dan dihidupkan kembali, sehingga tidak perlu mengonfigurasi ulang setiap kali daya dipulihkan.
  
  <p align="justify">Hasil selanjutnya yakni memutus koneksi ESP32, disini saya menggunakan bantuan push button untuk memutus koneksi. Lalu ESP32 akan mencoba terhubung kembali dengan jaringan yang telah dikonfigurasi sebelumnya dan hasilnya pada serial monitor akan terdapat pesan "Connected to “SSID” Successfully" yang menandakan jika berhasil terhubung. Terakhir jika gagal terhubung maka hasilnya ESP32 akan menjadi mode Access Point kembali.
