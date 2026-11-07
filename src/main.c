#include <stdio.h>
#include "tree.h"

int main(void) {
  puts("Tugas Besar IF2110 AP2 2026/2027");
  puts("Template berhasil dikompilasi dan dijalankan.");
  puts("Implementasikan inisialisasi, ADT, dan fitur sesuai spesifikasi.");

  Node* a = createTree();

  pageAdd(0, "Morning Star", a);
  pageAdd(0, "Halo Semua", a);
  pageAdd(1, "Muahhh", a);

  displayTree(a, 0);
  pageView(3, a);

  pageMove(3, 2, a);
  displayTree(a, 0);

  pageDelete(2, a);
  displayTree(a,0);

  return 0;
}
