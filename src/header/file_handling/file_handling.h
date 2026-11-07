#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <stdio.h>
#include "header/boolean.h"
#include "header/mesinkata/mesinkarakter.h"
#include "header/mesinkata/mesinkata.h"

#define PATH_MAX_LEN 256

/* PRIMITIF FILE HANDLING */

boolean buildPath(char *dest, const char *folder, const char *filename);
/* dest berukuran minimal PATH_MAX_LEN, jika melebihi maka akan mengembalikan false, jika berhasil akan mengembalikan true */

boolean isFolderExist(const char *path);
/* fungsi mengembalikan true jika path ada dan berupa folder */

boolean makeFolder(const char *path);
/* Membuat folder path. True jika berhasil atau folder sudah ada */

boolean isConfigComplete(const char *folder);
/* fungsi mengembalikan true jika file konfigurasi ada dan dapat dibuka di folder */

/* PEMBACAAN CSV */

boolean openConfigFile(const char *folder, const char *filename);
/* I.S. : Membuka folder/filename sebagai pita mesin karakter.
   F.S. : true jika berhasil; currentChar = karakter pertama file.
   Catatan: file otomatis ditutup oleh START() berikutnya
   atau openConfigFile() berikutnya. */

   boolean isEndOfFile(void);
/* true jika pita file sudah habis (currentChar == MARK). */

boolean isEndOfLine(void);
/* true jika currentChar adalah akhir baris atau akhir file. */

void nextLine(void);
/* Melewati karakter akhir baris (\n, \r\n) dan baris kosong.
   F.S. : currentChar = karakter pertama baris berikutnya yang tidak kosong,
          atau isEndOfFile(). */

void skipLine(void);
/* Melewati seluruh baris saat ini (dipakai untuk header CSV). */

boolean readField(Word *out, boolean *quoted);
/* Membaca satu field CSV ke out.
   - Spasi di sekitar field dibuang ("P1, P0" tetap terbaca "P0").
   - Field berpetik: isi di antara petik, "" dibaca sebagai ".
   - Koma pemisah ikut dikonsumsi.
   F.S. : true jika field valid; *quoted = true jika field diapit petik.
          false jika petik tidak ditutup atau ada sampah setelah petik penutup.
          Setelah membaca field terakhir, isEndOfLine() bernilai true. */

/*  PENULISAN CSV  */
void writeQuoted(FILE *f, const char *s);
/* Menulis s diapit petik ganda; petik di dalam s ditulis dua kali. */
#endif