# D. Menggunakan JSON Parsing

## 1. Keterangan

<p align="justify">Dalam percobaan ini digunakan JSON node yang dapat digunakan untuk melakukan parsing (mengurai) data JSON. Di Node-RED, JSON parsing digunakan untuk mengonversi data dalam format JSON menjadi objek JavaScript atau sebaliknya.

## 2. Alat dan Bahan

Laptop yang terpasang Node-Red
   
## 3. Hasil dan Pembahasan

### Hasil Percobaan

![hasil_5d](https://github.com/milham08330/Embedded-System/assets/42812745/50e84851-c020-4832-b6f8-e441faf5e32a)

<p align="justify">Pada percobaan ini terdapat input data JSON yaitu {"temp":27,"humidity":50}. Lalu input tersebut diarahkan ke node JSON untuk mengurai payload pesan. Setelah diurai (parsing), diarahkan ke node function yang diberi program untuk mengambil nilai suhu (temp) atau nilai kelembapan (humidity) dari objek JSON yang sudah di-parse dan menetapkannya sebagai nilai baru dan diatur sebagai payload pesan. Dengan ini maka outputnya akan tampil pada node debug yakni 27 atau 50 sesuai dengan program yang ditetapkan di node function.
