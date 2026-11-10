#include <stdio.h>
#include <stdlib.h>
#include "header/page/page.h"

int id_maker = 0;

TreeNode* createTree(){
    TreeNode* b = malloc(sizeof(TreeNode));
    b->data.Block = 0;
    b->data.Judul = "Workspace";
    b->data.ID = 0;
    b->firstChild = Nil;
    b->nextSibling = Nil;
    return b;
}

int findTree(TreeNode* tree, int Id){
    if(tree == Nil) return 0;
    else{
        if(tree->data.ID == Id) return 1;
        else return findTree(tree->firstChild, Id) || findTree(tree->nextSibling, Id);
    }
}

TreeNode* giveTree(TreeNode* tree, int Id){
    if(!findTree(tree, Id)) return Nil;

    if(Id == tree->data.ID) return tree;
    else if(findTree(tree->firstChild, Id)) return giveTree(tree->firstChild, Id);
    else return giveTree(tree->nextSibling, Id);
}

void addChild(TreeNode* parent, Eltype child){
    TreeNode* a = createTree();
    a->data = child;
    a->data.parentID = parent->data.ID;
    if(parent->firstChild != Nil){
        TreeNode* prev = parent;
        TreeNode* b = parent->firstChild;
        while(b->data.ID < child.ID && b->nextSibling != Nil){
            prev = b;
            b = b->nextSibling;
        }
        if(prev == parent){
            if(b->data.ID > child.ID){
                prev->firstChild = a;
                a->nextSibling = b;
            } else{
                b->nextSibling = a;
            }
        } else{
            if(b->data.ID > child.ID){
                prev->nextSibling = a;
                a->nextSibling = b;
            } else{
                b->nextSibling = a;
            }
        }
    } else{
        parent->firstChild = a;
    }
}

void displayTree(TreeNode* a, int i) {
    if (a == NULL) {
        return;
    }
    for(int j = 0; j < i; j++){
        printf("  ");
    }
    printf("[P%d] %s\n", a->data.ID, a->data.Judul);
    TreeNode* child = a->firstChild;
    while (child != NULL) {
        displayTree(child, i+1);
        child = child->nextSibling;
    }
}

void detachNode(TreeNode* node, TreeNode* root){
    TreeNode* parent = giveTree(root, node->data.parentID);
    if(parent == Nil) return;

    if(parent->firstChild == node){
        parent->firstChild = node->nextSibling;
    } else{
        TreeNode* prev = parent->firstChild;
        while(prev != Nil && prev->nextSibling != node){
            prev = prev->nextSibling;
        }
        if(prev != Nil) prev->nextSibling = node->nextSibling;
    }
    node->nextSibling = Nil;
}

void freeSubtree(TreeNode* n){
    TreeNode* child = n->firstChild;
    while(child != Nil){
        TreeNode* next = child->nextSibling;
        freeSubtree(child);
        child = next;
    }
    free(n);
}

Page createPage(char* judul){
    Page a;
    a.ID = id_maker + 1;
    a.Judul = judul;
    a.Block = 0;
    a.parentID = 0;
    id_maker++;
    return a;
}

void pageAdd(int parentId, char* judul, TreeNode* root){
    if(findTree(root, parentId)){
        TreeNode* p = giveTree(root, parentId);
        Page b = createPage(judul);
        addChild(p, b);
    } else{
        printf("Halaman tidak dapat dibuat: parent P%d tidak ditemukan.\n", parentId);
    }
}

void pageView(int id, TreeNode* root){
    if(findTree(root, id)){
        TreeNode* a = giveTree(root, id);
        Page b = a->data;
        printf("[P%d] %s. Parents: P%d\n", b.ID, b.Judul, b.parentID);
    } else{
        printf("Halaman tidak ada\n");
    }
}

void pageTitle(int id, char* judulPengganti, TreeNode* root){
    if(findTree(root, id)){
        TreeNode* a = giveTree(root, id);
        a->data.Judul = judulPengganti;
    } else{
        printf("Halaman tidak ada\n");
    }
}

void pageMove(int id, int parentIdBaru, TreeNode* root){
    if(id == 0){
        printf("Halaman tidak dapat dipindahkan: Workspace.\n");
        return;
    }

    TreeNode* node = giveTree(root, id);
    if(node == Nil){
        printf("Halaman tidak ada\n");
        return;
    }

    TreeNode* parentBaru = giveTree(root, parentIdBaru);
    if(parentBaru == Nil){
        printf("Halaman tidak dapat dipindahkan: parent P%d tidak ditemukan.\n", parentIdBaru);
        return;
    }
    if(parentIdBaru == id || findTree(node->firstChild, parentIdBaru)){
        printf("Halaman tidak dapat dipindahkan: P%d tidak boleh dipindah ke dalam dirinya sendiri atau keturunannya.\n", id);
        return;
    }

    Eltype data = node->data;
    TreeNode* anak = node->firstChild;   

    detachNode(node, root);
    free(node);                     

    addChild(parentBaru, data);
    TreeNode* baru = giveTree(parentBaru, id);
    baru->firstChild = anak;
}
void pageDelete(int id, TreeNode* root){
    if(id == 0){
        printf("Halaman tidak dapat dihapus: Workspace (P0) adalah root.\n");
        return;
    }
    TreeNode* node = giveTree(root, id);
    if(node == Nil){
        printf("Halaman tidak ada\n");
        return;
    }
    
    TreeNode* parent = giveTree(root, node->data.parentID);
    if(parent == Nil) return;

    if(parent->firstChild == node){
        parent->firstChild = node->nextSibling;
    } else{
        TreeNode* prev = parent->firstChild;
        while(prev != Nil && prev->nextSibling != node){
            prev = prev->nextSibling;
        }
        if(prev != Nil) prev->nextSibling = node->nextSibling;
    }
    node->nextSibling = Nil;

    freeSubtree(node);
}