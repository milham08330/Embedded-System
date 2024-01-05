# B. Menggunakan Function Node

## 1. Keterangan 

<p align="justify">Percobaan ini menggunakan function node di Node-RED. Buat sebuah flow dengan menggabungkan inject node, function node, dan debug node. Inject node digunakan untuk mengirim pesan, function node untuk menjalankan kode JavaScript terhadap pesan, dan debug node untuk menampilkan pesan dalam sidebar Debug pada editor Node-RED.


## 2. Alat dan Bahan

Laptop yang terpasang Node-Red
   
## 3. Hasil dan Pembahasan

### Flow fungsi output tunggal

![hasil_5b_1](https://github.com/milham08330/Embedded-System/assets/42812745/1278eac6-e566-4571-90e4-2b9ff475e77f)

<p align="justify">Pada percobaan ini output yang dihasilkan yaitu berupa data string “Hello World”. Pertama adalah inject node yang membuat pesan string yang telah ditentukan yakni "Hello World". Kemudian hubungkan dengan function node, dan hubungkan lagi node tersebut dengan debug node yang mana digunakan untuk melihat output. Terakhir, deploy program dan dapat dilihat keluaran hasil debugnya.

### Flow fungsi output berganda

![hasil_5b_2](https://github.com/milham08330/Embedded-System/assets/42812745/3558e9e2-2abe-4049-b264-9235d7618b60)

<p align="justify">Pada percobaan ini output yang dihasilkan yaitu berupa data string “Hello World” dan "Expelliarmus". Function node disini dirancang untuk mengalirkan pesan dari dua Inject Node ke dua output yang berbeda. Function node tersebut dirancang untuk mengalirkan pesan dari dua Inject Node ke dua output yang berbeda. Fungsinya didasarkan pada pengecekan nilai pada properti "topic" dari pesan. Jika nilai "topic" adalah "test1", maka pesan akan dialirkan ke output pertama. Sebaliknya, jika nilai "topic" adalah "test2", pesan akan dialirkan ke output kedua. Dengan cara ini, Function Node digunakan untuk mengarahkan pesan dari Inject Node ke output yang sesuai dengan nilai "topic" yang telah ditentukan.
