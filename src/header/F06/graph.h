#ifndef GRAPH_H
#define GRAPH_H

#include <boolean.h>
#define DEFAULT_CAPACITY 5

// adt dynamic list untuk link per node
typedef struct {
    int *linked;
    int capacity;
    int nEff;
} LinkList;

// index based hash map adjacency list
typedef struct {
    LinkList *out;            // edges menuju keluar page
    LinkList *in;             // edges menuju ke dalam page (backlink)
    int capacity;
    int nEff;
} Graph;

// -------------- ADT LINKS --------------
// CONSTRUCTOR AND DESTRUCTOR 
LinkList create_linklist();
LinkList delete_linklist(LinkList *links);

// PREDICATE
boolean is_link_empty(LinkList *links);
boolean is_link_exist(LinkList *links, int id);

// SETTER
void add_edge(LinkList *links, int dest_id);
void remove_edge(LinkList *links, int dest_id);


// ----------- ADT GRAPH ------------
// CONSTRUCTOR AND DESTRUCTOR
Graph create_graph();
Graph delete_graph();

// GETTER AND SETTER
LinkList get_in_links(Graph *graph, int id);
LinkList get_out_links(Graph *graph, int id);

void add_links(Graph *graph, int id_source, int id_dest);
void remove_links(Graph *graph, int id_source, int id_dest);

#endif