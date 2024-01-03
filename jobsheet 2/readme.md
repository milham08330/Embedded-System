# Jobsheet 2 - PROTOKOL KOMUNIKASI DAN SENSOR 

<p align="justify">ESP32 adalah nama dari mikrokontroler yang dirancang oleh perusahaan yang berbasis di Shanghai, China yakni Espressif Systems. ESP32 menawarkan solusi jaringan WiFi dan BLE. ESP32 menggunakan prosesor dual core yang berjalan di instruksi Xtensa LX16. Selain itu, ESP32 telah mendukung protokol komunikasi seperti I2C, UART dan SPI. Terdapat point penting dalam percobaan kali ini, yaitu :

1. <p align="justify">UART (Universal Asynchronous Receiver Transmitter): UART adalah protokol dalam pengiriman data serial antara device satu dengan lainnya. Dalam pengiriman data, clock antara pengirim dan penerima harus sama karena paket data dikirim tiap bit mengandalkan clock tersebut.</p>
2. <p align="justify">SPI (Serial Peripheral Interface): SPI adalah protokol komunikasi serial yang memungkinkan transfer data dengan kecepatan tinggi antara mikrokontroler dan perangkat lain. Protokol ini cocok untuk aplikasi yang membutuhkan transfer data dengan kecepatan tinggi, seperti pada layar LCD atau modul memori. SPI merupakan satu mode komunikasi serial synchrounous kecepatan tinggi yang dimiliki oleh Atmega 328. Komunikasi SPI membutuhkan 3 jalur yaitu MOSI, MISO, dan SCK.</p>
3. <p align="justify">12C (Inter Integrated Circuit): I2C adalah protokol komunikasi serial yang memungkinkan beberapa perangkat terhubung ke dalam satu bus. Protokol ini cocok untuk aplikasi yang membutuhkan komunikasi antara beberapa perangkat dengan menggunakan hanya dua kabel. Bus yang digunakan untuk komunikasi antara mikrokontroler dan device lainnya seperi sensor, dll.</p>

Terdapat 3 percobaan dalam jobsheet ini yaitu :
1. <a href="https://github.com/brianrahma/brian-system-embedded/tree/master/jobsheet%202/a.%20EP32%20Capacitive%20Touch%20Sensor">EP32 Capacitive Touch Sensor
2. <a href="https://github.com/brianrahma/brian-system-embedded/tree/master/jobsheet%202/b.%20Mengakses%20Sensor%20DHT%2011%20(Single%20Wire%20%20BUS)">Mengakses Sensor DHT 11 (Single Wire  BUS)
3. <a href="https://github.com/brianrahma/brian-system-embedded/tree/master/jobsheet%202/c.%20Mengakses%20Sensor%20RFID%20(SPI%20Communication)">Mengakses Sensor RFID (SPI Communication)

## Alat dan Bahan
**Alat dan Bahan** yang digunakan dalam praktikum ini, antara lain:
1) ESP32
2) Breadboard
3) Kabel jumper
4) Sensor DHT11, RFID
5) LED (5) dan Push Button (3)
6) Servo
7) Resistor 330,1K, 10K Ohm (@ 3)

> [!NOTE]  
> *Buka folder subjob percobaan untuk melihat laporan*
