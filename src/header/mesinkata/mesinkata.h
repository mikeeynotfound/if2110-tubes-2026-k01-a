#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include <stdio.h>
#include "header/boolean.h"
#include "header/mesinkata/mesinkarakter.h"

/* KONSTANTA & SYMBOL */
#define MARK ';'
#define NMAX 500
#define BLANK ' '

typedef struct Word{
    char TabWord[NMAX]; /* menyimpan kata */
    int length; /* panjang kata */
} Word;

/* variasi global*/
extern Word currentWord;
extern char currentChar;

/* Primitif Mesin Kata */
void STARTWORD(void);
/* Memulai pembacaan kata dari pita masukan standar.
   I.S. : Sembarang.
   F.S. : Spasi/newline di awal diabaikan. currentWord berisi kata pertama.
          Jika currentChar == MARK, maka EOPWORD() bernilai true. */

void ADVWORD(void);
/* Memajukan pita kata ke kata berikutnya.
   I.S. : EOPWORD() bernilai false.
   F.S. : currentWord berisi kata berikutnya pada pita (spasi antar kata diabaikan).
          Jika currentChar == MARK, maka EOPWORD() bernilai true. */

void CopyWord(void);
/* Menyalin karakter dari currentChar ke currentWord hingga menemukan BLANK, MARK, atau newline.
   I.S. : currentChar bukan BLANK dan bukan MARK.
   F.S. : currentWord berisi karakter-karakter yang dibaca berturut-turut. */

void IgnoreBlanks(void);
/* Mengabaikan spasi, tab, dan karakter perpindahan baris.
   I.S. : currentChar sembarang.
   F.S. : currentChar bukan BLANK, '\n', atau '\r' (atau currentChar == MARK). */

boolean EOPWORD(void);
/* Menghasilkan true jika currentChar == MARK, false jika tidak. */

/* --- FUNGSI UTILITAS KATA --- */

boolean isWordEqual(Word W, char *str);
/* Menghasilkan true jika isi W sama persis dengan string str. */

int wordToInt(Word W);
/* Mengonversi currentWord yang berisi karakter angka menjadi nilai integer. */

#endif