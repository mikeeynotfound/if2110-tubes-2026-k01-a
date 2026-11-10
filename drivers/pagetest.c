#include "header/page/page.h"

int main(){
  TreeNode* a = createTree();
  Multilist b = create_multilist();

  pageAdd(0, "Morning Star", a);
  pageAdd(0, "Halo Semua", a);
  pageAdd(1, "Muahhh", a);

  displayTree(a, 0);
  printf("\n");

  pageView(3, a, &b);
  printf("\n");

  pageMove(3, 2, a);
  displayTree(a, 0);
  printf("\n");

  pageTitle(2, "Miraculous Ladybug", a);
  displayTree(a,0);
  printf("\n");

  printPath(a, 2);
  printf("\n");

  pageStats(a, 2);
  printf("\n");

  pageDeleteConfirmation(2, a);
  pageDelete(2, a);
  displayTree(a,0);
  printf("\n");

  pageAdd(100, "Muahhh", a);
  pageView(100, a, &b);
  pageTitle(100, "Miraculous Ladybug", a);
  pageDelete(100, a);
  pageDelete(0, a);
  pageMove(100, 2, a);
  pageMove(3, 100, a);
}