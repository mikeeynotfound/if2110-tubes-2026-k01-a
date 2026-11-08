#include"header/block_notes/blocknotes.h"
#include"header/util/util.h"
#include<stdio.h>
#include"header/boolean.h"
static void test_blocknotes(){
    List blocknotes;
    int id = 1;
    unsigned char txt = 0;
    unsigned char check = 1;
    AddressBlock p = NULL;
    blocknotes_init(&blocknotes);
    if(blocknotes == NULL){
        printf("Blocknotes INIT : Success\n\n");
    }
    else{
        printf("Blocknotes INIT : Failed\n\n");
    }

    List block_2;

    blocknotes_init(&block_2);
    if(block_2 == NULL){
        printf("block_2 INIT : Success\n");
    }
    else{
        printf("block_2 INIT : Failed\n");
    }

    // Add Pas Kosong Normal 
    if(blocknotes_add_block(&blocknotes,"Bawa Hati",txt,1,&id)){
        p = blocknotes;
        int length = blocknotes_length(blocknotes);
        if ( length == 1 && Util_streq(p->keterangan,"Bawa Hati")){
            printf("Add Block TXT : Success\n\n");
        }
        else{
            printf("Add Block TXT : Failed\n\n");
            printf("%d\n",length);
        }
    }
    else {
        printf("Add Block TXT : Failed\n\n");
    }
    blocknotes_printblock(blocknotes);
    
    // Add di awal Pas Udah ada 1 Di Depan Tapi
    if(blocknotes_add_block(&blocknotes,"Bawa Budi",check,1,&id)){
        int length = blocknotes_length(blocknotes);
        if ( length == 2 && Util_streq(p->keterangan,"Bawa Budi")){
            printf("Add Block Check : Success\n\n");
        }
        else{
            printf("Add Block Check : Failed\n\n");
            printf("%d\n",length);
        }
    }
    else {
        printf("Add Block Check : Failed\n");
    }
    blocknotes_printblock(blocknotes);
    
    // Add Out of Bound Pas Masih Kosong
    if(blocknotes_add_block(&block_2,"Bawa Hati_2",txt,2,&id)){
        p = block_2;
        int length = blocknotes_length(block_2);
        if ( length == 1 && Util_streq(p->keterangan,"Bawa Hati_2")){
            printf("Add Block TXT out of bound : Failed\n\n");
        }
        else{
            printf("Add Block TXT out of bound : SUCCESS\n\n");
        }
    }
    else {
        printf("Add Block TXT out of bound : SUCCESS\n\n");
    }
    blocknotes_printblock(block_2);

    // Add Biasa pas kosong
    if(blocknotes_add_block(&block_2,"Bawa Hati_2",txt,1,&id)){
        p = block_2;
        int length = blocknotes_length(block_2);
        if ( length == 1 && Util_streq(p->keterangan,"Bawa Hati_2")){
            printf("Add Block TXT : Success\n\n");
        }
        else{
            printf("Add Block TXT : Failed\n\n");
            printf("%d\n",length);
        }
    }
    else {
        printf("Add Block TXT : Failed\n\n");
    }
    blocknotes_printblock(block_2);

    //Add di tengah
    if(blocknotes_add_block(&blocknotes,"Bawa Bujank",check,2,&id)){
        p = blocknotes;
        p = p->next;
        int length = blocknotes_length(blocknotes);
        if ( length == 3 && Util_streq(p->keterangan,"Bawa Bujank")){
            printf("Add Block Check : Success\n\n");
        }
        else{
            printf("Add Block Check : Failed\n\n");
            printf("%d\n",length);
        }
    }
    else {
        printf("Add Block Check : Failed\n");
    }
    blocknotes_printblock(blocknotes);

    //Add di tengah
    if(blocknotes_add_block(&blocknotes,"Bawa Budum",check,4,&id)){
        p = blocknotes;
        p = p->next;
        p = p->next;
        p = p->next;
        int length = blocknotes_length(blocknotes);
        if ( length == 4 && Util_streq(p->keterangan,"Bawa Budum")){
            printf("Add Block Check : Success\n\n");
        }
        else{
            printf("Add Block Check : Failed\n\n");
            printf("%d\n",length);
        }
    }
    else {
        printf("Add Block Check : Failed\n");
    }
    blocknotes_printblock(blocknotes);

    if(blocknotes_check_block(&blocknotes,1)){
        printf("CHECK BLOCK in TEXT TYPE : FAILED\n\n");
    }
    else{
        printf("CHECK BLOCK in TEXT TYPE : SUCCESS\n\n");
    }

    if(blocknotes_check_block(&blocknotes,2)){
        if(p->checked == true){
            printf("CHECK BLOCK in CHECK TYPE : SUCCESS\n\n");
        }
        else{
            printf("CHECK BLOCK in CHECK TYPE : FAILED\n\n");
        }
    }
    else{
        printf("CHECK BLOCK in CHECK TYPE : FAILED\n\n");
    }

    blocknotes_printblock(blocknotes);

    if(blocknotes_check_block(&blocknotes,2)){
        if(p->checked == false){
            printf("UNCHECK BLOCK in CHECK TYPE : SUCCESS\n\n");
        }
        else{
            printf("UNCHECK BLOCK in CHECK TYPE : FAILED\n\n");
        }
    }
    else{
        printf("UNCHECK BLOCK in CHECK TYPE : FAILED\n\n");
    }
    
    blocknotes_printblock(blocknotes);
    
    if(blocknotes_edit_keterangan_block(&blocknotes,1,"Bawa Anji")){
        p = blocknotes;
        p = p->next;
        p = p->next;
        int length = blocknotes_length(blocknotes);
        if (length==4 && Util_streq(p->keterangan,"Bawa Anji")){
            printf("Edit Keterangan Block Success\n");
        }
        else{
            printf("Edit Keterangan Block Failed\n");
            printf("%d\n",length);
        }
    }
    else{
        printf("Edit Keterangan Block Failed\n");
    }
    
    blocknotes_printblock(blocknotes);

    if(blocknotes_edit_keterangan_block(&blocknotes,3,"Bawa Anji")){
        printf("Edit Keterangan Block Not Exist FAILED\n");
        
    }
    else{
        printf("Edit Keterangan Block Not Exist Success\n");
    }
    
    if(blocknotes_move_block(&blocknotes,10,2)){
        printf("Move Block Out of Bound FAILED\n");
    }
    else{
        printf("Move Block Out of Bound SUCCESS\n");
    }

    if(blocknotes_move_block(&blocknotes,1,20)){
        printf("Move Block ID not Found FAILED\n");
    }
    else{
        printf("Move Block ID not Found SUCCESS\n");
    }

    if(blocknotes_move_block(&blocknotes,1,4)){
        if(Util_streq(blocknotes->keterangan,"Bawa Bujank")){
            printf("Move Block SUCCESS\n");
        }
        else{
            printf("Move Block Failed\n");
        }
    }
    else{
        printf("Move Block Failed\n");
    }
    blocknotes_printblock(blocknotes);

    if(blocknotes_delete_block(&blocknotes,10)){
            printf("Delete Block out of bound Failed\n");
    }
    else{
        printf("Delete Block out of bound success\n");
    }

    if(blocknotes_delete_block(&blocknotes,4)){
        int length = blocknotes_length(blocknotes);
        if(length==3 && blocknotes->id ==2){
            printf("Delete Block awal success\n");
        }
        else{
            printf("Delete Block awal Failed\n");
        }
    }
    else{
        printf("Delete Block awal failed\n");
    }
    blocknotes_printblock(blocknotes);
    
    if(blocknotes_delete_block(&blocknotes,1)){
        int length = blocknotes_length(blocknotes);
        if(length==2 && blocknotes->next->id ==5){
            printf("Delete Block tengah success\n");
        }
        else{
            printf("Delete Block tengah Failed\n");
        }
    }
    else{
        printf("Delete Block tengah failed\n");
    }

    blocknotes_printblock(blocknotes);

    if(blocknotes_delete_block(&blocknotes,5)){
        int length = blocknotes_length(blocknotes);
        if(length==1){
            printf("Delete Block belakang success\n");
        }
        else{
            printf("Delete Block belakang Failed\n");
        }
    }
    else{
        printf("Delete Block belakang failed\n");
    }

    blocknotes_printblock(blocknotes);
    
    if(blocknotes_delete_block(&blocknotes,2)){
        int length = blocknotes_length(blocknotes);
        if(length==0){
            printf("Delete Block Last success\n");
        }
        else{
            printf("Delete Block Last Failed\n");
        }
    }
    else{
        printf("Delete Block Last failed\n");
    }

    blocknotes_printblock(blocknotes);

    blocknotes_deallocate(&block_2);
    blocknotes_deallocate(&blocknotes);
}

int main(){
    test_blocknotes();
    return 0;
}