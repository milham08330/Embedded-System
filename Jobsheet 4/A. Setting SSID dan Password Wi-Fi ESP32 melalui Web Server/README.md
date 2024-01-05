# A. Setting SSID dan Password Wi-Fi ESP32 melalui Web Server

## 1. Alat dan Bahan
1) ESP32
2) Arduino IDE

## 2. Source Code

```cpp
#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <EEPROM.h>
//Variables
int i = 0;
int statusCode;
const char* ssid = "1163542";
const char* passphrase = "kitabisa";
String st;
String content;
String esid;
String epass = "";
//Function Decalration
bool testWifi(void);
void launchWeb(void);
void setupAP(void);
//Establishing Local server at port 80
WebServer server(80);
void setup()
{
 Serial.begin(115200); //Initialising if(DEBUG)Serial Monitor
 Serial.println();
 Serial.println("Disconnecting current wifi connection");
 WiFi.disconnect();
 EEPROM.begin(512); //Initialasing EEPROM
 delay(10);
 pinMode(15, INPUT);
 Serial.println();
 Serial.println();
 Serial.println("Startup");
 //---------------------------------------- Read eeprom for ssid and pass
 Serial.println("Reading EEPROM ssid");
 for (int i = 0; i < 32; ++i)
 {
 esid += char(EEPROM.read(i));
 }
 Serial.println();
 Serial.print("SSID: ");
 Serial.println(esid);
 Serial.println("Reading EEPROM pass");
 for (int i = 32; i < 96; ++i)
 {
 epass += char(EEPROM.read(i));
 }
 Serial.print("PASS: ");
 Serial.println(epass);
 WiFi.begin(esid.c_str(), epass.c_str());
}
void loop() {
 if ((WiFi.status() == WL_CONNECTED))
 {
 for (int i = 0; i < 10; i++)
 {
 Serial.print("Connected to ");
 Serial.print(esid);
 Serial.println(" Successfully");
 delay(100);
 }
 }
 else
 {
 }
 if (testWifi() && (digitalRead(2) != 1))
 {
 Serial.println(" connection status positive");
 return;
 }
 else
 {
 Serial.println("Connection Status Negative / D15 HIGH");
 Serial.println("Turning the HotSpot On");
 launchWeb();
 setupAP();// Setup HotSpot
 }
 Serial.println();
 Serial.println("Waiting.");
 while ((WiFi.status() != WL_CONNECTED))
 {
 Serial.print(".");
 delay(100);
 server.handleClient();
 }
 delay(1000);
}
//----------------------------------------------- Fuctions used for WiFi credentials saving and connecting to it which you do not need to change
bool testWifi(void)
{
 int c = 0;
 //Serial.println("Waiting for Wifi to connect");
 while ( c < 20 ) {
 if (WiFi.status() == WL_CONNECTED)
 {
 return true;
 }
 delay(500);
 Serial.print("*");
 c++;
 }
 Serial.println("");
 Serial.println("Connect timed out, opening AP");
 return false;
}
void launchWeb()
{
 Serial.println("");
 if (WiFi.status() == WL_CONNECTED)
 Serial.println("WiFi connected");
 Serial.print("Local IP: ");
 Serial.println(WiFi.localIP());
 Serial.print("SoftAP IP: ");
 Serial.println(WiFi.softAPIP());
 createWebServer();
 // Start the server
 server.begin();
 Serial.println("Server started");
}
void setupAP(void)
{
 WiFi.mode(WIFI_STA);
 WiFi.disconnect();
 delay(100);
 int n = WiFi.scanNetworks();
 Serial.println("scan done");
 if (n == 0)
 Serial.println("no networks found");
 else
 {
 Serial.print(n);
 Serial.println(" networks found");
 for (int i = 0; i < n; ++i)
 {
 // Print SSID and RSSI for each network found
 Serial.print(i + 1);
 Serial.print(": ");
 Serial.print(WiFi.SSID(i));
 Serial.print(" (");
 Serial.print(WiFi.RSSI(i));
 Serial.print(")");
 //Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
 delay(10);
 }
 }
 Serial.println("");
 st = "<ol>";
 for (int i = 0; i < n; ++i)
 {
 // Print SSID and RSSI for each network found
 st += "<li>";
 st += WiFi.SSID(i);
 st += " (";
 st += WiFi.RSSI(i);
 st += ")";
 //st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
 st += "</li>";
 }
 st += "</ol>";
delay(100);
 WiFi.softAP("MiSREd IoT", "");
 Serial.println("Initializing_softap_for_wifi credentials_modification");
 launchWeb();
 Serial.println("over");
}
void createWebServer()
{
 {
 server.on("/", []() {
      IPAddress ip = WiFi.softAPIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      content = "<!DOCTYPE HTML>\r\n<html>Welcome to Wifi Credentials Update page";
      content += "<form action=\"/scan\" method=\"POST\"><input type=\"submit\" value =\"scan\"></form>";
      content += ipStr;
      content += "<p>";
      content += st;
      content += "</p><form method='get' action='setting'><label>SSID: </label><input name='ssid' length = 32 > <input name = 'pass' length = 64><input type = 'submit'></ form> "; 
      content += "</html>";
      server.send(200,"text/html",content);
 });
 server.on("/scan", []() {
 //setupAP();
 IPAddress ip = WiFi.softAPIP();
 String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
 content = "<!DOCTYPE HTML>\r\n<html>go back";
 server.send(200, "text/html", content);
 });
 server.on("/setting", []() {
 String qsid = server.arg("ssid");
 String qpass = server.arg("pass");
 if (qsid.length() > 0 && qpass.length() > 0) {
 Serial.println("clearing eeprom");
 for (int i = 0; i < 96; ++i) {
 EEPROM.write(i, 0);
 }
 Serial.println(qsid);
 Serial.println("");
 Serial.println(qpass);
 Serial.println("");
 Serial.println("writing eeprom ssid:");
 for (int i = 0; i < qsid.length(); ++i)
 {
 EEPROM.write(i, qsid[i]);
 Serial.print("Wrote: ");
 Serial.println(qsid[i]);
 }
 Serial.println("writing eeprom pass:");
 for (int i = 0; i < qpass.length(); ++i)
 {
 EEPROM.write(32 + i, qpass[i]);
 Serial.print("Wrote: ");
 Serial.println(qpass[i]);
 }
 EEPROM.commit();
 content = "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
 statusCode = 200;
 ESP.restart();
 } else {
 content = "{\"Error\":\"404 not found\"}";
 statusCode = 404;
 Serial.println("Sending 404");
 }
 server.sendHeader("Access-Control-Allow-Origin", "*");
 server.send(statusCode, "application/json", content);
 });
 }
}
```

