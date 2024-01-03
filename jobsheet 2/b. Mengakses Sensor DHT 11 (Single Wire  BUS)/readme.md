# B. Mengakses Sensor DHT 11 (Single Wire / BUS)

# 1. Sensor DHT 11 | Cek Sensor DHT11

## 1. Keterangan Singkat (Abstrak)

Dalam percobaan ini program dibuat untuk dapat memahami bagaimana cara untuk memeriksa atau mengecek kerja dari sensor DHT 11.

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/5652d042-d7f5-49df-9936-d3c632b0c1c3" width="500">

## 3. Source Code
Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/tree/master/jobsheet%202/b.%20Mengakses%20Sensor%20DHT%2011%20(Single%20Wire%20%20BUS)/1.%20program%20contoh%20dht11"> disini </a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/38b89bf3-4847-4742-8be1-b4ef9607aef1" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaan

![B1 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/cb710504-b5d0-4f01-b818-27b39c142c30)

<p align="justify">Pada praktikum dibutuhkan library sensor DHT11 dan library Adafruit Sensor Unified Sensor untuk dapat menjalankan program. Hasil praktikum ini kita dapat mengerti cara mengecek Sensor DHT 11, dimana setelah mengecek kita dapat mengetahui jika sensor berfungsi dengan baik maka serial monitor akan menampilkan hasil suhu dan kelembaban sensor DHT11.
<br></br>

# 2. Sensor DHT 11 | Studi Kasus

## 1. Keterangan Singkat (Abstrak)

<p align="justify">Dalam percobaan ini program dibuat untuk dapat membuat ESP32 menyalakan LED Merah dan buzzer secara beep (blink) ketika suhu rungan mencapai 36 derajat celcius. Apabila
suhu dibawah 36 derajat, ESP32 akan mematikan buzzer dan menyalakan LED berbentuk running LED

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/81e6ab41-8a26-41bf-accc-7f17cc40bccd" width="600">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/b.%20Mengakses%20Sensor%20DHT%2011%20(Single%20Wire%20%20BUS)/2.%20saat%20suhu%20ruang%2030%20derajat%20maka%20LED%20dan%20buzzer%20nyala/dht11_2.ino"> disini </a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/d337ddd7-00ea-47f7-a29d-45dd0e05667b" width="800">

## 3. Hasil dan Pembahasan

### Hasil Percobaan

https://github.com/brianrahma/brian-system-embedded/assets/82065700/9da6b43e-101b-4a9c-b4f0-8e39c48b8924

<p align="justify">Dalam praktikum ini hasil dari tugas ini adalah ketika sensor mendeteksi peningkatan suhu. Apabila suhu dibawah 36 derajat, ESP32 akan mematikan buzzer dan menyalakan LED berbentuk running LED. Saat suhu ruangan mencapai 36 derajat Celcius, ESP32 menyalakan LED merah dan buzzer berbunyi beep. 
