#include "header/F06/graph.h"
#include <stdlib.h>

// CONSTRUCTOR AND DESTRUCTOR
Graph create_graph() {
    Graph graph = {NULL, NULL, 0, 0};

    set_graph_capacity(&graph, DEFAULT_CAPACITY);
    return graph;
}

void delete_graph(Graph *graph) {
    for (int i = 0; i < graph->capacity; i++) {
        delete_vertexlist(&graph->in[i]);
        delete_vertexlist(&graph->out[i]);
    }

    free(graph->in);
    free(graph->out);
    graph->in = NULL;
    graph->out = NULL;
    graph->size = 0;
    graph->capacity = 0;
}

boolean set_graph_capacity(Graph *graph, int new_cap) {
    if (new_cap < 0 || new_cap < graph->capacity) return false;
    if (new_cap == graph->capacity) return true;

    VertexList *tempIn = malloc(new_cap * sizeof(VertexList));
    if (tempIn == NULL) return false;
    VertexList *tempOut = malloc(new_cap * sizeof(VertexList));
    if (tempOut == NULL) {
        free(tempIn);
        return false;
    }

    for (int i = 0; i < graph->capacity; i++) {
        tempIn[i] = graph->in[i];
        tempOut[i] = graph->out[i];
    }
    for (int i = graph->capacity; i < new_cap; i++) {
        tempIn[i] = create_vertexlist();
        tempOut[i] = create_vertexlist();
    }

    free(graph->in);
    free(graph->out);
    graph->in = tempIn;
    graph->out = tempOut;
    graph->capacity = new_cap;
    return true;
}

// GETTER AND SETTER
VertexList *get_in_links(Graph *graph, int id) {
    return &(graph->in[id]);
}

VertexList *get_out_links(Graph *graph, int id) {
    return &(graph->out[id]);
}

void add_links(Graph *graph, int id_source, int id_dest) {
    if (id_source <= 0 || id_dest <= 0 || id_source == id_dest) return;

    int capacity = graph->capacity;
    int max_id = id_source >= id_dest ? id_source : id_dest;

    if (max_id > capacity - 1) {
        if (!set_graph_capacity(graph, max_id + 1)) return;
    }

    VertexList *out = &graph->out[id_source];
    VertexList *in = &graph->in[id_dest];

    add_vertex(out, id_dest);
    add_vertex(in, id_source);

    if (max_id >= graph->size) graph->size = max_id + 1;
}

void remove_links(Graph *graph, int id_source, int id_dest) {
    if (!is_link_exist(graph, id_source, id_dest)) return;
    
    VertexList *out = &graph->out[id_source];
    VertexList *in = &graph->in[id_dest];

    remove_vertex(out, id_dest);
    remove_vertex(in, id_source);
}

// PREDICATES
boolean is_link_exist(Graph *graph, int id_source, int id_dest) {
    if (id_source >= graph->capacity || id_dest >= graph->capacity) return false;

    VertexList *out = &graph->out[id_source];
    VertexList *in = &graph->in[id_dest];

    if (is_vertex_exist(out, id_dest) && is_vertex_exist(in, id_source)) return true;
    else return false;
}

