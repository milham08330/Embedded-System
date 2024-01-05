# D. Mengganti Hostname ESP32

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

Program dapat dilihat <a href="https://github.com/brianrahma/brian-system-embedded/blob/master/jobsheet%203/d.%20Mengganti%20Hostname%20ESP32/program/Mengganti%20Hostname%20ESP32.ino"> disini </a> atau dibawah ini
<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/0fe97a3f-c461-4787-9fa7-2d0fea2ecc96" width="800">

## 3. Flowchart

![Mengganti Hostname ESP32](https://github.com/brianrahma/brian-system-embedded/assets/82065700/e07dcb5f-40ee-4ab6-8fac-d9cc19aee2c2)

## 4. Hasil dan Pembahasan

 **Hasil percobaan :**
 
![D gif](https://github.com/brianrahma/brian-system-embedded/assets/82065700/6efe61bb-4b97-4a25-84f8-cba396d183f9)

<p align="justify">Pada percobaan ini ESP32 akan terhubung dengan WiFi yang SSID dan kata sandinya telah diatur, serta mengatur dan menetapkan sebuah hostname khusus. Hasil dari percobaan ini dapat dilihat pada serial monitor, dapat dilihat disitu akan tampil alamat IP yang diperoleh, nilai RSSI, dan hostname baru yang telah ditetapkan sebelumnya menggunakan fungsi  `WiFi.getHostname()`.
