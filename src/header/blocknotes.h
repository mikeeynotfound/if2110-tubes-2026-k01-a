#ifndef BLOCK_NOTES
#define BLOCK_NOTES

/* Fitur Block Pada Notes, digunakan untuk menampilkan data dan konten dengan List Berkait*/
#include"boolean.h"
#define MAX_BLOCK 10

typedef struct BlockNotes *AddressBlock;
typedef struct BlockNotes {
    char* keterangan;
    boolean checked;
    unsigned char type; // 1 untuk check & text; 0 untuk text only
    char id_local;
    AddressBlock next;
} BlockNotes;

typedef AddressBlock List;

void blocknotes_init(List *block);

boolean blocknotes_is_full(List block);

boolean blocknotes_add_block(List *L, AddressBlock new_block);

boolean blocknotes_edit_keterangan_block(List L, char id_local, char* keterangan_baru);

boolean blocknotes_check_block(List L,char id_local);

boolean blocknotes_delete_block(BlockNotes* block);

void blocknotes_deallocate(AddressBlock block);
#endif