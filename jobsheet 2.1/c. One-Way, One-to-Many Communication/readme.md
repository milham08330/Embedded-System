# C. One-Way, One-to-Many Communication

## 1. Mengirim Pesan yang Sama Ke Beberapa Board ESP32
### A. Rangkaian
<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

### B. Source Code
1. Program ESP32 sebagai sender dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/c.%20One-Way%2C%20One-to-Many%20Communication/1.%20Mengirim%20Pesan%20yang%20Sama%20Ke%20Beberapa%20Board%20ESP32/sender.ino">disini
2. Program ESP32 sebagai receiver dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/c.%20One-Way%2C%20One-to-Many%20Communication/1.%20Mengirim%20Pesan%20yang%20Sama%20Ke%20Beberapa%20Board%20ESP32/receiver.ino">disini

### C. Hasil dan Pembahasan
![J2 1 -C-1-1](https://github.com/brianrahma/system-embedded/assets/82065700/48437206-8f7a-4bdc-aa1c-5e62e8337466)

<p align="justify">Pada percobaan ini  menggunakan empat modul ESP32, di mana satu modul berperan sebagai Master/sender dan tiga modul lainnya sebagai receiver. Langkah awal memerlukan MAC Address dari tiap ESP32 yang akan menjadi receivernya, diikuti dengan memasukkan MAC address receiver pada program Master untuk mengirimkan data seragam ke setiap modul receiver. Program tersebut diunggah ke masing-masing modul, dan kemudian dilakukan pemantauan melalui Serial Monitor di Arduino IDE.

**Apabila salah satu board Receiver dimatikan**

![J2 1 -C-1-1](https://github.com/brianrahma/system-embedded/assets/82065700/6a07e44b-3b04-45fe-984e-db32e085ddab)

<p align="justify">Yang terjadi adalah komunikasi antara sender dan receiver akan terputus, artinya data yang dikirim sender tidak akan diterima oleh receiver, dan pada sender tercetak "Delivery Fail"
 
## 2. Mengirim Pesan yang Berbeda Ke Beberapa Board ESP32
### A. Rangkaian
<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

### B. Source Code
1. Program ESP32 sebagai sender dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/c.%20One-Way%2C%20One-to-Many%20Communication/2.%20Mengirim%20Pesan%20yang%20Berbeda%20Ke%20Beberapa%20Board%20ESP32/sender.ino">disini
2. Program ESP32 sebagai receiver dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/c.%20One-Way%2C%20One-to-Many%20Communication/2.%20Mengirim%20Pesan%20yang%20Berbeda%20Ke%20Beberapa%20Board%20ESP32/_receive_mac_Mengirim_Pesan_yang_Berbeda_Ke_Beberapa_Board_ESP3.ino">disini

### C. Hasil dan Pembahasan

![J2 1 -C-1-2](https://github.com/brianrahma/system-embedded/assets/82065700/a764446b-a2b5-48d5-9c07-44a05253ca96)

<p align="justify">Pada percobaan ini masih sama dengan sebelumnya, yaitu menggunakan 1 ESP yang bertindak sebagai Master/sender dan 3 ESP bertindak sebagai receiver. Perbedaannya terdapat pada data yang dikirimkan ke masing-masing receiver tidak sama. Receiver 1 akan mendapatkan data yang berisi variabel dengan tipe data integer, receiver 2 mendapatkan data variabel dengan tipe data float, dan receiver 3 mendapatkan data variabel dengan tipe data string.
