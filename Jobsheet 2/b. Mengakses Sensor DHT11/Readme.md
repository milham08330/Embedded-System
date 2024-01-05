# ESP32 & DHT11 1: Example
Program pertama akan digunakan untuk mencoba sensor DHT11.

## Alat dan Bahan
1. ESP32            ==> 1 buah
2. Resistor 10K ohm ==> 1 buah
3. DHT11            ==> 1 buah  

## Rangkaian

![rangkaian_job2_b1](https://github.com/milham08330/Embedded-System/assets/42812745/3fe80ff3-3bb4-4a61-bd8e-7d74d1f42892)

## Program

```cpp
// Menambahkan library DHT
#include "DHT.h"

#define DHTPIN 4            // Digital pin terhubung ke DHT sensor

// Uncomment type yang tidak digunakan
#define DHTTYPE DHT11       // DHT 11
//#define DHTTYPE DHT22     // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21     // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);       // komunikasi serial diatur ke baudrate 9600
  Serial.println(F("DHT11 Embedded System Test!"));
  dht.begin();              // memulai komunikasi dht
}
void loop() {
  // jeda antar pengukuran.
  delay(2000);
  
  // Pembacaan suhu atau kelembapan sekitar 250 milliseconds!
  float h = dht.readHumidity();
  // membaca suhu sebagai Celsius (the default)
  float t = dht.readTemperature();
  // membaca suhu sebagai Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // cek jika ada pembacaan yang salah atau gagal agar bisa memulai ulang
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Hitung heat index dalam Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Hitung heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
```

## Flowchart

![flow_job2_b1](https://github.com/milham08330/Embedded-System/assets/42812745/c31755d4-4177-4d10-bdbe-588d33edda8d)

## Hasil dan Pembahasan

https://github.com/alfan459/Embedded-System/assets/54757609/832715cd-2ba7-4708-9520-d3906ddc5ae0

Program di atas menggunakan sensor suhu dan kelembapan DHT11 untuk mengukur kondisi lingkungan. Berikut adalah penjelasan singkat mengenai kode tersebut:

Loop utama program ini melakukan pengukuran suhu dan kelembapan setiap 2 detik sekali. Hasil pembacaan kemudian ditampilkan ke Serial Monitor. Jika pembacaan gagal atau ada kesalahan, pesan kesalahan akan dicetak di Serial Monitor.
<br></br>

# ESP32 & DHT11 2: Controlling LED & Buzzer
Program kedua digunakan untuk mengatur kondisi LED dan buzzer menyala atau tidak melalui sensor DHT11.

## Alat dan Bahan
1. ESP32             ==> 1 buah
2. DHT11             ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10K ohm  ==> 1 buah 

## Rangkaian

![rangkaian_job2_b2](https://github.com/milham08330/Embedded-System/assets/42812745/a1e599cb-a995-4475-bcb3-d78588245828)

## Program

```cpp
const int led1 = 16;           // LED1 dihubungkan pada GPIO16
const int led2 = 18;            // LED2 dihubungkan pada GPIO18
const int led3 = 19;            // LED3 dihubungkan pada GPIO19
const int buzzer = 10;         // buzzer dihubungkan pada GPIO10

// Menambahkan library DHT
#include "DHT.h"

#define DHTPIN 4            // Digital pin terhubung ke DHT sensor

// Uncomment type yang tidak digunakan
#define DHTTYPE DHT11       // DHT 11
//#define DHTTYPE DHT22     // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21     // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);       // komunikasi serial diatur ke baudrate 9600
  Serial.println(F("DHT11 Embedded System Test!"));
  dht.begin();              // memulai komunikasi dht

  // inisialisasi LED sebagai output:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
}
void loop() {
  // jeda antar pengukuran.
  delay(2000);
  
  // Pembacaan suhu atau kelembapan sekitar 250 milliseconds!
  float h = dht.readHumidity();
  // membaca suhu sebagai Celsius (the default)
  float t = dht.readTemperature();
  // membaca suhu sebagai Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // cek jika ada pembacaan yang salah atau gagal agar bisa memulai ulang
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Hitung heat index dalam Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Hitung heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  // Jika suhu berada dibawah 30 derajat, maka running led:
  if(t < 30.00 || t == 30.00){
   digitalWrite(led1, HIGH);
   digitalWrite(buzzer, HIGH);
   delay(1000);
   digitalWrite(buzzer, LOW);
   delay(1000);
  }
  
  else{
    digitalWrite(buzzer, LOW);
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
}
```

## Flowchart

![flow_job2_b2](https://github.com/milham08330/Embedded-System/assets/42812745/c74ea5cf-b9ca-4e5e-a007-fe502174f7b9)

## Hasil dan Pembahasan**

https://github.com/alfan459/Embedded-System/assets/54757609/2e9c38bc-0893-4240-98a9-303b0f99527e

Program di atas menggabungkan penggunaan sensor suhu dan kelembapan DHT11 dengan kontrol LED dan buzzer berdasarkan nilai suhu yang terukur. Berikut adalah penjelasan singkat mengenai kode tersebut:

Loop utama program ini melakukan pengukuran suhu dan kelembapan setiap 2 detik sekali. Hasil pembacaan kemudian ditampilkan ke Serial Monitor. Kontrol LED dan buzzer dilakukan berdasarkan nilai suhu yang terukur. Jika suhu berada di bawah atau sama dengan 30 derajat, LED1 akan menyala dan buzzer akan berbunyi selama 1 detik. Jika tidak, akan dilakukan kontrol LED dengan pola tertentu (contoh di atas menunjukkan pola LED yang berbeda).
<br></br>
