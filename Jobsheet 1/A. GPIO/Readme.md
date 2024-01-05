![gpio2](https://github.com/milham08330/Embedded-System/assets/42812745/08057aff-336c-4826-a68a-b8bb023f7fe0)# GPIO 1
Program pertama akan digunakan untuk membuat blink dengan interval 100ms, 1 detik, 2 detik, dan 3 detik sekali.

1. Alat dan Bahan
   * ESP32             ==> 1 buah
   * LED               ==> 1 buah
   * Resistor 220 Ohm  ==> 1 buah
   * Resistor 10k Ohm  ==> 1 buah
   * Push button       ==> 1 buah

2. Rangkaian

    ![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/3315aacb-0598-4a4e-ae46-9679b2e153fc)


3. Program
   ```cpp
    // set pin numbers
     const int buttonPin = 4; // the number of the pushbutton pin
    const int ledPin = 5; // the number of the LED pin
    // variable for storing the pushbutton status 
    int buttonState = 0;
    void setup() {
     Serial.begin(115200); 
     // initialize the pushbutton pin as an input
     pinMode(buttonPin, INPUT);
     // initialize the LED pin as an output
     pinMode(ledPin, OUTPUT);
        }
    void loop() {
     // read the state of the pushbutton value
     buttonState = digitalRead(buttonPin);
     Serial.println(buttonState);
     // check if the pushbutton is pressed.
     // if it is, the buttonState is HIGH
     if (buttonState == HIGH) {
     // turn LED on
     digitalWrite(ledPin, HIGH);
     } else {
     // turn LED off
     digitalWrite(ledPin, LOW);
           }
        }
   ```
4. Flowchart

    ![flow_job1_1](https://github.com/milham08330/Embedded-System/assets/42812745/76c92be9-0c6f-4093-b2f5-2febd8741a2b)

5. Hasil dan Pembahasan

   https://github.com/JustBadrun/Embeded_System/assets/128286595/a0d04c5c-72f7-4751-bc99-6c04fcde8f4c

    LED akan menyala dan mati dengan pola waktu tertentu. 
   - LED menyala selama 100ms dan mati selama 1 detik.
   - LED menyala selama 1 detik dan mati selama 1 detik.
   - LED menyala selama 2 detik dan mati selama 1 detik.
   - LED menyala selama 3 detik dan mati selama 1 detik.

   Pola ini akan terus berulang selama program berjalan di dalam fungsi `loop()`. Fungsi `delay()` digunakan untuk memberikan jeda waktu dalam milidetik.


<br></br>

# GPIO 2
Program pertama akan digunakan untuk membuat blink 1 detik sekali menggunakan timer milis().

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 1 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 1 buah

2. Rangkaian
   
    ![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/a463a2d8-5739-45a1-96ac-a4eb0641ea41)


4. Program
```cpp
  // mengatur posisi PIN
  const int ledPin = 5;               // LED dihubungkan pada pin GPIO 5

  // variable untuk keadaan Led
  int ledState = LOW;                 // kondisi yang akan digunakan untuk set LED
  unsigned long previousMillis = 0;   // waktu Led setelah mati
  const long interval = 1000;         // interval untuk blink (milliseconds)

  void setup() {
    pinMode(ledPin, OUTPUT);          // Menginisialisasi LED sebagai Output
    }

  void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;                     // Menyimpan waktu terakhir LED ngeblink

    // jika led dalam keadaan mati, maka nyalakan dan sebaliknya
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // atur nyala atau mati LED sesuai dengan nilai variable ledState
    digitalWrite(ledPin, ledState);
        }
  }
```
4. Flowchart
   
    ![flow_job1_2](https://github.com/milham08330/Embedded-System/assets/42812745/5ea3ec78-18ee-4a53-8452-5182e667afe2)


6. Hasil dan Pembahasan

    ![gpio2](https://github.com/milham08330/Embedded-System/assets/42812745/7572499e-0a61-4922-9783-406625d358e7)

    Kode di atas merupakan program sederhana untuk mengendalikan LED dengan menggunakan ESP32. Program ini menggunakan konsep *blinking* (nyala-mati secara bergantian) dengan menggunakan fungsi `millis()` untuk mengatur interval waktu. 

     - Jika waktu sekarang (`currentMillis`) dikurangi dengan waktu terakhir LED dimatikan (`previousMillis`) lebih besar atau sama dengan interval yang ditentukan, maka:
       - Waktu terakhir LED dimatikan (`previousMillis`) diupdate.
       - Kondisi LED (`ledState`) diubah (dari mati ke nyala atau sebaliknya).
       - LED diatur sesuai dengan kondisi terkini (`ledState`) menggunakan `digitalWrite()`.
<br></br>

# GPIO 3
Program pertama akan digunakan untuk mengendalikan LED menggunakan push button.

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 1 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 1 buah

2. Rangkaian
   
    ![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/ef829f6a-57aa-4afa-8c82-13144c9cbc08)

4. Program

   ```cpp
   // mengatur pin
    const int buttonPin = 4;    // pin 4 terhubung ke push button
    const int ledPin = 5;       // pin 5 terhubung ke LED

    // menambahkan variable untuk menyimpan keadaan pushbutton
    int buttonState = 0;

    void setup() {
      Serial.begin(115200);       // komunikasi serial diatur di 115200
      pinMode(buttonPin, INPUT);  // inisialisasi pushbutton sebagai input
      pinMode(ledPin, OUTPUT);    // inisialisasi led sebagai output
    }

    void loop() {
      buttonState = digitalRead(buttonPin);    // membaca nilai pushbutton secara digital dan menyimpannya ke variable buttonState
      Serial.println(buttonState);             // menampilkan nilai buttonState di serial monitor
  
   // Jika buttonState bernilai HIGH atau pushbutton ditekan, maka akan menyalakan led
    if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);            // menyalakan led
    } 
   // Jika tidak ditekan, maka matikan lampu
      else {
      digitalWrite(ledPin, LOW);             // mematikan led
      }
    }
   ```

6. Flowchart

    ![flow_job1_3](https://github.com/milham08330/Embedded-System/assets/42812745/6f5987c7-fb3e-46fc-9253-0b8a6970e24c)

7. Hasil dan Pembahasan

    ![gpio3](https://github.com/milham08330/Embedded-System/assets/42812745/cecc5452-51aa-4b54-8af9-24224ae0f303)

   Berdasarkan nilai `buttonState`, program memutuskan apakah push button ditekan atau tidak. Jika `buttonState` bernilai `HIGH`, artinya push button ditekan, maka program akan menyalakan LED dengan menggunakan `digitalWrite(ledPin, HIGH)`. Jika tidak ditekan, maka LED dimatikan dengan menggunakan `digitalWrite(ledPin, LOW)`.
<br></br>

# GPIO 4
Program pertama akan digunakan untuk mengendalikan LED agar blink setiap 500 ms ketika push button ke-2 ditekan.

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 2 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 2 buah

2. Rangkaian
   
    ![rangkaian_job1_4](https://github.com/milham08330/Embedded-System/assets/42812745/c65b37c7-0a2f-4987-b6ee-3f32766aa60a)

4. Program
   ```cpp
   // mengatur posisi PIN
    const int button1 = 4;  // button1 dihubungkan pada pin GPIO4
    const int button2 = 2;  // button2 dihubungkan pada pin GPIO2
    const int led1 = 5;     // LED1 dihubungkan pada pin GPIO 5
    const int led2 = 18;     // LED2 dihubungkan pada pin GPIO 18

   // variable untuk menyimpan keadaan button, 0 atau 1 
    int buttonState1 = 0;
    int buttonState2 = 0;

    // variable untuk keadaan Led
    int ledState = LOW;                // kondisi yang akan digunakan untuk set LED
    unsigned long previousMillis = 0;  // waktu Led setelah mati
    const long interval = 500;         // interval untuk blink (milliseconds)

    void setup() {
   // menginisialisasi button sebagai input
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);

    // menginisialisasi LED sebagai output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
   }

    void loop() {

    unsigned long currentMillis = millis();

    // membaca kondisi button
    buttonState1 = digitalRead(button1);
    buttonState2 = digitalRead(button2);

    // Jika button1 ditekan maka led1 akan menyala
    if (buttonState1 == HIGH) {
    digitalWrite(led1, HIGH);
    }
    // Jika tidak maka led1 akan mati
    else {
    digitalWrite(led1, LOW);
    }

    // Jika button2 ditekan maka kedua led akan blink 500ms
    if (buttonState2 == HIGH) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // Menyimpan waktu terakhir LED ngeblink

      // jika led dalam keadaan mati, maka nyalakan dan sebaliknya
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      // atur nyala atau mati LED sesuai dengan nilai variable ledState
      digitalWrite(led1, ledState);
      digitalWrite(led2, ledState);
          }
        }
      }
   ```
   
6. Flowchart

    ![flow_job1_4](https://github.com/milham08330/Embedded-System/assets/42812745/39f0580a-6432-4d30-950e-f3ddcc081e5e)

7. Hasil dan Pembahasan

    ![gpio4](https://github.com/milham08330/Embedded-System/assets/42812745/96144037-3df3-4b6a-8741-8c6b028af82f)

   program untuk mengendalikan dua LED (LED1 dan LED2) menggunakan dua push button (button1 dan button2) pada ESP32. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

   Pada setiap iterasi loop, program membaca kondisi dari button1 dan button2 menggunakan `digitalRead()`. Berdasarkan kondisi tersebut, program menyalakan atau mematikan LED1 sesuai dengan keadaan button1. Selain itu, jika button2 ditekan, kedua LED (LED1 dan LED2) akan melakukan blinking dengan interval 500ms menggunakan variabel `ledState` dan `previousMillis`.

<br></br>

# GPIO 5
Program pertama akan digunakan untuk membuat LED menyala bergantian dari kiri ke kanan ketika push button ke-3 ditekan.

1. Alat dan Bahan
    * ESP32             ==> 1 buah
    * LED               ==> 5 buah
    * Resistor 220 Ohm  ==> 1 buah
    * Resistor 10k Ohm  ==> 1 buah
    * Push button       ==> 3 buah

2. Rangkaian
   
    ![rangkaian_job1_5](https://github.com/milham08330/Embedded-System/assets/42812745/5c8fff45-929c-4e29-9d67-15309a994142)

4. Program
   ```cpp
    // mengatur posisi PIN
    const int button1 = 4;    // button1 dihubungkan pada pin GPIO4
    const int button2 = 2;  // button2 dihubungkan pada pin GPIO5
    const int button3 = 15;  // button3 dihubungkan pada pin GPIO6
    const int led1 = 5;     // LED1 dihubungkan pada pin GPIO 7
    const int led2 = 18;     // LED2 dihubungkan pada pin GPIO 8
    const int led3 = 19;     // LED3 dihubungkan pada pin GPIO 9  
    const int led4 = 21;    // LED4 dihubungkan pada pin GPIO 10
    const int led5 = 3;    // LED5 dihubungkan pada pin GPIO 11

    // variable untuk menyimpan keadaan button, 0 atau 1
    int buttonState1 = 0;
    int buttonState2 = 0;
    int buttonState3 = 0;

    // variable untuk keadaan Led
    int ledState = LOW;                // kondisi yang akan digunakan untuk set LED
    unsigned long previousMillis = 0;  // waktu Led setelah mati
    const long interval = 500;         // interval untuk blink (milliseconds)

    void setup() {
    // menginisialisasi button sebagai input
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);

    // menginisialisasi LED sebagai output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    }

    void loop() {

    unsigned long currentMillis = millis();

    // membaca kondisi button
    buttonState1 = digitalRead(button1);
    buttonState2 = digitalRead(button2);
    buttonState3 = digitalRead(button3);

    // Jika button1 ditekan maka led1 akan menyala
    if (buttonState1 == HIGH) {
    digitalWrite(led1, HIGH);
    }
    // Jika tidak maka led1 akan mati
    else {
    digitalWrite(led1, LOW);
    }

    // Jika button2 ditekan maka kedua led akan blink 500ms
    if (buttonState2 == HIGH) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // Menyimpan waktu terakhir LED ngeblink

      // jika led dalam keadaan mati, maka nyalakan dan sebaliknya
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      // atur nyala atau mati LED sesuai dengan nilai variable ledState
      digitalWrite(led1, ledState);
      digitalWrite(led2, ledState);
      }
      }  

      // Jika button3 ditekan, maka running led
      if (buttonState3 == HIGH) {
      // Kiri ke kanan
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      delay(100);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      delay(100);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      delay(100);

      // Kanan ke Kiri
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      delay(100);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      delay(100);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      delay(100);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      delay(100);
        }
      }
      ```

   
6. Flowchart

    ![flow_job1_5](https://github.com/milham08330/Embedded-System/assets/42812745/2e39846e-acc6-4d9e-8b7e-b5b83c3103cc)

7. Hasil dan Pembahasan

  ![gpio5](https://github.com/milham08330/Embedded-System/assets/42812745/68666ee5-02fc-4ee4-adbf-8d1a12ea58b2)

     program untuk mengendalikan beberapa LED (LED1 hingga LED5) menggunakan tiga push button (button1, button2, dan button3) pada platform Arduino atau mikrokontroler sejenis. Berikut adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

     loop utama program yang akan terus diulang. Pada setiap iterasi loop, program membaca kondisi dari button1, button2, dan button3 menggunakan `digitalRead()`. Berdasarkan kondisi tersebut, program menyalakan atau mematikan LED1 sesuai dengan keadaan button1. Selain itu, jika button2 ditekan, kedua LED (LED1 dan LED2) akan melakukan blinking dengan interval 500ms menggunakan variabel `ledState` dan `previousMillis`. Jika button3 ditekan, LED3, LED4, dan LED5 akan melakukan efek running dari kiri ke kanan dan dari kanan ke kiri.
