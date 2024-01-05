# ADC DAC 1
Program pertama akan digunakan untuk menampilkan pembacaan potensio.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * Potensio 10k Ohm  ==> 1 buah

2. Rangkaian
   
   ![rangkaian_adc_1](https://github.com/milham08330/Embedded-System/assets/42812745/38ef8233-05a8-4af5-9b84-0aa78445bf20)

4. Program
   ```cpp
   // Potentiometer terhubung ke GPIO34 (Analog ADC1_CH6)
     const int potPin = 34;

     // variable untuk menyimpan nilai potensiometer
        int potValue = 0;
        void setup() {
          Serial.begin(115200);           // Serial diatur di baudrate 115200
       delay(1000);                    // jeda waktu pertama kali
     }
     void loop() {
  
       // Membaca nilai potensiometer
       potValue = analogRead(potPin);
       Serial.println(potValue);       // Menampilkan nilai potensio ke serial monitor
       delay(500);
     }
   ```
   
5. Flowchart

   ![flow_adc_1](https://github.com/milham08330/Embedded-System/assets/42812745/52f10e1b-4500-493e-a6f8-1547e0ff34fd)

7. Hasil dan Pembahasan

      ![ADC DAC 1](https://github.com/alfan459/Embedded-System/assets/54757609/67c66308-4865-4563-86f5-7198c5c76a53)

      Program ESP32 di atas membaca nilai analog dari potensiometer yang terhubung ke pin GPIO34 (Analog ADC1_CH6) dan menampilkan nilai tersebut ke Serial Monitor setiap 500 milidetik. Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

   loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai analog dari potensiometer dibaca menggunakan `analogRead(potPin)`. Nilai tersebut kemudian ditampilkan ke Serial Monitor dengan `Serial.println(potValue)`. Delay 500 milidetik (`delay(500)`) diatur antara setiap pembacaan nilai untuk memberikan interval waktu antar bacaan dan mencegah tampilan nilai yang terlalu cepat di Serial Monitor.

     Dengan cara ini, program tersebut memungkinkan pengguna untuk melihat nilai pembacaan analog dari potensiometer pada Serial Monitor secara real-time.


<br></br>

# ADC DAC 2: mengatur cahaya LED menggunakan potensio.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * LED               ==> 1 buah
      * Resistor 220 Ohm  ==> 1 buah
      * Potensio 10k Ohm  ==> 1 buah

2. Rangkaian
   
   ![rangkaian_adc_2](https://github.com/milham08330/Embedded-System/assets/42812745/0012cc76-1dd0-42d8-9374-327b72bc7054)

4. Program
   ```cpp
   #include <Arduino.h>
   #include <analogWrite.h>

     const int analogInPin = 34;       // Analog input pin dimana potentiometer akan terhubung
     const int analogOutPin = 5;       // Analog output pin dimana LED akan terhubung

     // mengatur pengaturan PWM
     const int freq = 5000;
     const int ledChannel = 0;         // PWM channel
     const int resolution = 8;         // resolution

     int sensorValue = 0;
     int outputValue = 0;

     void setup() {
       // membaca nilai potensio
       // nilai output akan dikirimkan ke AnalogOut
  
       Serial.begin(115200);           // komunikasi serial diatur pada baudrate 115200
  
       // mengkonfigurasi LED PWM
       ledcSetup(ledChannel, freq, resolution);
  
       // menghubungkan Channel ke GPIO untuk dihubungkan
       ledcAttachPin(analogOutPin, ledChannel);
   }

     void loop() {
       sensorValue = analogRead(analogInPin);            // membaca nilai analog
       outputValue = map(sensorValue, 0, 4095, 0, 255);  // map untuk range nilai analog
       analogWrite(analogOutPin, outputValue);           // atur nilai analogOut

       // tampilkan hasilnya ke serial monitor
       Serial.print("sensor = ");
       Serial.print(sensorValue);
       Serial.print("\t output = ");
       Serial.println(outputValue);
  

       // tunggu 2 miliseconds sebelum loop selanjutnya untuk ADC
       delay(2);
     }
   ```
   
6. Flowchart
   
   ![flow_adc_2](https://github.com/milham08330/Embedded-System/assets/42812745/6b7d5c5c-5ce0-453c-b6f4-a7b310d800b4)

7. Hasil dan Pembahasan

      ![ADC DAC 2](https://github.com/alfan459/Embedded-System/assets/54757609/7e356dc6-fb4c-4f21-99e2-f1f4b3849738)

      Program ESP32 di atas membaca nilai analog dari potensiometer yang terhubung ke pin GPIO34 dan mengirimkan nilai tersebut ke LED yang terhubung ke pin GPIO5 menggunakan modul PWM (Pulse Width Modulation). Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

      Loop utama program yang akan terus diulang. Pada setiap iterasi loop, nilai analog dari potensiometer dibaca menggunakan `analogRead(analogInPin)`. Nilai tersebut kemudian diubah menggunakan `map` untuk sesuaikan dengan rentang PWM (0-255), dan nilai PWM tersebut diatur pada LED menggunakan `analogWrite(analogOutPin, outputValue)`. Selain itu, hasil bacaan dan keluaran ditampilkan di Serial Monitor. Diberikan jeda 2 milidetik (`delay(2)`) sebelum pembacaan berikutnya untuk ADC.

<br></br>


