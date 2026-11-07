#include "header/mesinkata/mesinkarakter.h"

#include <stdio.h>

static FILE *pita;
static boolean endOfTape = false;
char currentChar;

void START(void){
    if (pita != NULL && pita != stdin) fclose(pita);
    pita = stdin;
    endOfTape = false;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama pada pita posisinya adalah pada currentChar.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita.
          Jika currentChar == MARK maka EOP bernilai true,
          selain itu EOP bernilai false. */

void ADV(void){
    int c = fgetc(pita);
    if (c == EOF) {
        currentChar = MARK;
        endOfTape = true;
    } else {
        currentChar = (char) c;
    }
}
/* Pita dimajukan satu karakter.
   I.S. : currentChar bukan MARK (EOP false)
   F.S. : currentChar adalah karakter berikutnya pada pita.
          Jika currentChar == MARK maka EOP bernilai true,
          selain itu EOP bernilai false.
          Jika masukan habis, currentChar dianggap MARK dan EOT bernilai true. */

boolean EOP(void){
    return (currentChar == MARK);
}
/* Menghasilkan true jika currentChar == MARK, false jika tidak. */

boolean STARTFILE(const char *path){
    FILE *f = fopen(path, "r");
    if (f == NULL) return false;
    if (pita != NULL && pita != stdin) fclose(pita);
    pita = f;
    endOfTape = false;
    ADV();
    return true;
}
/* Mesin siap dioperasikan dengan pita berupa file pada path.
   I.S. : path terdefinisi.
   F.S. : Jika berhasil, mengembalikan true dan currentChar adalah karakter
          pertama file. Jika gagal, mengembalikan false dan pita tidak berubah. */

boolean EOT(void){
    return endOfTape;
}
/* Menghasilkan true jika pita benar-benar habis (EOF), false jika tidak. */