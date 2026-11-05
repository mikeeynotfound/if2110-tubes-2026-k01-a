#include "header/F06/graph.h"
#include <stdlib.h>

// CONSTRUCTOR AND DESTRUCTOR
Graph create_graph() {
    Graph graph = {NULL, NULL, 0, 0};

    set_graph_capacity(&graph, DEFAULT_CAPACITY);
    return graph;
}

Graph delete_graph(Graph *graph) {
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
    if ((size_t)new_cap > (size_t)-1 / sizeof(VertexList)) return false;

    VertexList *tempIn = malloc((size_t)new_cap * sizeof(VertexList));
    if (tempIn == NULL) return false;
    VertexList *tempOut = malloc((size_t)new_cap * sizeof(VertexList));
    if (tempOut == NULL) {
        free(tempIn);
        return false;
    }

    for (int i = 0; i < graph->capacity; i++) {
        tempIn[i] = graph->in[i];
        tempOut[i] = graph->out[i];
    }
    for (int i = graph->capacity; i < new_cap; i++) {
        tempIn[i] = (VertexList){NULL, 0, 0};
        tempOut[i] = (VertexList){NULL, 0, 0};
    }

    free(graph->in);
    free(graph->out);
    graph->in = tempIn;
    graph->out = tempOut;
    graph->capacity = new_cap;
    return true;
}

// GETTER AND SETTER
VertexList get_in_links(Graph *graph, int id) {
}

VertexList get_out_links(Graph *graph, int id) {
}

void add_links(Graph *graph, int id_source, int id_dest) {
    if (id_source <= 0 || id_dest <= 0 || id_source == id_dest) return;

    int size = graph->size;
    int capacity = graph->capacity;
    int max_id = id_source >= id_dest ? id_source : id_dest;

    if (max_id > capacity - 1) {
        if (!set_graph_capacity(graph, id_source * 2)) return;
    }

    VertexList *out = &graph->out[id_source];
    VertexList *in = &graph->in[id_dest];

    add_link(out, id_dest);
    add_link(in, id_dest);

    if (max_id >= graph->size) graph->size = max_id + 1;
}

void remove_links(Graph *graph, int id_source, int id_dest) {
    
}
