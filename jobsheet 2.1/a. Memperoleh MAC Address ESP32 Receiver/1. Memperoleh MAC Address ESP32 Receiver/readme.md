# A. Memperoleh MAC Address ESP32 Receiver

## 1. Rangkaian

<img src="https://github.com/brianrahma/brian-system-embedded/assets/82065700/df22b4a6-37f9-4eda-8d9c-644d8d0cfec3" width="500">

## 2. Source Code

```cpp
#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  Serial.println(WiFi.macAddress());
}
void loop() {
}
```

## 3. Hasil dan Pembahasan

 **Hasil percobaan :**

 <img src="https://github.com/brianrahma/system-embedded/assets/82065700/fb43dc71-a008-4110-9d64-ff6c98b3cbc4" width="700">

 
<p align="justify">Dalam percobaan ini output yang didapat adalah mendapatkan MAC Address dari ESP32 yang dikirim melalui serial monitor. MAC Address yang didapat yaitu C8:F0:9E:F4:32:7C
