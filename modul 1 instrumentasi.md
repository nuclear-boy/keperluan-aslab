# [cite_start]📚 MODUL PRAKTIKUM 1: Sensor dalam Instrumentasi Elektronika [cite: 241, 242]

## [cite_start]1. Pendahuluan [cite: 243]
[cite_start]Sensor merupakan komponen utama dalam sistem instrumentasi elektronika karena berfungsi mengubah besaran fisika seperti suhu, cahaya, kelembapan, dan tekanan menjadi sinyal listrik yang dapat diolah lebih lanjut oleh rangkaian elektronika atau mikrokontroler[cite: 244]. [cite_start]Pemahaman mengenai karakteristik sensor, cara kerja, kalibrasi, serta metode pembacaan sinyal sangat penting agar mahasiswa mampu merancang sistem pengukuran yang akurat dan andal[cite: 245]. 

[cite_start]Dalam praktikum ini, mahasiswa akan mempelajari prinsip kerja beberapa jenis sensor yang umum digunakan pada sistem instrumentasi, seperti sensor cahaya (LDR), sensor suhu (NTC atau DHT11), dan sensor jarak (ultrasonik)[cite: 246]. [cite_start]Praktikum juga melatih kemampuan menghubungkan sensor dengan rangkaian mikrokontroler serta melakukan analisis terhadap data hasil pengukuran[cite: 247].

---

## [cite_start]2. Tujuan Praktikum [cite: 248]
Setelah mengikuti praktikum ini, mahasiswa diharapkan mampu:
* [cite_start]Memahami prinsip kerja berbagai jenis sensor[cite: 249, 250].
* [cite_start]Menghubungkan sensor dengan rangkaian elektronika dan mikrokontroler[cite: 251].
* [cite_start]Mengukur dan merekam data keluaran sensor[cite: 252].
* [cite_start]Melakukan kalibrasi sederhana dan analisis karakteristik sensor[cite: 253].
* [cite_start]Menginterpretasikan hasil pengukuran dalam bentuk grafik dan laporan[cite: 254].

---

## [cite_start]3. Dasar Teori [cite: 255]

### [cite_start]3.1 Definisi Sensor [cite: 256]
[cite_start]Sensor adalah komponen elektronika yang mampu mendeteksi perubahan besaran fisik dan mengubahnya menjadi sinyal listrik[cite: 257]. [cite_start]Sensor dibedakan menjadi beberapa kategori berdasarkan cara kerja, jenis keluaran, dan besaran yang diukur[cite: 258].

### [cite_start]3.2 Jenis-Jenis Sensor yang Umum Digunakan [cite: 259]
* [cite_start]**Sensor Cahaya (LDR – Light Dependent Resistor):** LDR memiliki resistansi yang berubah terhadap intensitas cahaya[cite: 260, 261]. [cite_start]Semakin terang cahaya, resistansi LDR semakin kecil[cite: 261]. [cite_start]Sensor ini umumnya digunakan untuk detektor siang/malam dan pengukur intensitas cahaya[cite: 262].
* [cite_start]**Sensor Suhu (NTC Thermistor / DHT11):** NTC (Negative Temperature Coefficient) memiliki resistansi yang menurun ketika suhu meningkat[cite: 263, 264]. [cite_start]DHT11 adalah sensor suhu dan kelembapan digital yang memberikan sinyal keluaran berupa data digital[cite: 265].
* [cite_start]**Sensor Jarak Ultrasonik (HC-SR04):** Menggunakan gelombang ultrasonik 40 kHz untuk mengukur jarak berdasarkan waktu tempuh sinyal (*time of flight*)[cite: 266, 267].

### [cite_start]3.3 Konsep Kalibrasi Sensor [cite: 268]
[cite_start]Kalibrasi dilakukan untuk mengetahui hubungan matematis antara sinyal keluaran sensor dan besaran fisik sebenarnya[cite: 269]. [cite_start]Contoh kalibrasi sederhana: menyusun tabel hubungan tegangan keluaran LDR terhadap intensitas cahaya (lux)[cite: 270].

---

## [cite_start]4. Alat dan Bahan [cite: 271]
1. [cite_start]Mikrokontroler Arduino Uno [cite: 272]
2. [cite_start]Sensor LDR [cite: 273]
3. [cite_start]Sensor suhu DHT11 [cite: 274]
4. [cite_start]Sensor jarak ultrasonik HC-SR04 [cite: 275]
5. [cite_start]Resistor 10 kΩ (sebagai pembagi tegangan LDR) [cite: 276]
6. [cite_start]Breadboard dan kabel jumper [cite: 277]
7. [cite_start]Multimeter [cite: 278]
8. [cite_start]Laptop dengan Arduino IDE [cite: 279]

---

