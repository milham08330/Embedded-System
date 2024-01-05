# C. Menggunakan Switch Node

## 1. Keterangan Singkat (Abstrak)

<p align="justify">Dalam percobaan ini digunakan switch node yang merupakan salah satu node yang umum digunakan di Node-RED untuk mengarahkan alur berdasarkan kondisi tertentu. Node ini dapat digunakan untuk memfilter atau membagi alur berdasarkan nilai variabel atau kondisi tertentu. Switch node disini dikonfigurasi untuk dua kondisi yakni >28 dan <=28.

## 2. Alat dan Bahan

Laptop yang terpasang Node-Red
   
## 3. Hasil dan Pembahasan

### Hasil Percobaan

![hasil_5c](https://github.com/milham08330/Embedded-System/assets/42812745/42156ade-cecd-4e22-a7b5-b48708da0f24)

<p align="justify">Pada percobaan ini output yang dihasilkan yaitu berupa data number “30” dan "27". Switch node disini digunakan untuk memisahkan aliran data menjadi dua jalur berdasarkan nilai tertentu. Switch node tersebut dirancang untuk mengarahkan aliran data (pesan) berdasarkan kondisi atau aturan yang telah tetapkan, dimana ditetapkan dua kondisi yakni >28 dan <=28. Misalnya pada inject node pertama diberikan data 30 (>28), maka data akan diarahkan ke output 1. Lalu pada inject node kedua diberikan data 27 (<=28), maka data akan diarahkan ke output 2.
