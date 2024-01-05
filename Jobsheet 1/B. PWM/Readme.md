# PWM 1
Program pertama akan digunakan untuk membuat efek fade pada LED menggunakan PWM.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * LED               ==> 3 buah
      * Resistor 220 Ohm  ==> 3 buah

2. Rangkaian
   
   ![rangkaian_pwm](https://github.com/milham08330/Embedded-System/assets/42812745/f06fe387-2262-460d-8e81-cc7fe0a2d3c5)

4. Program

   ```cpp
   // mengatur pin yang terhubung ke LED
   const int ledPin = 16;            // LED terhubung ke pin GPIO16

   // Mengatur pengaturan PWM
   const int freq = 5000;
   const int ledChannel = 0;         //PWM Channel
   const int resolution = 8;         //resolution bit

     void setup() {
       // Mengkonfigurasi PWM LED
       ledcSetup(ledChannel, freq, resolution);

       // menghubungkan channel ke GPIO agar bisa dikendalikan
       ledcAttachPin(ledPin, ledChannel);
       pinMode(5, OUTPUT);
       digitalWrite(5, LOW);
   }

     void loop() {
       // meningkatkan cahaya LED
       for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
         // mengatur keterangan cahaya LED dengan PWM
         ledcWrite(ledChannel, dutyCycle);
         delay(15);
       }
       // mengurangi cahaya LED
       for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
         // mengatur keterangan cahaya LED dengan PWM
         ledcWrite(ledChannel, dutyCycle);
         delay(15);
       }
     }
   ```
6. Flowchart
   
   ![flow_pwm_1](https://github.com/milham08330/Embedded-System/assets/42812745/cefb8cf8-0b44-4011-b3c2-f68f924432ef)

   
7. Hasil dan Pembahasan

     ![hasil2](https://github.com/milham08330/Embedded-System/assets/42812745/fc12c53c-af0e-4b74-a07e-a194fe43c9c8)
      
     program untuk mengendalikan intensitas cahaya dari sebuah LED menggunakan modul PWM (Pulse Width Modulation) pada ESP32. Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

     Pada setiap iterasi loop, intensitas cahaya LED secara perlahan ditingkatkan dari nilai duty cycle 0 hingga 255 menggunakan loop pertama. Setelah mencapai nilai maksimum, intensitas cahaya kemudian dikurangi dari 255 hingga 0 menggunakan loop kedua. Delay 15ms diatur antara setiap perubahan nilai duty cycle untuk memberikan efek perubahan intensitas cahaya yang halus.

     Dengan menggunakan modul PWM, program ini dapat menghasilkan efek fading atau perubahan intensitas cahaya secara gradual pada LED yang terhubung ke pin GPIO16.
<br></br>

# PWM 2: Pengendalian 3 LED dengan Satu Channel PWM
Program pertama akan digunakan untuk membuat efek fade pada LED menggunakan PWM.

1. Alat dan Bahan
      * ESP32             ==> 1 buah
      * LED               ==> 3 buah
      * Resistor 220 Ohm  ==> 3 buah

2. Rangkaian

   ![rangkaian_pwm](https://github.com/milham08330/Embedded-System/assets/42812745/dab8a947-1a14-4f98-a073-f09bca232d83)

4. Program
   ```cpp
   // mengatur pin yang terhubung ke LED
     const int ledPin = 16;   // LED1 terhubung ke pin GPIO16
     const int ledPin2 = 17;  // LED2 terhubung ke pin GPIO17
     const int ledPin3 = 5;   // LED3 terhubung ke pin GPIO5

     // Mengatur pengaturan PWM
     const int freq = 5000;
     const int ledChannel = 0;  // PWM Channel
     const int resolution = 8;  // resolution bit

     void setup() {
       // Mengkonfigurasi PWM LED
       ledcSetup(ledChannel, freq, resolution);

       // menghubungkan channel ke GPIO agar bisa dikendalikan
       ledcAttachPin(ledPin, ledChannel);
       ledcAttachPin(ledPin2, ledChannel);
       ledcAttachPin(ledPin3, ledChannel);
     }
     void loop() {
       // meningkatkan cahaya LED
       for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
         // mengatur keterangan cahaya LED dengan PWM
         ledcWrite(ledChannel, dutyCycle);
         delay(15);
       }
       // mengurangi cahaya LED
       for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
         // mengatur keterangan cahaya LED dengan PWM
         ledcWrite(ledChannel, dutyCycle);
         delay(15);
            }
        }
     ```
   
6. Flowchart

   ![flow_pwm_2](https://github.com/milham08330/Embedded-System/assets/42812745/a499ff5e-5458-4868-bcd6-7591f87bd83a)

   
7. Hasil dan Pembahasan

     ![hasil1](https://github.com/milham08330/Embedded-System/assets/42812745/476bbede-9445-4f7a-ba41-8840d4dcb76e)
      
   program untuk mengendalikan intensitas cahaya dari tiga buah LED menggunakan modul PWM pada ESP32. Berikut adalah penjelasan untuk setiap bagian dari kode tersebut:

     Loop utama program yang akan terus diulang. Pada setiap iterasi loop, intensitas cahaya ketiga LED secara perlahan ditingkatkan dari nilai duty cycle 0 hingga 255 menggunakan loop pertama. Setelah mencapai nilai maksimum, intensitas cahaya kemudian dikurangi dari 255 hingga 0 menggunakan loop kedua. Delay 15ms diatur antara setiap perubahan nilai duty cycle untuk memberikan efek perubahan intensitas cahaya yang halus.

     Dengan menggunakan modul PWM, program ini dapat menghasilkan efek fading atau perubahan intensitas cahaya secara gradual pada ketiga LED yang terhubung ke pin GPIO16, GPIO17, dan GPIO5.
<br></br>
