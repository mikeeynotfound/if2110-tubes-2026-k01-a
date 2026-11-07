#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include "header/boolean.h"

/* MESIN KARAKTER */
/* Pita karakter dibaca dari masukan standar dan diakhiri karakter MARK. */
#define MARK ';'

/* State Mesin Karakter */
extern char currentChar;

void START(void);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama pada pita posisinya adalah pada currentChar.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita.
          Jika currentChar == MARK maka EOP bernilai true,
          selain itu EOP bernilai false. */

void ADV(void);
/* Pita dimajukan satu karakter.
   I.S. : currentChar bukan MARK (EOP false)
   F.S. : currentChar adalah karakter berikutnya pada pita.
          Jika currentChar == MARK maka EOP bernilai true,
          selain itu EOP bernilai false.
          Jika masukan habis sebelum MARK, currentChar dianggap MARK. */

boolean EOP(void);
/* Menghasilkan true jika currentChar == MARK atau mencapai EOF (End of File), false jika tidak. */

boolean STARTFILE(const char *path);
/* Membuka file pada path sebagai pita. Mengembalikan true jika berhasil,
   false jika file tidak dapat dibuka. */

boolean EOT(void);
/* true jika pita benar-benar habis (EOF), tidak bertemu MARK. */
#endif
