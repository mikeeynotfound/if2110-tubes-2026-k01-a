
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include"header/block_notes/blocknotes.h"
#define Nil NULL

typedef struct Page {
    int parentID;
    int ID;
    char* Judul;
    List Block;
} Page;

typedef Page Eltype;

typedef struct TreeNode {
    Eltype data;
    struct TreeNode* firstChild;
    struct TreeNode* nextSibling;
} TreeNode;

/* Tree */
TreeNode* createTree();
int findTree(TreeNode* tree, int Id);
TreeNode* giveTree(TreeNode* tree, int Id);
void addChild(TreeNode* parent, Eltype child);
void displayTree(TreeNode* root, int i);

/* Page */
Page createPage(char* judul);
void pageAdd(int parentId, char* judul, TreeNode* root);
void pageView(int Id, TreeNode* root);
void pageTitle(int id, char* judulPengganti, TreeNode* root);
void pageMove(int id, int parentIdBaru, TreeNode* root);
void pageDelete(int id, TreeNode* root);

#endif
