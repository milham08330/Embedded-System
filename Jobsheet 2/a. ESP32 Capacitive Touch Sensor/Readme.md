# ESP32 TOUCH 1: Example
Program pertama akan digunakan untuk menampilkan pembacaan sensor touch ESP32.

## Alat dan Bahan
1. ESP32             ==> 1 buah

## Rangkaian

![rangkaian_job2_a1](https://github.com/milham08330/Embedded-System/assets/42812745/d9590fac-d005-4c5d-ad1d-6041509b2aa3)

## Program
```cpp
   void setup() {
     Serial.begin(115200);     // komunikasi serial diatur pada baudrate 115200 
     delay(1000);              // delay awal 
     Serial.println("ESP32 Touch Test");
   }
   void loop() {
     Serial.println(touchRead(4));  //mendapatkan nilai dari Touch 0 pin = GPIO 4
     delay(1000);
   }
```
## Flowchart

![flow_job2_a1](https://github.com/milham08330/Embedded-System/assets/42812745/e6522ae5-1d1b-4566-bbe3-073cf95899fd)

## Hasil dan Pembahasan

https://github.com/alfan459/Embedded-System/assets/54757609/caead734-0d30-4f79-be89-72f7cb674c8f

Program di atas merupakan program sederhana untuk menguji sensor sentuh pada ESP32. Berikut adalah penjelasan singkat mengenai kode tersebut:

Loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sentuhan pada pin Touch 0 (GPIO 4) dibaca menggunakan fungsi `touchRead(4)`. Nilai tersebut kemudian ditampilkan di Serial Monitor menggunakan `Serial.println()`. Setelah itu, program menunggu selama 1000 milidetik sebelum membaca kembali nilai sentuhan.

Program ini sederhana dan digunakan untuk memantau nilai sentuhan pada pin Touch 0 (GPIO 4) dari ESP32 dan menampilkannya di Serial Monitor setiap detik sekali. Nilai yang ditampilkan akan berupa angka analog, dan nilai yang lebih tinggi biasanya menunjukkan sentuhan yang lebih kuat.
<br></br>

# ESP32 TOUCH 2: Menyalakan LED Lewat Sensor Touch
Program kedua digunakan untuk mengatur kondisi LED menyala atau tidak melalui sensor touch ESP 32.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah

## Rangkaian

![rangkaian_job2_a1](https://github.com/milham08330/Embedded-System/assets/42812745/0032b14c-32a5-4132-ab0b-b0e63d47ecc8)

## Program
```cpp
// Mengatur pin
const int touchPin = 4;        // Pin Touch yakni di GPIO4    
const int ledPin = 16;         // Pin LED dihubungkan pada GPIO16

const int threshold = 20;      // mengatur nilai treshold 
int touchValue;                // variable untuk menympan nilai touch pin

void setup(){
  Serial.begin(115200);        // komunikasi serial diatur pada baudrate 115200 
  delay(1000);                 // delay awal 
  pinMode (ledPin, OUTPUT);    // inisialisasi LED sebagai output
}

void loop(){
  touchValue = touchRead(touchPin);    // membaca nilai touch
  Serial.print(touchValue);            // menampilkan nilai touch ke serial monitor
  
  // Jika nilai touch lebih kecil dari nilai treshold, maka lampu akan blink
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    Serial.println(" - LED Blink");
  }
  // Jika tidak, matikan lampu
  else{
    // turn LED off
    digitalWrite(ledPin, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}
```
## Flowchart

![flow_job2_a2](https://github.com/milham08330/Embedded-System/assets/42812745/a137eca0-90ec-4886-bb3e-ab7ac0a6b572)

## Hasil dan Pembahasan

![Uploading job2_2.gif…]()

Program di atas merupakan contoh penggunaan sensor sentuh pada ESP32 untuk mengontrol LED. Berikut adalah penjelasan singkat mengenai kode tersebut:


Bagian ini merupakan loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sentuhan dari pin Touch (GPIO 4) dibaca menggunakan `touchRead(touchPin)`. Nilai tersebut kemudian ditampilkan di Serial Monitor menggunakan `Serial.print()`. Jika nilai sentuhan kurang dari nilai threshold (20), maka LED (GPIO 16) akan berkedip dengan interval 1 detik, dan statusnya ditampilkan di Serial Monitor. Jika nilai sentuhan tidak mencapai threshold, LED dimatikan, dan statusnya juga ditampilkan di Serial Monitor. Setelah itu, terdapat jeda selama 500 milidetik sebelum membaca kembali nilai sentuhan.
   
<br></br>

# ESP32 TOUCH 3: LED Blink & Touchsensor
Program ini digunakan untuk menyalakan LED secara blink ketika sensor touch disentuh.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. Resistor 220 ohm  ==> 1 buah
3. LED               ==> 1 buah

## Rangkaian

![rangkaian_job2_a1](https://github.com/milham08330/Embedded-System/assets/42812745/c7cd12bc-6393-4e0c-8438-173730a677b7)

## Program

```cpp
// Mengatur pin
const int touchPin = 4;        // Pin Touch yakni di GPIO4    
const int ledPin = 16;         // Pin LED dihubungkan pada GPIO16

const int threshold = 20;      // mengatur nilai treshold 
int touchValue;                // variable untuk menympan nilai touch pin

void setup(){
  Serial.begin(115200);        // komunikasi serial diatur pada baudrate 115200 
  delay(1000);                 // delay awal 
  pinMode (ledPin, OUTPUT);    // inisialisasi LED sebagai output
}

void loop(){
  touchValue = touchRead(touchPin);    // membaca nilai touch
  Serial.print(touchValue);            // menampilkan nilai touch ke serial monitor
  
  // Jika nilai touch lebih kecil dari nilai treshold, maka nyalakan lampu
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(ledPin, HIGH);
    Serial.println(" - LED on");
  }
  // Jika tidak, matikan lampu
  else{
    // turn LED off
    digitalWrite(ledPin, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}
```
## Flowchart

![flow_job2_a3](https://github.com/milham08330/Embedded-System/assets/42812745/b4354562-1bae-440f-96ac-fb985a44f55f)

## Hasil dan Pembahasan

![job2_3](https://github.com/milham08330/Embedded-System/assets/42812745/8d92cd77-7c20-4345-af56-06c13c6459e4)

Program di atas menggunakan sensor sentuh pada pin GPIO4 dan mengontrol LED pada pin GPIO16. Berikut adalah penjelasan singkat mengenai kode tersebut:

Loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sentuhan dari pin Touch (GPIO 4) dibaca menggunakan `touchRead(touchPin)`. Nilai tersebut kemudian ditampilkan di Serial Monitor menggunakan `Serial.print()`. Jika nilai sentuhan kurang dari nilai threshold (20), maka LED (GPIO 16) akan berkedip dengan interval 1 detik, dan statusnya ditampilkan di Serial Monitor. Jika nilai sentuhan tidak mencapai threshold, LED dimatikan, dan statusnya juga ditampilkan di Serial Monitor. Setelah itu, terdapat jeda selama 500 milidetik sebelum membaca kembali nilai sentuhan.
<br></br>

# ESP32 TOUCH 4: Touchsensor Count
Program ini digunakan untuk menampilkan nilai yang terus bertambah pada serial monitor ketika touchsensor ditekan.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 ohm  ==> 1 buah

## Rangkaian

![rangkaian_job2_a1](https://github.com/milham08330/Embedded-System/assets/42812745/cd5a7745-691f-4afb-be98-0666e92d3ed2)

## Program

```cpp
const int ledPin = 2; // Pin LED
const int touchPin = 4; // Pin sensor sentuh
int touchCount = 0; // Variabel untuk menghitung sentuhan

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    // Jika sensor sentuh disentuh, tambahkan 1 ke touchCount
    touchCount++;
    
    // Hidupkan LED
    digitalWrite(ledPin, HIGH);

    // Tampilkan touchCount di Serial Monitor
    Serial.print("Sentuhan ke-");
    Serial.println(touchCount);
    
    // Tunggu sebentar untuk menghindari deteksi berulang
    delay(500);
  } else {
    // Matikan LED jika sensor tidak disentuh
    digitalWrite(ledPin, LOW);
  }
}
```

## Flowchart

![flow_job2_a4](https://github.com/milham08330/Embedded-System/assets/42812745/263fe374-81ef-437f-b28c-a02bb286d2c5)

## Hasil dan Pembahasan

https://github.com/alfan459/Embedded-System/assets/54757609/505c5c47-1b4f-40c5-8997-02c481a8cb3e

Program di atas menggunakan sensor sentuh pada pin GPIO4 dan mengontrol LED pada pin GPIO2. Berikut adalah penjelasan singkat mengenai kode tersebut:

Loop utama program yang akan terus diulang. Pada setiap iterasi loop, kondisi dari sensor sentuh (GPIO4) dibaca menggunakan `digitalRead(touchPin)`. Jika kondisi tersebut adalah `HIGH` (sensor sentuh disentuh), maka `touchCount` akan ditambah 1, LED (GPIO2) akan dinyalakan, dan informasi mengenai jumlah sentuhan akan ditampilkan di Serial Monitor. Setelah itu, terdapat jeda selama 500 milidetik untuk menghindari deteksi berulang. Jika kondisi sensor sentuh adalah `LOW` (tidak disentuh), LED dimatikan.
<br></br>

# ESP32 TOUCH 5: Touchsensor & Running LED
Program ini digunakan untuk menyalakan LED secara running dari kiri ke kanan ketika touchsensor ditekan.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. LED               ==> 3 buah
3. Resistor 220 ohm  ==> 3 buah

## Rangkaian

![rangkaian_job2_a5](https://github.com/milham08330/Embedded-System/assets/42812745/74dfc55a-121c-4150-bd92-0fc5c222be26)

## Program

```cpp
// Mengatur pin
const int touchPin = 4;        // Pin Touch yakni di GPIO4    
const int led1 = 16;           // LED1 dihubungkan pada GPIO16
const int led2 = 17;            // LED2 dihubungkan pada GPIO17
const int led3 = 18;            // LED3 dihubungkan pada GPIO18

const int threshold = 20;      // mengatur nilai treshold 
int touchValue;                // variable untuk menympan nilai touch pin

void setup(){
  Serial.begin(115200);        // komunikasi serial diatur pada baudrate 115200 
  delay(1000);                 // delay awal 
  // inisialisasi LED sebagai output:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);    
}

void loop(){
  touchValue = touchRead(touchPin);    // membaca nilai touch
  Serial.print(touchValue);            // menampilkan nilai touch ke serial monitor
  
  // Jika nilai touch lebih kecil dari nilai treshold, maka lampu akan blink
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);

    // Kanan ke Kiri
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(800);
  }
  // Jika tidak, matikan lampu
  else{
    // turn LED off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  delay(500);
}
```

## Flowchart

![flow_job2_a5](https://github.com/milham08330/Embedded-System/assets/42812745/df2f000a-dc66-46c2-a23b-c00daf9c42d6)

## Hasil dan Pembahasan

![Uploading job2_5.gif…]()

Program di atas menggunakan sensor sentuh pada pin GPIO4 dan mengontrol tiga buah LED pada pin GPIO16, GPIO17, dan GPIO18. Berikut adalah penjelasan singkat mengenai kode tersebut:

Loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai sensor sentuh (GPIO4) dibaca menggunakan `touchRead(touchPin)`. Jika nilai tersebut lebih kecil dari nilai treshold, maka akan dijalankan pola blink untuk tiga LED. Jika tidak, semua LED dimatikan. Terdapat delay sebesar 500 milidetik untuk menghindari deteksi berulang. Pola blink pada LED1, LED2, dan LED3 dapat diatur sesuai kebutuhan di dalam bagian yang ditandai sebagai `// Mengatur pola blink untuk tiga LED`.
<br></br>