## 3. Flowchart

![flow_job4_a](https://github.com/milham08330/Embedded-System/assets/42812745/c03d1622-3622-4573-a3c9-b270f79fe6e8)

## 4. Hasil dan Pembahasan
### Dokumentasi Hasil
1. Tampilan Awal Serial Monitor Sebelum Dihubungkan
   
   ![dok4_a1](https://github.com/milham08330/Embedded-System/assets/42812745/6e4e1679-cd0c-4676-a490-108bda737428)

2. Tampilan Web & WiFi
   
   ![dok4_a2](https://github.com/milham08330/Embedded-System/assets/42812745/4adb3991-d01c-468c-b55a-990d8e9aaa38)

   ![dok4_a22](https://github.com/milham08330/Embedded-System/assets/42812745/ae4a65e9-deee-4e14-bff4-461154368cd8)

3. Serial Monitor Setelah Memasukkan SSID dan PASS
4. 
   ![dok4_a3](https://github.com/milham08330/Embedded-System/assets/42812745/6403924d-a099-4298-b678-4336476e0c83)

5. Serial Monitor Setelah Berhasil Terhubung
   
   ![dok4_a4](https://github.com/milham08330/Embedded-System/assets/42812745/32270913-ac3b-4fd7-b5e9-96051e55576c)


### Pembahasan

  1. Bagian Awal:
  * Memasukkan library yang diperlukan:
     * 'WiFi.h': untuk mengakses fungsi Wi-Fi.
     * Membaca kredensial WiFi yang tersimpan di EEPROM.
     * Mencoba menghubungkan ke WiFi menggunakan kredensial tersebut.

  2. Loop Utama:
  * Jika terkoneksi ke WiFi:
    * Mencetak pesan konfirmasi koneksi.
  * Jika tidak terkoneksi ke WiFi:
    * Mengecek status tombol untuk memaksa mode AP (Access Point).
    * Jika tombol tidak ditekan dan koneksi gagal, memulai mode AP dan membuat halaman web untuk konfigurasi WiFi.
    * Menunggu hingga terkoneksi ke WiFi.

  3. Fungsi testWifi:
  * Mencoba menghubungkan ke WiFi selama 10 detik.
  * Mengembalikan nilai 'true' jika terkoneksi, 'false' jika tidak.

  4. Fungsi launchWeb:
  * Mencetak informasi IP address perangkat (local dan softAP jika ada).
  * Menjalankan fungsi createWebServer untuk membuat halaman web konfigurasi WiFi.

  5. Fungsi setupAP:
  * Mengatur perangkat sebagai Access Point (AP) dengan nama "MiSREd IoT".
  * Mencari jaringan WiFi di sekitar dan menyimpan daftarnya dalam variabel st.
  * Menjalankan fungsi launchWeb untuk menampilkan halaman konfigurasi WiFi.

  6. Fungsi createWebServer:
  * Menangani permintaan ke halaman web:
    * '/' : Menampilkan halaman utama dengan daftar jaringan WiFi yang ditemukan dan formulir untuk memasukkan kredensial WiFi baru.
    * '/scan' : Memindai ulang jaringan WiFi dan menampilkan hasilnya.
    * '/setting' : Menerima kredensial WiFi baru, menyimpannya ke EEPROM, dan me-restart perangkat.
  
### Kesimpulan:
Kode ini dirancang untuk memudahkan konfigurasi WiFi pada perangkat dengan menyediakan antarmuka web yang dapat diakses dari perangkat lain. Pengguna dapat mengubah kredensial WiFi tanpa perlu mengubah kode secara langsung.
