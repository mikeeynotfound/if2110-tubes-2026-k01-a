#include "header/F06/graph.h"
#include <stdlib.h>

// CONSTRUCTOR AND DESTRUCTOR
Graph create_graph() {
    Graph graph;
    graph.in = malloc(DEFAULT_CAPACITY * sizeof(VertexList));
    graph.out = malloc(DEFAULT_CAPACITY * sizeof(VertexList));
    
    if (graph.in == NULL || graph.out == NULL) {
        graph.in = NULL;
        graph.out = NULL;

        graph.size = 0;
        graph.capacity = 0;
    } 
    else {
        graph.size = 0;
        graph.capacity = DEFAULT_CAPACITY;
    }

    return graph;
}

Graph delete_graph(Graph *graph) {
    free(graph->in);
    free(graph->out);

    graph->in = NULL;
    graph->out = NULL;
}

void set_graph_capacity(Graph *graph, int new_cap) {
    VertexList *tempIn = realloc(graph->in, new_cap * sizeof(VertexList));
    VertexList *tempOut = realloc(graph->out, new_cap * sizeof(VertexList));

    if (tempIn == NULL || tempOut == NULL) return;
    
    graph->in = tempIn;
    graph->out = tempOut;
    graph->capacity = new_cap;
}

// GETTER AND SETTER
VertexList get_in_links(Graph *graph, int id) {
}

VertexList get_out_links(Graph *graph, int id) {
}

void add_links(Graph *graph, int id_source, int id_dest) {
    int size = graph->size;
    int capacity = graph->capacity;

    if (id_source > capacity - 1) set_graph_capacity(graph, id_source * 2);
    
}

void remove_links(Graph *graph, int id_source, int id_dest) {

}
