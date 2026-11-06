#include "header/mesinkata/mesinkarakter.h"

#include <stdio.h>

static FILE *pita;
static int retval;
void START(void){

    pita = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama pada pita posisinya adalah pada currentChar.
I.S. : sembarang
 F.S. : currentChar adalah karakter pertama pada pita.
        Jika currentChar == MARK maka EOP bernilai true,
        selain itu EOP bernilai false. */

void ADV(void){
   retval = fscanf(pita, "%c", &currentChar);
    if (retval == EOF) {
        currentChar = MARK;
        }
}
/* Pita dimajukan satu karakter.
I.S. : currentChar bukan MARK (EOP false)
F.S. : currentChar adalah karakter berikutnya pada pita.
        Jika currentChar == MARK maka EOP bernilai true,
        selain itu EOP bernilai false.
        Jika masukan habis sebelum MARK, currentChar dianggap MARK. */

boolean EOP(void){
    return (currentChar == MARK); 
}
/* Menghasilkan true jika currentChar == MARK, false jika tidak. */