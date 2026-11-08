#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"header/block_notes/blocknotes.h"
#include"header/util/util.h"


static AddressBlock createNode(char* keterangan, unsigned char type, int* id){
    AddressBlock new = (AddressBlock) malloc(sizeof(*new));
    new->keterangan = Util_strdup(keterangan);
    new->type = type;
    new->checked = false;
    new->id = *id;
    new->next = NULL;
    (*id)++;
    
    return new;
}

static boolean isEmpty(List block)
{
    return (block==NULL);
}

int blocknotes_length(List block){
    if(isEmpty(block)){
        return 0;
    }
    else{
        AddressBlock p = block;
        int length = 0;
        while(p != NULL){
            length++;
            p = p->next;
        }
        return length;
    }
}

static void deallocateNode(AddressBlock* block){
    if (block == NULL || *block == NULL){
        return;
    } 
    if ((*block)->keterangan!=NULL){
        free((*block)->keterangan);
        (*block)->keterangan = NULL;
    }

    free(*block);
    *block = NULL;
}

void blocknotes_init(List *block){
    (*block) = NULL;
    
}

boolean blocknotes_is_full(List block){
    if(blocknotes_length(block)==MAX_BLOCK){
        return true;
    }
    else{
        return false;
    }
}

boolean blocknotes_add_block(List *L, char* keterangan, unsigned char type, int posisi, int* id){
    int len = blocknotes_length(*L);
    if(posisi<1 || posisi>len+1){
        return false;
    }

    AddressBlock p = *L;
    AddressBlock new = createNode(keterangan,type,id);

    if (posisi == 1){
        new->next = *L;
        *L = new;
        return true;
    }
    if(new!=NULL){
        int count = 1;
        while(count<posisi-1){
            p = p->next;
            count++;
        }
        AddressBlock temp = p->next;
        p->next = new;
        new->next = temp;
        return true;
    }
    return false;
}

boolean blocknotes_edit_keterangan_block(List *L, int id_block, char* keterangan_baru){
    
    if(L == NULL || (*L)==NULL){
        return false;
    }
    AddressBlock p = *L;


    while(p!=NULL && id_block!=p->id){
        p = p->next;
    }

    if (p==NULL){
        return false;
    }
    Util_strreplace(&(p->keterangan),keterangan_baru);
    return true;

}

boolean blocknotes_move_block(List *L, int new_pos, int id){
    if(L==NULL || (*L)==NULL){
        return false;
    }
    int len = blocknotes_length(*L);
    if(new_pos<1 || new_pos>len){
        return false;
    }
    int pos_now = 1;
    AddressBlock p = *L;
    while(p!=NULL && p->id != id){
        p = p->next;
        pos_now++;
    }

    if (p==NULL){
        return false;
    }
    if(pos_now==new_pos){
        return true;
    }
    //detach
    if (pos_now==1){
        p = *L;   
        *L = (*L)->next;
    }
    else{
        int count =1;
        p = *L;
        while(count<pos_now-1){
            p = p->next;
            count++;
        }
        AddressBlock temp;
        temp = p;
        p = p->next;
        temp->next = p->next;
    }
    //insert_at

    if(new_pos==1){
        p->next = *L;
        *L = p;
    }
    else{
        int count = 1;
        AddressBlock helper_pointer = *L;
        while(count<new_pos-1){
            helper_pointer = helper_pointer->next;
            count++;
        }
        AddressBlock temp; 
        temp = helper_pointer->next;
        helper_pointer->next = p;
        p->next = temp;   
    }
    return true;

}

boolean blocknotes_check_block(List *L, int id_block){
    if( L == NULL || (*L)==NULL ){
        return false;
    }
    AddressBlock p = *L;


    while(p!=NULL && id_block!=p->id){
        p = p->next;
    }

    if (p==NULL){
        return false;
    }
    if (p->type == 0){
        return false;
    }
    p->checked = !p->checked;
    return true;
}

boolean blocknotes_delete_block(List *block, int id_block){
    if(block == NULL ||*block ==NULL){
        return false;
    }

    if ((*block)->id == id_block){
        AddressBlock p = *block;
        *block = (*block)->next;
        deallocateNode(&p);
        return true;
    }
    AddressBlock p = *block;

    while(p->next!= NULL && p->next->id != id_block){
        p = p->next;
    }

    if (p->next== NULL){
        return false;
    }
    AddressBlock temp;
    temp = p;
    p = p->next;
    temp->next = p->next;
    deallocateNode(&p);
    return true;
}

void blocknotes_printblock(List L){
    if (L==NULL){
        printf("Block Masih Kosong\n");
        return;
    }
    AddressBlock p = L;
    int i = 1;
    while(p!=NULL){
        if(p->type == 0){
            printf("%d [B%d] TEXT : %s\n",i,p->id,p->keterangan);
        }
        else{
            if(p->checked == true){
                printf("%d [B%d] CHECK [X] %s\n",i,p->id,p->keterangan);
            }
            else{
                printf("%d [B%d] CHECK [ ] %s\n",i,p->id,p->keterangan);
            }
        }
        p = p->next;
        i++;
    }
}

void blocknotes_deallocate(List* block){
    if(block == NULL || (*block )==NULL){
        return;
    }
    AddressBlock p = *block;
    
    while(p!=NULL){
        AddressBlock nextblock = p->next;
        deallocateNode(&p);
        p = nextblock;
    }
    *block = NULL;
}