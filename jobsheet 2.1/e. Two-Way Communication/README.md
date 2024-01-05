# E. Two-Way Communication

## 1. Pengecekan sensor DHT11

### a. Rangkaian

<img src="https://github.com/brianrahma/system-embedded/assets/82065700/5d566ac5-972f-4f71-a616-6293307b34d3" width="500">

### b. Source Code
Program ESP32 dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/e.%20Two-Way%20Communication/1.%20program%20contoh%20pengecekan%20sensor%20DHT11/2_unit_ESP32_dan_2_unit_sensor_DHT11.ino">disini

### C. Hasil dan Pembahasan

![JOB 4 E-1](https://github.com/brianrahma/system-embedded/assets/82065700/db2e7688-5518-4f1d-8db0-ad185bca5071)

<p align="justify">Pada percobaan ini dilakukan pengecekan terhadap sensor DHT11. Pengecekan ini akan memberikan data-data seperti humidity, temperature, dan heat index yang dibaca oleh sensor DHT11.

## 2. Two-Way Communication
### a. Rangkaian

<img src="https://github.com/brianrahma/system-embedded/assets/82065700/5d566ac5-972f-4f71-a616-6293307b34d3" width="500">

### b. Source Code
Program ESP32 dapat dilihat <a href="https://github.com/brianrahma/system-embedded/blob/master/jobsheet%202.1/e.%20Two-Way%20Communication/2.%20mengirim%20data%20dht11%20ke%20board%20eps32%20lain/2_unit_ESP32_dan_2_unit_sensor_DHT11_program2.ino">disini

### c. Hasil dan Pembahasan

![JOB 4 E-1-3](https://github.com/brianrahma/system-embedded/assets/82065700/2e498984-795f-4d76-8602-56a14146f47a)

<p align="justify">Pada percobaan ini dua buah ESP32 saling berkomunikasi 2 arah, yakni saling menerima dan mengirim data. Hasil pembacaan sensor DHT11 oleh ESP32 A dikirim lalu diterima oleh ESP32 B, sebaliknya hasil pembacaan sensor DHT11 oleh ESP32 B dikirim dan diterima oleh ESP32 A. Program ini menggabunngkan fungsi pengiriman dan penerimaan data serta pembacaan sensor sekaligus.


