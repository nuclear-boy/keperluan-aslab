// ==========================================
// BAGIAN 1: Memasukkan Library dan Nama Pin
// ==========================================
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // Memanggil alat bantu (library) untuk layar LCD

#define trigPin 9  // Menamai pin 9 Arduino sebagai pin Trigger (Pemancar)
#define echoPin 10 // Menamai pin 10 Arduino sebagai pin Echo (Penerima)

// Mengatur alamat layar LCD (Biasanya 0x27 atau 0x3F) dengan ukuran 16 kolom 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// ==========================================
// BAGIAN 2: Pengaturan Awal (Berjalan 1 Kali)
// ==========================================
void setup() {
  Serial.begin(9600); // Menyalakan jalur komunikasi ke layar laptop (Serial Monitor)
  
  pinMode(trigPin, OUTPUT); // Pin Trigger bertugas mengeluarkan sinyal (OUTPUT)
  pinMode(echoPin, INPUT);  // Pin Echo bertugas mendengarkan sinyal masuk (INPUT)
  
  // Menyalakan layar LCD pertama kali
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Alat Kalibrasi"); // Menampilkan teks pembuka
  delay(2000);                 // Tunggu 2 detik
  lcd.clear();                 // Bersihkan layar
}

// ==========================================
// BAGIAN 3: Program Utama (Berjalan Terus Menerus)
// ==========================================
void loop() {
  long duration;    // Variabel untuk menyimpan waktu tempuh suara
  float distance;   // Variabel untuk menyimpan hasil hitungan jarak

  // --- Tahap A: Menembakkan Gelombang Suara ---
  digitalWrite(trigPin, LOW);  // Matikan pemancar sejenak
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Tembakkan gelombang suara selama 10 mikrodetik [cite: 58]
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Matikan pemancar lagi [cite: 59]
  
  // --- Tahap B: Menghitung Waktu dan Jarak ---
  // Menghitung berapa lama pin Echo menerima pantulan suara (dalam mikrodetik)
  duration = pulseIn(echoPin, HIGH); [cite: 60]
  
  // Rumus fisika: Jarak = (Waktu x Kecepatan Suara) dibagi 2 [cite: 13, 61]
  distance = duration * 0.0343 / 2.0; [cite: 61]
  
  // --- Tahap C: Menampilkan Hasil ke Layar ---
  // 1. Tampil di Layar Laptop (Serial Monitor)
  Serial.print("Distance (cm): "); [cite: 62]
  Serial.println(distance); [cite: 62]
  
  // 2. Tampil di Layar LCD Kotak
  lcd.setCursor(0, 0); // Pindah ke baris atas
  lcd.print("Jarak Objek:");
  lcd.setCursor(0, 1); // Pindah ke baris bawah
  lcd.print(distance); 
  lcd.print(" cm    "); // Cetak spasi kosong agar angka lama tertimpa
  
  delay(500); // Jeda setengah detik sebelum mengukur lagi [cite: 63]
}