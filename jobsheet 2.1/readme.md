# JOBSHEET 2.1 - JARINGAN SENSOR NIRKABEL MENGGUNAKAN ESP-NOW

## Abstrak
<p align="justify">ESP-NOW adalah protokol komunikasi tanpa Wi-Fi yang dikembangkan oleh Espressif untuk ESP32. Protokol ini memungkinkan perangkat saling berkomunikasi pada frekuensi 2.4GHz 
dengan konfigurasi awal menggunakan alamat MAC. Setelah terpasang, jaringan peer-to-peer terbentuk, memungkinkan koneksi tetap ada tanpa perlu melakukan handshaking ulang. 
Jika salah satu perangkat ESP32 mati atau diatur ulang, koneksi otomatis dipulihkan saat restart ke perangkat pasangannya yang telah ditentukan alamatnya.</p>

<p align="justify">Jobsheet ini bertujuan untuk memahami konsep topologi jaringan sensor nirkabel berbasis ESP-NOW, melakukan konfigurasi berbagai topologi ESP-NOW, dan menganalisis dan menentukan topologi ESP-NOW,sesuai dengan
studi kasus proyek.</p>

Terdapat 5 percobaan pada jobsheet ini, antara lain:
1. <a href="https://github.com/brianrahma/system-embedded/tree/master/jobsheet%202.1/a.%20Memperoleh%20MAC%20Address%20ESP32%20Receiver/1.%20Memperoleh%20MAC%20Address%20ESP32%20Receiver">Memperoleh MAC Address ESP32 Receiver
2. <a href="https://github.com/brianrahma/system-embedded/tree/master/jobsheet%202.1/b.%20ESP-NOW%20One-Way%20Point-to-Point%20Communication">ESP-NOW One-Way Point-to-Point Communication
3. <a href="https://github.com/brianrahma/system-embedded/tree/master/jobsheet%202.1/c.%20One-Way%2C%20One-to-Many%20Communication">One-Way, One-to-Many Communication
4. <a href="https://github.com/brianrahma/system-embedded/tree/master/jobsheet%202.1/d.%20One-Way%2C%20Many-to-One%20Communication/1.%203%20board%20diatur%20sebagai%20Sender%20dan%201%20board%20diatur%20sebagai%20receiver">One-Way, Many-to-One Communication
5. <a href="https://github.com/brianrahma/system-embedded/tree/master/jobsheet%202.1/e.%20Two-Way%20Communication">Two-Way Communication

## Alat dan Bahan
**Alat dan Bahan** yang digunakan dalam praktikum ini, antara lain:
1) ESP32
2) Breadboard
3) Kabel jumper
4) Resistor 10K Ohm
5) Sensor DHT11

> [!NOTE]  
> *Buka folder-folder subjob untuk melihat laporan percobaan*
