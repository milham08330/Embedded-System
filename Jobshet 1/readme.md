
<h1 align="">GPIO</h1>
<h1 align="">A. Program pertama akan digunakan untuk membuat blink dengan interval 100ms, 1 detik, 2 detik, dan 3 detik sekali.</h1>

<br>1. Alat dan Bahan</p>

<br>ESP32 ==> 1 buah</p>
<br>LED ==> 1 buah
<br>Resistor 220 Ohm ==> 1 buah
<br>Resistor 10k Ohm ==> 1 buah
<br>Push button ==> 1 buah

<br>2. Rangkaian
<br>![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/6331087e-8f68-4a7f-ad8a-31dec91569ff)

<br>3. Program
```// set pin numbers
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

<br>4. Flowchart
![flow_job1_1](https://github.com/milham08330/Embedded-System/assets/42812745/fbbe4a1a-d031-49fc-8568-538d4129e591)


<br>5. Hasil 
<br>Led blink 1 detik 


https://github.com/milham08330/Embedded-System/assets/42812745/e370cf18-5670-4bf8-914d-22fd5ce3b6d1


<h1 align="">B. Program LED dapat blink 1 detik sekali menggunakan timer milis()</h1>

<br>1. Alat dan Bahan</p>

<br>ESP32 ==> 1 buah</p>
<br>LED ==> 1 buah
<br>Resistor 220 Ohm ==> 1 buah
<br>Resistor 10k Ohm ==> 1 buah
<br>Push button ==> 1 buah

<br>2. Rangkaian
<br>![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/6331087e-8f68-4a7f-ad8a-31dec91569ff)

<br>3. Program
```// the number of the LED pin
const int ledPin = 16; // 16 corresponds to GPIO16
// setting PWM properties
const int freq = 5000;
const int ledChannel = 0; //PWM Channel
const int resolution = 8; //resolution bit
void setup(){
 // configure LED PWM functionalitites
 ledcSetup(ledChannel, freq, resolution);
 
 // attach the channel to the GPIO to be controlled
 ledcAttachPin(ledPin, ledChannel);
}
void loop(){
 // increase the LED brightness
for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){ 
 // changing the LED brightness with PWM
 ledcWrite(ledChannel, dutyCycle);
 delay(15);
 }
 // decrease the LED brightness
 for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
 // changing the LED brightness with PWM
 ledcWrite(ledChannel, dutyCycle); 
 delay(15);
 }
}
```
<br>4. Flowchart 

![flow_job1_2](https://github.com/milham08330/Embedded-System/assets/42812745/a3493f0e-0926-41da-b901-d32fbf6659b1)


<br>5. Hasil 
<br>Led Push Button


https://github.com/milham08330/Embedded-System/assets/42812745/82c7801a-64d3-4b1c-a9d9-1eb73c7c3cd0


<h1 align="">C. Program pertama akan digunakan untuk mengendalikan LED menggunakan Push Button()</h1>

<br>1. Alat dan Bahan</p>

<br>ESP32 ==> 1 buah</p>
<br>LED ==> 1 buah
<br>Resistor 220 Ohm ==> 1 buah
<br>Resistor 10k Ohm ==> 1 buah
<br>Push button ==> 1 buah

<br>2. Rangkaian
<br>![gpio](https://github.com/milham08330/Embedded-System/assets/42812745/6331087e-8f68-4a7f-ad8a-31dec91569ff)

<br>3. Program
```
// the number of the LED pin
const int ledPin = 16; // 16 corresponds to GPIO16
const int ledPin2 = 17; // 17 corresponds to GPIO17
const int ledPin3 = 5; // 5 corresponds to GPIO5
// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
void setup(){
 // configure LED PWM functionalitites
 ledcSetup(ledChannel, freq, resolution);
 
 // attach the channel to the GPIO to be controlled
 ledcAttachPin(ledPin, ledChannel);
 ledcAttachPin(ledPin2, ledChannel);
 ledcAttachPin(ledPin3, ledChannel);
}
void loop(){
 // increase the LED brightness
 for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){ 
 // changing the LED brightness with PWM
edcWrite(ledChannel, dutyCycle);
 delay(15);
 }
 // decrease the LED brightness
 for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
 // changing the LED brightness with PWM
 ledcWrite(ledChannel, dutyCycle); 
 delay(15);
 }
}
```
<br>4. Flowchart



<br>5. Hasil 
<br>Led Push Button 

https://github.com/milham08330/Embedded-System/assets/42812745/0e0e3ff0-2a9e-4ae6-9677-ce272f30bf16
