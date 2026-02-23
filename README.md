# 📚 Analisis Matematis & Kalibrasi Sensor Berbasis Mikrokontroler

Repositori ini berisi dokumentasi matematis dan metrik evaluasi yang digunakan dalam eksperimen kalibrasi **Sensor Jarak Ultrasonik (HC-SR04)** dan **Sensor Suhu (DHT11)**. Seluruh persamaan di bawah ini diimplementasikan ke dalam kode Arduino untuk mengoreksi dan menganalisis pembacaan sensor.

---

## 📑 Daftar Isi
1. [Bagian 1: Pengukuran Jarak Ultrasonik (ToF)](#1-pengukuran-jarak-ultrasonik-tof)
2. [Bagian 2: Kalibrasi Sensor Suhu (Regresi Linear)](#2-kalibrasi-sensor-suhu-regresi-linear)
3. [Bagian 3: Evaluasi Kinerja Sensor](#3-evaluasi-kinerja-sensor)

---

## 1. Pengukuran Jarak Ultrasonik (ToF)

Sensor ultrasonik beroperasi menggunakan prinsip **Time of Flight (ToF)**, yaitu mengukur waktu tempuh gelombang mekanik (frekuensi 40 kHz) dari saat dipancarkan (Transmitter) hingga pantulannya kembali diterima (Receiver).



### A. Rumus Jarak Dasar
Karena gelombang suara melakukan perjalanan bolak-balik (ke objek dan kembali ke sensor), jarak total yang ditempuh adalah $2d$. Maka, jarak objek ($d$) dihitung dengan persamaan:

$$
d = \frac{v \cdot t}{2}
$$

**Keterangan Variabel:**
* $d$ = Jarak objek ke sensor (m atau cm)
* $t$ = Waktu tempuh total gelombang / *duration* (s atau $\mu s$)
* $v$ = Kecepatan rambat suara di udara ($\approx 343 \text{ m/s}$ pada suhu $25^\circ\text{C}$)

### B. Pengaruh Suhu terhadap Kecepatan Suara
Kecepatan suara di udara ($v$) tidaklah konstan dan sangat dipengaruhi oleh suhu lingkungan ($T$). Jika ingin hasil pengukuran jarak yang jauh lebih presisi, kecepatan suara dapat dikoreksi menggunakan persamaan:

$$
v = 331 + 0.6T
$$

Dimana $T$ adalah suhu lingkungan dalam satuan derajat Celcius ($^\circ\text{C}$).

## 2. Kalibrasi Sensor Suhu (Regresi Linear)

Sensor *low-cost* seperti DHT11 memiliki simpangan bawaan pabrik. Untuk membuat alat ukur yang layak untuk riset, data sensor (DHT11) harus dikalibrasi terhadap data Alat Ukur Referensi (Standar) menggunakan metode **Regresi Linear**.



### A. Model Persamaan Regresi
Melalui plot titik data eksperimen (Suhu Referensi vs Suhu Sensor), ditarik garis lurus (*trendline*) yang menghasilkan persamaan:

$$
Y = aX + b
$$

**Keterangan Variabel:**
* $Y$ = Suhu terbaca oleh Sensor DHT11 (Sumbu Y)
* $X$ = Suhu Sebenarnya dari Alat Referensi (Sumbu X)
* $a$ = **Sensitivitas** (Kemiringan garis/gradien)
* $b$ = **Offset** (Nilai simpangan awal pada saat $X=0$)

### B. Persamaan Kalibrasi (Konversi)
Tujuan utama di dalam sistem mikrokontroler adalah mencari tahu **Suhu Sebenarnya ($X$)** berdasarkan data mentah sensor ($Y$). Persamaan aljabarnya dibalik menjadi:

$$
X = \frac{Y - b}{a}
$$

---

## 3. Evaluasi Kinerja Sensor

Untuk mengukur kualitas pembacaan sensor (baik sebelum maupun sesudah dikalibrasi), praktikan harus mengevaluasinya menggunakan 3 metrik parameter ukur berikut:



### A. Tingkat Kesalahan (Error)
Menghitung seberapa besar simpangan atau melesetnya pembacaan sensor ($T_{sensor}$) terhadap alat ukur standar ($T_{ref}$).

**1. Error Absolut** (Selisih nilai murni):

$$\text{Error Absolut} = T_{sensor} - T_{ref}$$

**2. Error Relatif** (Persentase penyimpangan):

$$\text{Error Relatif (\%)} = \left| \frac{T_{sensor} - T_{ref}}{T_{ref}} \right| \times 100\%$$

### B. Akurasi (Ketepatan)
Akurasi menyatakan persentase kedekatan nilai hasil pengukuran sensor dengan nilai yang sebenarnya. Nilai ideal adalah 100%.

$$
\text{Akurasi} = \left( 1 - \left| \frac{T_{sensor} - T_{ref}}{T_{ref}} \right| \right) \times 100\%
$$

### C. Presisi (Ketelitian / Standar Deviasi)
Presisi menunjukkan tingkat konsistensi/keterulangan instrumen saat mengukur titik yang sama berkali-kali. Presisi dinyatakan menggunakan rumus **Standar Deviasi Sampel** ($s$). Semakin kecil nilai $s$, semakin presisi sensor tersebut.

$$
s = \sqrt{\frac{\sum_{i=1}^{n} (x_i - \overline{x})^2}{n - 1}}
$$

**Keterangan Variabel Standar Deviasi:**
* $s$ = Nilai Presisi (Standar deviasi)
* $x_i$ = Nilai pengukuran ke-$i$
* $\overline{x}$ = Nilai rata-rata (*mean*) dari sekumpulan data pengukuran
* $n$ = Jumlah total pengukuran berulang (jumlah sampel)
