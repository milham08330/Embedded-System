# C. Mengakses Sensor RFID (SPI Communication)

# 1. RFID | Cek Sensor RFID

## 1. Keterangan Singkat (Abstrak)

<p align="justify">Dalam percobaan ini program dibuat untuk dapat memahami bagaimana cara untuk mengecek kerja dari sensor RFID. Percobaan ini untuk membaca dan memverifikasi kartu RFID menggunakan modul RFID (MFRC522) dengan ESP32.

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/ea39039f-9943-4990-bec3-5044040809e7">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/c.%20Mengakses%20Sensor%20RFID%20(SPI%20Communication)/1.%20program%20contoh%20RFID/rfid_1.ino">disini</a> atau dibawah ini

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/a5a9a013-9ecb-49f9-8d79-3219afe7a1d5" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaan

![C1 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/501c3112-b488-471d-95aa-fd433f366820)

<p align="justify">Dalam praktikum ini kita dapat mengerti cara mengecek RFID. Ketika kartu RFID didekatkan ke pembaca RFID, kode identifikasi kartu RFID  muncul di layar serial monitor. Sesuaikan nilai keyTagUID dengan UID yang sebenarnya dari kartu yang diizinkan untuk mengakses.
<br></br>

# 2. RFID | Studi Kasus

## 1. Keterangan Singkat (Abstrak)

<p align="justify">Dalam percobaan ini program dibuat agar tag RFID dapat digunakan untuk mendapatkan hak akses. Dimana saat tag RFID dikenali maka LED hijau menyala dan servo bergerak kekanan. Jika tag RFID tidak dikenali maka LED merah menyala dans servo tidak bergerak.

## 2. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/a86be088-1acb-4698-bd51-42b2fe179d7c" width="600">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/c.%20Mengakses%20Sensor%20RFID%20(SPI%20Communication)/2.%20RFID%20dikenali%20maka%20LED%20hijau%20dan%20servo%20menyala/rfid___servo.ino">disini</a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/5b3258df-4ebc-49fc-a5e5-581f8bb02b37">

## 3. Hasil dan Pembahasan

### Hasil Percobaan

https://github.com/brianrahma/brian-system-embedded/assets/82065700/851cfac7-f156-44d5-ae7e-32bb988054aa

<p align="justify">Dalam praktikum ini kita dapat mengetahui program agar Tag RFID yang terbaca sebelumya dapat digunakan untuk hak akses. Apabila Tag RFID didekatkan pada Reader, maka LED Hijau akan menyala, servo akan bergerak ke kanan (lalu kembali ke posisi semula setelah 3 detik) dan di Serial Monitor akan tertampil pesan “Akses Diterima, Silahkan Masuk”. Apabila Tag RFID tidak dikenali, maka LED Merah akan menyala, servo tidak bergerak dan di Serial Monitor akan tertampil pesan “Akses Ditolak”. Gunakan Tag RFID lain untuk mencobanya.
