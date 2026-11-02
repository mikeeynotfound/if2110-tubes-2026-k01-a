# Template Tugas Besar AP2

Starter repository untuk **IF2110 Algoritma dan Pemrograman 2 2026/2027**. Berisi contoh struktur proyek C, Makefile, serta sample data.

Struktur folder boleh disesuaikan dengan rancangan kelompok.

```sh
make
make run
```

`make run` menjalankan aplikasi kelompok melalui `bin/nangornotes`.

## Struktur Folder

```text
.
├── Makefile
├── README.md
├── src/
│   ├── main.c
├── drivers/                  # Program pengujian ADT
├── sample-data/
│   ├── jurnal/               # Contoh jurnal dengan data
│   └── kosong/               # Contoh jurnal kosong
└── doc/                      # Laporan dan dokumentasi kelompok
```

Folder `build/` dan `bin/` dibuat otomatis saat kompilasi dan tidak masuk Git.

## Makefile

| Perintah     | Kegunaan                                                      |
| ------------ | ------------------------------------------------------------- |
| `make`       | Mengompilasi seluruh file `.c` di `src/`, termasuk subfolder. |
| `make run`   | Mengompilasi jika diperlukan, lalu menjalankan aplikasi.      |
| `make clean` | Menghapus `build/` dan `bin/`; sample data tetap ada.         |
| `make help`  | Menampilkan bantuan target, termasuk driver.                  |

## Sample Data

- **sample-data/jurnal:** 3 halaman, 3 blok, 2 tag, 2 link, dan 3 relasi halaman–tag.
- **sample-data/kosong:** jurnal kosong yang valid untuk memulai aplikasi.

Masing-masing folder berisi enam CSV sesuai spesifikasi. Penjelasan isi dan ID berikutnya ada pada [sample-data/README.md](sample-data/README.md).

Path mengikuti working directory aplikasi; jangan di-hardcode.
