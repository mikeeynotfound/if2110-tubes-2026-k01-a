#ifndef GRAPH_H
#define GRAPH_H

#include "header/boolean.h"
#include "header/page/page.h"

#define DEFAULT_CAPACITY 5

// adt dynamic list untuk link per node
typedef struct {
    int *contents;
    int capacity;
    int size;
} VertexList;

// index based hash map adjacency list
typedef struct {
    VertexList *out;            // edges menuju keluar page
    VertexList *in;             // edges menuju ke dalam page (backlink)
    int size;
    int capacity;
} Graph;

// -------------- ADT LINKS --------------
// CONSTRUCTOR AND DESTRUCTOR 
VertexList create_vertexlist();
void delete_vertexlist(VertexList *list);
boolean set_vertexlist_capacity(VertexList *list, int new_cap);

// PREDICATE
boolean is_vertexlist_empty(VertexList *list);
boolean is_vertex_exist(VertexList *list, int id);

// SETTER
void add_vertex(VertexList *list, int dest_id);
void remove_vertex(VertexList *list, int dest_id);


// ----------- ADT GRAPH ------------
// CONSTRUCTOR AND DESTRUCTOR
Graph create_graph();
void delete_graph(Graph *graph);
boolean set_graph_capacity(Graph *graph, int new_cap);

// GETTER AND SETTER
VertexList *get_in_links(Graph *graph, int id);
VertexList *get_out_links(Graph *graph, int id);

void add_links(Graph *graph, int id_source, int id_dest);           // nanti bisa langsung add ke main ini
void remove_links(Graph *graph, int id_source, int id_dest);

// PREDICATES
boolean is_link_exist(Graph *graph, int id_source, int id_dest);

// -------- F06 --------
void show_links(TreeNode *root, Graph *graph, int id);              // ini buat integrasi ke main
void show_backlinks(TreeNode *root, Graph *graph, int id);

#endif