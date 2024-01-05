# A. Memperoleh MAC Address ESP32 Receiver

## 1. Rangkaian

![rangkaian](https://github.com/milham08330/Embedded-System/assets/42812745/9e5cdf38-216f-42a5-9827-4bcb75740506)

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

![hasil](https://github.com/milham08330/Embedded-System/assets/42812745/630ebc0b-64b5-4b2b-8d80-6e099520c0e5)

 
<p align="justify">Dalam percobaan ini output yang didapat adalah mendapatkan MAC Address dari ESP32 yang dikirim melalui serial monitor. MAC Address yang didapat yaitu C8:F0:9E:F4:32:7C
