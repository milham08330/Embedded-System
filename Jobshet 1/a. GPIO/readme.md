<h1 align="">GPIO 1</h1>
<h1 align="">A. Program pertama akan digunakan untuk membuat blink dengan interval 100ms, 1 detik, 2 detik, dan 3 detik sekali.</h1>

<h3>1. Alat dan Bahan</h3>
ESP32 ==> 1 buah
LED ==> 1 buah
Resistor 220 Ohm ==> 1 buah
Resistor 10k Ohm ==> 1 buah
Push button ==> 1 buah

<h3>2. Rangkaian</h3>

![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/6331087e-8f68-4a7f-ad8a-31dec91569ff)

<h3>3. Program</h3>

```
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

<h3>4. Flowchart</h3>
![flow_job1_1](https://github.com/milham08330/Embedded-System/assets/42812745/72ad482b-95e1-4648-8a90-035f25596f61)


<h3>4. Hasil</h3>

Led blink 1 detik 


https://github.com/milham08330/Embedded-System/assets/42812745/e370cf18-5670-4bf8-914d-22fd5ce3b6d1


<h1 align="">B. Program LED dapat blink 1 detik sekali menggunakan timer milis()</h1>

<h3>1. Alat dan Bahan</h3>

ESP32 ==> 1 buah
LED ==> 1 buah
Resistor 220 Ohm ==> 1 buah
Resistor 10k Ohm ==> 1 buah
Push button ==> 1 buah

<h3>2. Rangkaian</h3>

![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/6331087e-8f68-4a7f-ad8a-31dec91569ff)

<h3>3. Program</h3>

![GPIO 2](https://github.com/milham08330/Embedded-System/assets/42812745/be992475-e98f-4d1a-baed-74568e4d0928)

<h3>4. Hasil</h3> 

Led Push Button


https://github.com/milham08330/Embedded-System/assets/42812745/82c7801a-64d3-4b1c-a9d9-1eb73c7c3cd0


<h1 align="">C. Program pertama akan digunakan untuk mengendalikan LED menggunakan Push Button()</h1>

<h3>1. Alat dan Bahan</h3>
ESP32 ==> 1 buah</p>
LED ==> 1 buah
Resistor 220 Ohm ==> 1 buah
Resistor 10k Ohm ==> 1 buah
Push button ==> 1 buah

<h3>2. Rangkaian</h3>

![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/6331087e-8f68-4a7f-ad8a-31dec91569ff)

<h3>3. Program</h3>

![GPIO 2](https://github.com/milham08330/Embedded-System/assets/42812745/3ae6a033-9e51-4deb-8b65-71ce366ab55a)

<h3>4. Hasil</h3>

Led Push Button 

https://github.com/milham08330/Embedded-System/assets/42812745/0e0e3ff0-2a9e-4ae6-9677-ce272f30bf16


