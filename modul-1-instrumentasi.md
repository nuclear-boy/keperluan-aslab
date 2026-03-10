# 📚 MODUL PRAKTIKUM 1: Sensor dalam Instrumentasi Elektronika

## 1. Pendahuluan
Sensor merupakan komponen utama dalam sistem instrumentasi elektronika karena berfungsi mengubah besaran fisika seperti suhu, cahaya, kelembapan, dan tekanan menjadi sinyal listrik yang dapat diproses lebih lanjut.

Dalam praktikum ini, mahasiswa akan mempelajari prinsip kerja beberapa jenis sensor yang umum digunakan pada sistem instrumentasi, seperti:
- Sensor cahaya (LDR)
- Sensor suhu (NTC/DHT11)
- Sensor jarak ultrasonik (HC-SR04)

---

## 2. Tujuan Praktikum
Setelah mengikuti praktikum ini, mahasiswa diharapkan mampu:
1. Memahami prinsip kerja berbagai jenis sensor.
2. Menghubungkan sensor dengan rangkaian elektronika dan mikrokontroler.
3. Mengukur dan merekam data keluaran sensor.
4. Melakukan kalibrasi sederhana dan analisis karakteristik sensor.
5. Menginterpretasikan hasil pengukuran dalam bentuk grafik dan laporan.

---

## 3. Dasar Teori

### 3.1 Definisi Sensor
Sensor adalah komponen elektronika yang mampu mendeteksi perubahan besaran fisik dan mengubahnya menjadi sinyal listrik.

### 3.2 Jenis-Jenis Sensor yang Umum Digunakan

**1) Sensor Cahaya (LDR – Light Dependent Resistor)**  
LDR memiliki resistansi yang berubah terhadap intensitas cahaya.
- Cahaya meningkat → resistansi LDR menurun
- Cahaya menurun → resistansi LDR meningkat

**2) Sensor Suhu (NTC Thermistor / DHT11)**  
- **NTC (Negative Temperature Coefficient):** resistansi menurun ketika suhu meningkat.  
- **DHT11:** sensor suhu dan kelembapan dengan keluaran data digital.

**3) Sensor Jarak Ultrasonik (HC-SR04)**  
Menggunakan gelombang ultrasonik (±40 kHz) untuk mengukur jarak berdasarkan waktu tempuh sinyal (*time of flight*).

### 3.3 Konsep Kalibrasi Sensor
Kalibrasi dilakukan untuk mengetahui hubungan matematis antara sinyal keluaran sensor dan besaran fisik sebenarnya.

Contoh kalibrasi sederhana:
- Ambil beberapa titik pengukuran (input fisik vs output sensor)
- Susun tabel hasil
- Buat grafik dan cari hubungan (linear/polinomial sederhana)

---

## 4. Alat dan Bahan
1. Mikrokontroler Arduino Uno
2. Sensor LDR
3. Sensor suhu DHT11
4. Sensor jarak ultrasonik HC-SR04
5. Resistor 10 kΩ (pembagi tegangan LDR)
6. Breadboard dan kabel jumper
7. Multimeter
8. Laptop dengan Arduino IDE

---

## 5. Rangkaian Percobaan

### 5.1 Sensor Cahaya (LDR)
- Rangkai LDR seri dengan resistor 10 kΩ sebagai pembagi tegangan.
- Tegangan keluaran pada titik tengah pembagi tegangan dihubungkan ke pin **A0** Arduino.

### 5.2 Sensor Suhu (DHT11)
- Pin **DATA** dihubungkan ke pin digital (misalnya **D2**).
- Pasang resistor **pull-up 10 kΩ** antara **VCC** dan **DATA**.

### 5.3 Sensor Jarak Ultrasonik (HC-SR04)
- **Trig → D9**
- **Echo → D10**
- **VCC** dan **GND** sesuai standar.

---

## 6. Prosedur Percobaan

### Percobaan 1: Sensor Cahaya (LDR)
1. Rangkai sensor LDR sesuai rangkaian pembagi tegangan.
2. Upload program pembacaan analog pada pin **A0**.
3. Lakukan pengukuran pada kondisi terang, redup, dan gelap.
4. Catat nilai ADC dan intensitas cahaya (jika tersedia lux meter).

### Percobaan 2: Sensor Suhu (DHT11)
1. Hubungkan DHT11 dengan Arduino.
2. Gunakan library DHT pada Arduino IDE.
3. Catat nilai suhu dan kelembapan pada beberapa kondisi (ruangan, didekatkan ke sumber panas, dsb.).

### Percobaan 3: Sensor Jarak (HC-SR04)
1. Pastikan rangkaian sesuai.
2. Upload program pembacaan jarak.
3. Letakkan objek pada jarak 5, 10, 15, 20, dan 25 cm.
4. Catat hasil pengukuran sensor.

---

## 7. Program Arduino

### 7.1 Sensor Cahaya (LDR)
```cpp
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(500);
}
```

### 7.2 Sensor Suhu & Kelembapan (DHT11)
```cpp
#include "DHT.h"
DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Memberikan jeda awal agar sensor siap, dan mencetak header
  Serial.println("Memulai perekaman data...");
}

void loop() {
  // 1. Mengambil waktu berjalan Arduino dan mengubahnya ke detik
  unsigned long waktuDetik = millis() / 1000;
  
  // 2. Membaca data dari sensor
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  // 3. Menampilkan Waktu
  Serial.print("Waktu: "); 
  Serial.print(waktuDetik); 
  Serial.print(" s  |  ");
  
  // 4. Menampilkan Suhu dan Kelembapan
  Serial.print("Temp: "); 
  Serial.print(t);
  Serial.print(" C  |  Humidity: "); 
  Serial.println(h);
  
  // Jeda 1 detik sebelum perulangan selanjutnya
  delay(1000);
}
```

### 7.3 Sensor Jarak Ultrasonik (HC-SR04)
```cpp
#define trig 9
#define echo 10

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(500);
}
```
