#include "header/mesinkata/mesinkata.h"
#include "header/mesinkata/mesinkarakter.h"
#include <stdio.h>

/* Primitif Mesin Kata */

void CopyWord(void){
    currentWord.length = 0;

    while (currentChar != BLANK && currentChar != '\n' && currentChar != '\r' && currentChar != '\t' && currentChar != MARK) {
        if (currentWord.length < NMAX) { 
            currentWord.TabWord[currentWord.length] = currentChar;
            currentWord.length++;
        }
        ADV();
    }
}
/* Menyalin karakter dari currentChar ke currentWord hingga menemukan BLANK, MARK, atau newline.
   I.S. : currentChar bukan BLANK dan bukan MARK.
   F.S. : currentWord berisi karakter-karakter yang dibaca berturut-turut. */

void IgnoreBlanks(void){
    while ((currentChar == BLANK || currentChar == '\n' || currentChar == '\r' || currentChar == '\t') && currentChar != MARK) {
        ADV();
    }
}
/* Mengabaikan spasi, tab, dan karakter perpindahan baris.
   I.S. : currentChar sembarang.
   F.S. : currentChar bukan BLANK, '\n', atau '\r' (atau currentChar == MARK). */

void STARTWORD(void){
    START();
    IgnoreBlanks();

    if (currentChar == ';')
    {
        currentWord.length = 0;
    } else {
        CopyWord();
    }

}
/* Memulai pembacaan kata dari pita masukan standar.
   I.S. : Sembarang.
   F.S. : Spasi/newline di awal diabaikan. currentWord berisi kata pertama.
          Jika currentChar == MARK, maka EOPWORD() bernilai true. */

void ADVWORD(void){
    IgnoreBlanks();

    if (!EOPWORD())
    {
        CopyWord();
    } else {
        currentWord.length = 0;
    }
    
}
/* Memajukan pita kata ke kata berikutnya.
   I.S. : EOPWORD() bernilai false.
   F.S. : currentWord berisi kata berikutnya pada pita (spasi antar kata diabaikan).
          Jika currentChar == MARK, maka EOPWORD() bernilai true. */

boolean EOPWORD(void){
    return currentChar == ';' ;
}
/* Menghasilkan true jika currentChar == MARK, false jika tidak. */

/* FUNGSI UTILITAS KATA  */

boolean isWordEqual(Word W, char *str){
    int i = 0;

    while (i < W.length && str[i] != '\0') {
        if (W.TabWord[i] != str[i]){
            return false ;
        }
        i++ ;
    }

    return (i == W.length && str[i] == '\0');
}
/* Menghasilkan true jika isi W sama persis dengan string str. */

int wordToInt(Word W) {
    int result = 0;
    int sign = 1;
    int i = 0 ;

    if (W.length == 0) return 0; // Jika kata kosong
    if (i == W.length) return 0; // Tidak ada digit yang dapat dikonversi

    if (W.TabWord[0] == '-') {
        sign = -1;
        i++;
    } else if (W.TabWord[0] == '+') {
        i++;
    }

    for (i = 0 ; i < W.length; i++) {
        if (W.TabWord[i] >= '0' && W.TabWord[i] <= '9') {
            result = result * 10 + (W.TabWord[i] - '0');
        } else {
            return 0;
        }
    }

    return result * sign;
}
/* Mengonversi currentWord yang berisi karakter angka menjadi nilai integer. */
