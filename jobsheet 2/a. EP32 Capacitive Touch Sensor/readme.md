# 1. EP32 | A. Capacitive Touch Sensor

## 1. Keterangan Singkat (Abstrak)

Dalam percobaan ini program dibuat untuk dapat memahami bagaimana cara kerja protokol komunikasi yang terdapat pada ESP32 seperti UART, 12C, OneWire dan SPI dan bagaimana cara memanfaatkan tranducer sensor dan actuator untuk perangkat IoT.

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/a175edaa-7eb8-41b2-aad1-dbb8a9c13f3f" width="500">

## 3. Source Code
Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/a.%20EP32%20Capacitive%20Touch%20Sensor/1.%20program%20contoh%20touch%20test/touch_1.ino"> disini </a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/a7fa7af9-3a41-4f59-b262-d289d74a95a7" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaan

![A1 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/9c47b131-de2f-461a-8ef7-82372f1d5113)

<p align="justify">Dari praktikum ini merupakan sketsa (sketch) untuk penguji sentuhan (touch test) pada modul ESP32 menggunakan pin sentuh Touch0. Hasilnya saat kabel jumper disentuh (berfungsi sebagai sensor) maka dibaca nilai digital dan tampil pada serial monitor.
<br></br>

# 2. EP32 | LED menyala ketika Sensor disentuh

## 1. Keterangan Singkat (Abstrak)

Dalam percobaan ini program dibuat untuk dapat menghasilkan LED akan memberikan respon menyala apabila sensor disentuh().

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/a175edaa-7eb8-41b2-aad1-dbb8a9c13f3f" width="500">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/a.%20EP32%20Capacitive%20Touch%20Sensor/2.%20LED%20menyala%20ketika%20sensor%20disentuh%2C%20dan%20LED%20akan%20mati%20ketika%20sensor%20tidak%20disentuh/touch_2.ino"> disini </a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/c6c95bb7-e30f-444d-8647-563d43122433" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaan

![A2 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/cac2a02f-19f3-4078-8398-693716043600)

<p align="justify">Pada percobaan ini merupakan pengujian touch sensor dengan ditambahkan kontrol LED yang akan menyala ketika sentuhan terdeteksi. Hasilnya saat ada sentuhan maka LED akan menyala dan saat tidak ada sentuhan LED akan mati.
<br></br>

# 3. EP32 | Ketika sensor disentuh maka LED Blink akan menyala

## 1. Keterangan Singkat (Abstrak)

Dalam percobaan ini program dibuat untuk dapat melihat ketika sensor disentuh, LED akan menyala Blink dan menampilkan angka yang akan bertambah setiap kali sensor disentuh.

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/a175edaa-7eb8-41b2-aad1-dbb8a9c13f3f" width="500">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/a.%20EP32%20Capacitive%20Touch%20Sensor/3.%20ketika%20sensor%20disentuh%2C%20LED%20menyala%20Blink/touch_3.ino"> disini </a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/58c30ecc-3956-4c74-baf2-fbbc00b837d9" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaaan

![A3 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/fff6f9c0-11f3-4fad-ac58-d290e9ddfe1c)

<p align="justify">Program ini menggunakan ESP32 yang mengontol LED untuk menyala Blink ketika touch sensor disentuh. 
<br></br>

# 4. EP32 | Saat LED menyala Serial Monitor menampilkan angka yang akan bertambah setiap kali sensor disentuh

## 1. Keterangan Singkat (Abstrak)

Dalam percobaan ini program dibuat untuk menguji sentuhan pada modul ESP32 dengan menambahkan fitur penghitungan sentuhan saat LED menyala

## 2. Rangkaian

<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/a175edaa-7eb8-41b2-aad1-dbb8a9c13f3f" width="500">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/a.%20EP32%20Capacitive%20Touch%20Sensor/4.%20ketika%20LED%20menyala%20Serial%20Monitor%20menampilkan%20angka%20yang%20akan%20bertambah%20setiap%20kali%20sensor%20disentuh/touch_4.ino"> disini </a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/143daddd-db19-40c0-a695-77d3cc0cf1e1" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaan 

![A4 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/88aab4cf-7d8a-4b73-8a2a-468da4fdc2f5)

<p align="justify">Dalam percobaan ini saat touch sensor disentuh maka LED menyala dan pada Serial Monitor akan menampilkan angka yang akan bertambah setiap kali sensor disentuh.
<br></br>

# 5. EP32 | LED nyala running saat sensor disentuh

## 1. Keterangan Singkat (Abstrak)
Dalam percobaan ini digunakan 3 LED yang akan menyala running saat sensor disentuh. Jika tidak ada sentuhan yang terdeteksi, semua LED dimatikan.

## 2. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/a2ec94fc-6dae-40a9-9d52-f26ad5704a8e" width="600">

## 3. Source Code

Program dapat dilihat <a href="https://github.com/sabrinavirry/Sistem-Embedded/blob/master/jobsheet%202/a.%20EP32%20Capacitive%20Touch%20Sensor/5.%20LED%20nyala%20running%20saat%20sensor%20disentuh/touch_5.ino"> disini</a> atau dibawah ini
<img src="https://github.com/sabrinavirry/Sistem-Embedded/assets/151721571/83c476ae-a76f-447c-9ecf-2c20fee24fd4" width="800">

## 4. Hasil dan Pembahasan

### Hasil Percobaan

![A5 -GIF](https://github.com/brianrahma/brian-system-embedded/assets/82065700/7dc1c2e8-8bf7-4603-84e6-d7bd56f8a6a0)

<p align="justify">Dengan program di atas dalam percobaan ini yaitu ketika sensor disentuh, LED akan menyala menjadi running LED yang bergerak dari kiri ke kanan, kemudian kanan ke kiri secara kontinyu. Hasil output dari program ini akan menampilkan nilai sensor sentuh pada Serial Monitor. Kesimpulannya, program ini membuat 3 LED untuk menyala menjadi running LED ketika sensor disentuh.
