#include "header/main.h"

#include <stdio.h>

int main(void) {
  boolean isRunning = true;

  TreeNode *tree = createTree();
  Graph *graph = create_graph();
  Multilist ml = create_multilist();

  puts("Tugas Besar IF2110 AP2 2026/2027");

  while (isRunning) {
    printf(">> ");
    STARTWORD();
    printf("\n");

    Word w = currentWord;

    if (isWordEqual(w, "QUIT")) {
      isRunning = false;
    }
    else if (isWordEqual(w, "per fitur")) {
      continue;
    }
    else {
      continue;
    }
  }

  delete_multilist(&ml);
  delete_graph(graph);

  return 0;
}
