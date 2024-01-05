// AISYAH NURUL AINI               (4.31.21.0.03)
// BRIAN RAHMADITYA                (4.31.21.0.09)
// SABRINA VIRRY TALITHA MEIRILLA  (4.31.21.0.23)
//Import required libraries
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Ganti dengan kredensial jaringan Anda
const char* ssid = "wifikampus"; // Nama SSID WiFi Anda
const char* password = "12345678."; // Kata sandi WiFi Anda

#define DHTPIN 4 // Pin digital yang terhubung ke sensor DHT
#define DHTTYPE DHT11 // Jenis sensor DHT yang digunakan (DHT11)

DHT dht(DHTPIN, DHTTYPE);

// Membuat objek AsyncWebServer pada port 80
AsyncWebServer server(80);

// Fungsi untuk membaca suhu dari sensor DHT
String readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  } else {
    Serial.println(t);
    return String(t);
  }
}

// Fungsi untuk membaca kelembapan dari sensor DHT
String readDHTHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  } else {
    Serial.println(h);
    return String(h);
  }
}

// HTML untuk halaman web
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css"
integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr"
crossorigin="anonymous">
<style>
html {
font-family: Arial;
display: inline-block;
margin: 0px auto;
text-align: center;
}
h2 { font-size: 3.0rem; }
p { font-size: 3.0rem; }
.units { font-size: 1.2rem; }
.dht-labels{
font-size: 1.5rem;
vertical-align:middle;
padding-bottom: 15px;
}
</style>
</head>
<body>
<h2>ESP32 DHT Server</h2>
<p>
<i class="fas fa-thermometer-half" style="color:#059e8a;"></i>
<span class="dht-labels">Temperature</span>
<span id="temperature">%TEMPERATURE%</span>
<sup class="units">&deg;C</sup>
</p>
<p>
<i class="fas fa-tint" style="color:#00add6;"></i>
<span class="dht-labels">Humidity</span>
<span id="humidity">%HUMIDITY%</span>
<sup class="units">&percnt;</sup>
</p>
</body>
<script>
setInterval(function ( ) {
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
if (this.readyState == 4 && this.status == 200) {
document.getElementById("temperature").innerHTML = this.responseText;
}
};
xhttp.open("GET", "/temperature", true);
xhttp.send();
}, 10000 ) ;
setInterval(function ( ) {
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
if (this.readyState == 4 && this.status == 200) {
document.getElementById("humidity").innerHTML = this.responseText;
}
};
xhttp.open("GET", "/humidity", true);
xhttp.send();
}, 10000 ) ;
</script>
</html>)rawliteral";

// Fungsi untuk mengganti placeholder dengan nilai suhu dan kelembapan yang dibaca dari sensor DHT
String processor(const String& var) {
  if (var == "TEMPERATURE") {
    return readDHTTemperature();
  } else if (var == "HUMIDITY") {
    return readDHTHumidity();
  }
  return String();
}

void setup() {
  // Memulai komunikasi serial dengan baud rate 115200
  Serial.begin(115200);

  // Memulai sensor DHT
  dht.begin();

  // Menghubungkan ke WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Mencetak alamat IP lokal ESP32
  Serial.println(WiFi.localIP());

  // Route untuk halaman utama / web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", index_html, processor);
  });

  // Route untuk membaca suhu
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });

  // Route untuk membaca kelembapan
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readDHTHumidity().c_str());
  });

  // Menjalankan server
  server.begin();
}

void loop() {
  // Kode utama Anda akan berjalan berulang kali di sini
}

