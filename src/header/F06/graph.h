#ifndef GRAPH_H
#define GRAPH_H

#include <boolean.h>
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
    int capacity;
    int size;
} Graph;

// -------------- ADT LINKS --------------
// CONSTRUCTOR AND DESTRUCTOR 
VertexList create_vertexlist();
void delete_vertexlist(VertexList *list);
void set_vertexlist_capacity(VertexList *list, int new_cap);

// PREDICATE
boolean is_link_empty(VertexList *list);
boolean is_link_exist(VertexList *list, int id);

// SETTER
void add_link(VertexList *list, int dest_id);
void remove_link(VertexList *list, int dest_id);


// ----------- ADT GRAPH ------------
// CONSTRUCTOR AND DESTRUCTOR
Graph create_graph();
Graph delete_graph();

// GETTER AND SETTER
VertexList get_in_links(Graph *graph, int id);
VertexList get_out_links(Graph *graph, int id);

void add_links(Graph *graph, int id_source, int id_dest);
void remove_links(Graph *graph, int id_source, int id_dest);

#endif