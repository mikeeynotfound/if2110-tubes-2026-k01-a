#include <stdio.h>
#include "header/graph/graph.h"

static void print_vertexlist(const VertexList *list) {
    printf("[");

    for (int i = 0; i < list->size; i++) {
        printf("P%d", list->contents[i]);

        if (i < list->size - 1) {
            printf(", ");
        }
    }

    printf("]");
}

static void print_graph(const Graph *graph) {
    printf("\n=== GRAPH ===\n");
    printf("---------\n");
    printf("Size     : %d\n", graph->size);
    printf("Capacity : %d\n", graph->capacity);

    boolean empty = true;

    for (int i = 0; i < graph->capacity; i++) {
        if (graph->out[i].size > 0 ||
            graph->in[i].size > 0) {

            empty = false;
            
            printf("---------\n");
            printf("P%d Links: ", i);
            print_vertexlist(&graph->out[i]);

            printf("\nP%d Backlinks: ", i);
            print_vertexlist(&graph->in[i]);

            printf("\n---------\n");
        }
    }

    if (empty) {
        printf("(Tidak ada link)\n");
    }

    printf("=============\n\n");
}

int main() {
    TreeNode *root = createTree();

    pageAdd(0, "Morning Star", root);
    pageAdd(1, "Halo Semua", root);
    pageAdd(1, "Muahhh", root);
    pageAdd(0, "lagi", root);
    pageAdd(2, "lagi", root);
    pageAdd(2, "lagi", root);
    pageAdd(2, "lagi", root);

    // ----------- ADT GRAPH TEST CASE ----------
    printf("--------ADT GRAPH TEST CASES--------\n");
    // TEST CASE 1
    printf("--------TEST CASE 1--------\n");
    Graph g = create_graph();

    print_graph(&g);

    // TEST CASE 2
    printf("-----------TEST CASE 2----------\n");

    add_links(&g, 1, 2);
    add_links(&g, 2, 7);
    add_links(&g, 2, 3);

    printf("is_link_exist check: ");
    if (is_link_exist(&g, 1, 2) && is_link_exist(&g, 2, 7) 
    && is_link_exist(&g, 2, 3) && !is_link_exist(&g, 2, 4)) printf("PASS\n");
    else printf("FAIL\n");

    print_graph(&g);

    // TEST CASE 3
    printf("-----------TEST CASE 3----------\n");

    add_links(&g, 1, 2);
    add_links(&g, 1, 2);
    add_links(&g, 1, 1);
    add_links(&g, 0, 2);

    print_graph(&g);

    // TEST CASE 4
    printf("-----------TEST CASE 4----------\n");

    remove_links(&g, 2, 7);
    remove_links(&g, 1, 2);
    print_graph(&g);

    printf("---------TEST CASE 5-----------\n");
    printf("P2 Links: ");
    print_vertexlist(get_out_links(&g, 2));
    printf("\nP2 Backlinks: ");
    print_vertexlist(get_in_links(&g, 2));
    printf("\n");

    printf("---------TEST CASE 6-----------\n");
    add_links(&g, 1, 2);
    add_links(&g, 4, 2);
    add_links(&g, 2, 5);
    add_links(&g, 2, 7);

    print_graph(&g);

    // -----------F06 TEST CASES-----------
    printf("-----------F06 TEST CASES-----------\n");
    add_links(&g, 1, 2);
    add_links(&g, 4, 2);
    add_links(&g, 2, 5);
    add_links(&g, 2, 7);

    printf("P2 Links: \n\n");
    show_links(root, &g, 2);

    printf("\nP2 Backlinks:\n\n");
    show_backlinks(root, &g, 2);

    printf("\nP7 Links: \n\n");
    show_links(root, &g, 7);

    printf("\nP7 Backlinks:\n\n");
    show_backlinks(root, &g, 7);

    delete_graph(&g);
    return 0;
}