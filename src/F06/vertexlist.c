#include "header/F06/graph.h"
#include <stdlib.h>
#include <stdio.h>

// CONSTRUCTOR AND DESTRUCTOR
VertexList create_vertexlist() {
    VertexList res;
    res.size = 0;
    res.contents = malloc(DEFAULT_CAPACITY * sizeof(int));
    
    if (res.contents == NULL) {
        printf("Memory allocation failed\n");
        res.capacity = 0;
    }
    else res.capacity = DEFAULT_CAPACITY;

    return res;
}

void delete_vertexlist(VertexList *list) {
    list->capacity = 0;
    list->size = 0;
    free(list->contents);
}

void set_vertexlist_capacity(VertexList *list, int new_cap) {
    VertexList *temp = realloc(list, new_cap * sizeof(int));
    
    if (temp != NULL) list = temp;
    else return;
}

// PREDICATES
boolean is_link_empty(VertexList *list) {
    return (list->size == 0);
}

boolean is_link_exist(VertexList *list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->contents[i] == id) return true;
    }

    return false;
}

// SETTER
void add_link(VertexList *list, int id) {
    if (is_link_exist(list, id)) return;

    if (list->size == list->capacity) {
        if (list->capacity == 0) set_vertexlist_capacity(list, DEFAULT_CAPACITY);
        else set_vertexlist_capacity(list, list->capacity * 2);
    }

    int i = list->size - 1;
    while (i >= 0 && id < list->contents[i]) {
        list->contents[i + 1] = list->contents[i];
        i--;
    }

    list->contents[i + 1] = id;
    list->size++;
}

void remove_link(VertexList *list, int target_id) {
    int size = list->size;

    int i = 0;
    while (i < size && list->contents[i] != target_id) i++;

    if (i < size) {
        i++;
        for (; i < size; i++) {
            list->contents[i - 1] = list->contents[i];
        }

        list->size--;
    }
}
