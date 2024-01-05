# D. One-Way, Many-to-One Communication

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

1. Program ESP32 sebagai sender dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/jobsheet%202.1/d.%20One-Way,%20Many-to-One%20Communication/1.%203%20board%20diatur%20sebagai%20Sender%20dan%201%20board%20diatur%20sebagai%20receiver/receiver.ino">disini
2. Program ESP32 sebagai receiver dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/jobsheet%202.1/d.%20One-Way,%20Many-to-One%20Communication/1.%203%20board%20diatur%20sebagai%20Sender%20dan%201%20board%20diatur%20sebagai%20receiver/receiver.ino">disini

## 3. Hasil dan Pembahasan

 **Hasil percobaan :**
 
![hasil1](https://github.com/milham08330/Embedded-System/assets/42812745/9e6d1173-0d5d-40dc-94eb-cfafa547c416)

![hasil2](https://github.com/milham08330/Embedded-System/assets/42812745/e6c8e277-07a1-41c9-bb51-8903d4b535cd)

 <p align="justify">Dalam percobaan ini merupakan Many-to-One Communication, kata many menandakan banyaknya pengirim dan one berarti penerima tunggal. Dalam hal ini komunikasi berupa receiver tunggal yang menerima data dari 3 sender ESP32. Dari gambar diatas dapat dilihat bahwa receiver mendapatkan 3 buah data dari 3 sender yang ditandai dengan MAC Address sender yang berbeda-beda.


