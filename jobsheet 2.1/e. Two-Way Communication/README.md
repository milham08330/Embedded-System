# E. Two-Way Communication

## 1. Pengecekan sensor DHT11

### a. Rangkaian

<img src="https://github.com/brianrahma/system-embedded/assets/82065700/5d566ac5-972f-4f71-a616-6293307b34d3" width="500">

### b. Source Code
Program ESP32 dapat dilihat <a href="https://github.com/milham08330/Embedded-System/blob/master/jobsheet%202.1/e.%20Two-Way%20Communication/1.%20program%20contoh%20pengecekan%20sensor%20DHT11/2_unit_ESP32_dan_2_unit_sensor_DHT11.ino">disini

### C. Hasil dan Pembahasan

![hasil1](https://github.com/milham08330/Embedded-System/assets/42812745/ce3cfc50-f913-40ce-9bf4-bc66e7ffecd8)

<p align="justify">Pada percobaan ini dilakukan pengecekan terhadap sensor DHT11. Pengecekan ini akan memberikan data-data seperti humidity, temperature, dan heat index yang dibaca oleh sensor DHT11.

## 2. Two-Way Communication
### a. Rangkaian

<img src="https://github.com/brianrahma/system-embedded/assets/82065700/5d566ac5-972f-4f71-a616-6293307b34d3" width="500">

### b. Source Code
Program ESP32 dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/e.%20Two-Way%20Communication/2.%20mengirim%20data%20dht11%20ke%20board%20eps32%20lain/2_unit_ESP32_dan_2_unit_sensor_DHT11_program2.ino">disini

### c. Hasil dan Pembahasan

![hasil2](https://github.com/milham08330/Embedded-System/assets/42812745/3a0bb4aa-2f88-41d7-a85a-e1ae1175721f)

<p align="justify">Pada percobaan ini dua buah ESP32 saling berkomunikasi 2 arah, yakni saling menerima dan mengirim data. Hasil pembacaan sensor DHT11 oleh ESP32 A dikirim lalu diterima oleh ESP32 B, sebaliknya hasil pembacaan sensor DHT11 oleh ESP32 B dikirim dan diterima oleh ESP32 A. Program ini menggabunngkan fungsi pengiriman dan penerimaan data serta pembacaan sensor sekaligus.


