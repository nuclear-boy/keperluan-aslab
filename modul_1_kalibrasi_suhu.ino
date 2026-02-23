// ==========================================
// BAGIAN 1: Memasukkan Library dan Nama Pin
// ==========================================
#include "DHT.h" // Memanggil alat bantu (library) khusus sensor DHT [cite: 134]

#define DHTPIN 2       // Kabel DATA sensor dihubungkan ke pin 2 Arduino [cite: 135]
#define DHTTYPE DHT11  // Memberitahu Arduino bahwa tipe sensornya adalah DHT11 [cite: 136]

DHT dht(DHTPIN, DHTTYPE); // Membuat "mesin" pembaca bernama dht [cite: 137]

// ==========================================
// BAGIAN 2: Pengaturan Awal
// ==========================================
void setup() {
  Serial.begin(9600); // Membuka komunikasi ke laptop [cite: 140]
  dht.begin();        // Menyalakan sensor suhu [cite: 141]
  Serial.println("Mulai membaca sensor...");
}

// ==========================================
// BAGIAN 3: Program Utama Pembacaan Suhu
// ==========================================
void loop() {
  delay(2000); // Sensor DHT11 butuh istirahat 2 detik tiap ambil data, jangan dihapus! [cite: 154]

  // --- Tahap A: Mengambil Data Mentah ---
  float rawTemp = dht.readTemperature(); // Membaca suhu murni (Celcius) [cite: 144, 224]
  float h = dht.readHumidity();          // Membaca kelembaban udara [cite: 146]

  // --- Tahap B: Sistem Keamanan (Cek Kabel) ---
  // Mengecek apakah data yang masuk itu angka atau bukan (kabel putus/longgar)
  if (isnan(rawTemp) || isnan(h)) { [cite: 147]
    Serial.println("Error: Sensor tidak terbaca!"); [cite: 149]
    return; // Program berhenti di sini dan kembali ke atas, mencegah error sistem [cite: 150]
  }

  // --- Tahap C: Memasukkan Rumus Kalibrasi ---
  // Sesuai modul, jika regresi Y = 0.95X + 1.2 [cite: 218]
  // Maka suhu yang benar (X) = (Y - 1.2) / 0.95 [cite: 220, 221]
  // Angka 1.2 dan 0.95 HARUS DIGANTI dengan hasil hitungan praktikan dari Microsoft Excel/Grafik!
  float calibratedTemp = (rawTemp - 1.2) / 0.95; [cite: 225]

  // --- Tahap D: Menampilkan ke Laptop ---
  Serial.println("============================");
  
  Serial.print("Suhu Sebelum Kalibrasi: ");
  Serial.print(rawTemp); // Suhu asli sensor
  Serial.println(" C");

  Serial.print("Suhu Setelah Kalibrasi: ");
  Serial.print(calibratedTemp); // Suhu yang sudah dikoreksi rumus
  Serial.println(" C");
}