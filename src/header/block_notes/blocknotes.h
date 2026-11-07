#ifndef BLOCK_NOTES
#define BLOCK_NOTES

/* Fitur Block Pada Notes, digunakan untuk menampilkan data dan konten dengan List Berkait*/
#include"boolean.h"
#define MAX_BLOCK 10

typedef struct BlockNotes *AddressBlock;
typedef struct BlockNotes {
    char* keterangan;
    int id;
    boolean checked;
    unsigned char type; // 1 untuk check & text; 0 untuk text only
    AddressBlock next;
} BlockNotes;

typedef AddressBlock List;

void blocknotes_init(List *block);

boolean blocknotes_is_full(List block);

boolean blocknotes_add_block(List *L, char* keterangan, unsigned char type, int posisi, int* block_id);

boolean blocknotes_edit_keterangan_block(List *L, int id_block, char* keterangan_baru);

boolean blocknotes_move_block(List *L, int new_pos, int id);

boolean blocknotes_check_block(List *L,int id_block);

boolean blocknotes_delete_block(List *block, int id_block);

void blocknotes_printblock(List L);

void blocknotes_deallocate(List* block);
#endif