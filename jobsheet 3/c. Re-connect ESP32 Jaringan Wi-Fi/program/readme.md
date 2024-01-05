# C. Menghubungkan Kembali (Re-connect) ESP32 dengan Jaringan Wi-Fi

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

Program dapat dilihat <a href="https://github.com/brianrahma/brian-system-embedded/blob/master/jobsheet%203/c.%20Re-connect%20ESP32%20Jaringan%20Wi-Fi/program/Re-connect%20ESP32%20Wi-Fi.ino"> disini </a> atau dibawah ini
<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/17393c61-0c66-4b97-a746-39e79dda8431" width="800">


## 3. Flowchart

![Menghubungkan Kembali (Re-connect) ESP32 dengan Jaringan Wi-Fi](https://github.com/brianrahma/brian-system-embedded/assets/82065700/210e62c2-9e58-4541-a2be-b5aecc71dba3)

## 4. Hasil dan Pembahasan

 **Hasil percobaan :**

 ![](https://github.com/brianrahma/tahunpertama/blob/main/C%20gif.gif)

<p align="justify">Pada percobaan ini mendapatkan pengembangan dari percobaan sebelumnya yakni ESP32 sebagai client dapat re-connect atau menghubungkan kembali ke jaringan WiFi apabila koneksi terputus. Hasilnya jika koneksi WiFi terputus dan telah melewati interval yang ditentukan (30 detik), maka ESP32 akan mencoba untuk menghubungkan WiFi kembali dengan menggunakan fungsi 'WiFi.reconnect()'
