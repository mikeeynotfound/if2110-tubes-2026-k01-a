#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"header/blocknotes.h"

static AddressBlock blocknotes_createNode(char* keterangan, short id);

static boolean blocknotes_isEmpty(BlockNotes block);

static short blocknotes_length(BlockNotes block);

static boolean blocknotes_deallocateNode(AddressBlock block);