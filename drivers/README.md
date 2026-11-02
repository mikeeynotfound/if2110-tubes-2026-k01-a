# Driver ADT

Letakkan program pengujian ADT di folder ini. Setiap driver memiliki `int main(void)` sendiri dan menguji operasi ADT yang dipilih, termasuk perubahan isi struktur dan kasus gagal yang relevan.

Sebagai contoh, setelah membuat `drivers/list_driver.c`:

```sh
make driver DRIVER=drivers/list_driver.c
./bin/drivers/list_driver
```

Atau kompilasi dan jalankan sekaligus:

```sh
make run-driver DRIVER=drivers/list_driver.c
```

Makefile menghubungkan driver dengan modul `.c` di `src/`, **kecuali `src/main.c`**, agar tidak ada dua entry point. Header dapat diakses dari root `src/`, misalnya `#include "adt/list.h"` untuk berkas `src/adt/list.h`.

Subfolder didukung: `drivers/tree/traversal_driver.c` menghasilkan `bin/drivers/tree/traversal_driver`. Jika suatu driver membutuhkan himpunan modul yang berbeda, sesuaikan Makefile dengan dependensinya.

Template tidak menyertakan implementasi ADT atau driver yang sudah selesai. Rancang pengujian berdasarkan kontrak ADT kelompok kalian.
