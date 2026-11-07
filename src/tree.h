
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef int Blocks; // temporary

typedef struct Page {
    int parentID;
    int ID;
    char* Judul;
    Blocks Block;
} Page;

typedef Page Eltype;

typedef struct Node {
    Eltype data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

/* Tree */
Node* createTree();
int findTree(Node* tree, int Id);
Node* giveTree(Node* tree, int Id);
void addChild(Node* parent, Eltype child);
void displayTree(Node* root, int i);

/* Page */
Page createPage(char* judul);
void pageAdd(int parentId, char* judul, Node* root);
void pageView(int Id, Node* root);
void pageTitle(int id, char* judulPengganti, Node* root);
void pageMove(int id, int parentIdBaru, Node* root);
void pageDelete(int id, Node* root);

#endif
