# A. ESP32 Wi-Fi Modes dan Wifi-Scan

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

Program dapat dilihat <a href="https://github.com/brianrahma/brian-system-embedded/blob/master/jobsheet%203/a.%20ESP32%20Wi-Fi%20Modes%20dan%20Wifi-Scan/program/ESP32%20Wi-Fi%20Modes%20dan%20Wifi-Scan.ino"> disini </a> atau dibawah ini
<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/ac235960-d8f9-4ae1-acc6-5da18f9cdb14" width="800">

## 3. Flowchart

 ![flowchart](https://github.com/brianrahma/brian-system-embedded/assets/82065700/3114fd55-73df-4bfa-b05e-346ac04eaa67)

 ## 4. Hasil dan Pembahasan

 **Hasil percobaan :**
 
 ![A gif](https://github.com/brianrahma/brian-system-embedded/assets/82065700/6cef6d0a-9fe6-4cae-a4fb-fe42122918a4)

<p align="justify">Dalam percobaan ini ESP32 akan digunakan untuk melakukan pemindaian (scanning) jaringan WiFi di sekitar perangkat ESP32 menggunakan modul WiFi. Tujuan dari percobaan ini adalah untuk menampilkan daftar jaringan WiFi yang terdeteksi berserta dengan informasi seperti nama SSID, kekuatan sinyal (RSSI), dan apakah jaringan tersebut memiliki enkripsi (WPA/WPA2) atau tidak.

<p align="justify">Hasilnya dapat dilihat pada serial monitor, pertama akan mencetak "scan start" sebagai tanda dimulainya pemindaian. Jika tidak ada jaringan yang ditemukan, maka program akan mencetak "no networks found". Jika ada jaringan yang ditemukan, program akan mencetak daftar jaringan beserta informasinya, yaitu SSID, kekuatan sinyal, dan tanda "*" jika jaringan tersebut memiliki enkripsi. Program dalam percobaan ini akan terus berjalan secara berulang dengan interval waktu 5 detik untuk scan berikutnya.