## [cite_start]5. Rangkaian Percobaan [cite: 280]

### [cite_start]5.1 Sensor Cahaya (LDR) [cite: 281]
* [cite_start]LDR diseri dengan resistor 10 kΩ membentuk rangkaian pembagi tegangan[cite: 282]. * Tegangan keluaran pada titik tengah dihubungkan ke pin analog A0 Arduino[cite: 283].

### 5.2 Sensor Suhu DHT11 [cite: 284]
* [cite_start]Pin data dihubungkan ke pin digital (misal D2)[cite: 285].
* [cite_start]Beri resistor pull-up 10 kΩ antara VCC dan Data[cite: 286].

### [cite_start]5.3 Sensor Jarak Ultrasonik HC-SR04 [cite: 287]
* [cite_start]Trig → pin D9 Arduino [cite: 288]
* [cite_start]Echo → pin D10 Arduino [cite: 289]
* [cite_start]VCC dan GND sesuai standar [cite: 290]

---

## [cite_start]6. Prosedur Percobaan [cite: 291]

### [cite_start]Percobaan 1: Sensor Cahaya (LDR) [cite: 292]
1. [cite_start]Rangkai sensor LDR sesuai diagram[cite: 293].
2. [cite_start]Upload program pembacaan analog pada pin A0[cite: 294].
3. [cite_start]Lakukan pengukuran pada kondisi terang, redup, dan gelap[cite: 295].
4. [cite_start]Catat nilai ADC dan intensitas cahaya (bila tersedia lux meter)[cite: 296].

### [cite_start]Percobaan 2: Sensor Suhu DHT11 [cite: 297]
1. [cite_start]Hubungkan DHT11 dengan Arduino[cite: 298].
2. [cite_start]Gunakan library DHT pada Arduino IDE[cite: 299].
3. [cite_start]Catat nilai suhu dan kelembapan pada beberapa kondisi (ruangan, didekatkan dengan sumber panas)[cite: 300].

### [cite_start]Percobaan 3: Sensor Jarak HC-SR04 [cite: 301]
1. [cite_start]Pastikan rangkaian sesuai[cite: 302].
2. [cite_start]Upload program pembacaan jarak[cite: 303].
3. [cite_start]Letakkan objek pada jarak 5, 10, 15, 20, dan 25 cm[cite: 304].
4. [cite_start]Catat hasil pengukuran sensor[cite: 305].

---

## [cite_start]7. Program Arduino [cite: 306]

### [cite_start]7.1 Sensor LDR [cite: 307]
```cpp
int sensorPin = A0; [cite_start]// [cite: 308]

[cite_start]void setup() { // [cite: 309]
  Serial.begin(9600); [cite_start]// [cite: 310]
[cite_start]} // [cite: 311]

[cite_start]void loop() { // [cite: 312]
  int sensorValue = analogRead(sensorPin); [cite_start]// [cite: 313]
  Serial.println(sensorValue); [cite_start]// [cite: 314]
  delay(500); [cite_start]// [cite: 315]
[cite_start]} // [cite: 316]

### [cite_start]7.2 Sensor DHT [cite: 307]
```cpp
#include "DHT.h" // [cite: 318]
DHT dht(2, DHT11); // [cite: 319]

void setup() { // [cite: 320]
  Serial.begin(9600); // [cite: 321]
  dht.begin(); // [cite: 322]
} // [cite: 323]

void loop() { // [cite: 324]
  float t = dht.readTemperature(); // [cite: 325]
  float h = dht.readHumidity(); // [cite: 326]
  Serial.print("Temp: "); Serial.print(t); // [cite: 327]
  Serial.print(" C  Humidity: "); Serial.println(h); // [cite: 328]
  delay(1000); // [cite: 329]
} // [cite: 330]

### [cite_start]7.3 Sensor Jarak HC-SR04 [cite: 307]
```cpp

#define trig 9 // [cite: 332]
#define echo 10 // [cite: 333]

void setup() { // [cite: 334]
  Serial.begin(9600); // [cite: 335]
  pinMode(trig, OUTPUT); // [cite: 336]
  pinMode(echo, INPUT); // [cite: 337]
} // [cite: 338]

void loop() { // [cite: 339]
  digitalWrite(trig, LOW); // [cite: 340]
  delayMicroseconds(2); // [cite: 341]
  digitalWrite(trig, HIGH); // [cite: 342]
  delayMicroseconds(10); // [cite: 343]
  digitalWrite(trig, LOW); // [cite: 344]
  
  long duration = pulseIn(echo, HIGH); // [cite: 345]
  float distance = duration * 0.034 / 2; // [cite: 346]
  
  Serial.print("Distance: "); // [cite: 347]
  Serial.println(distance); // [cite: 348]
  delay(500); // [cite: 349]
} // [cite: 350]
