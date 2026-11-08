#include "header/F07/multilist.h"
#include <stdlib.h>

#define MULTILIST_DEFAULT_CAPACITY 8

// helper string (tanpa string.h)
static int ml_strlen(const char *s) {
    int length = 0;

    while (s[length] != '\0') length++;
    return length;
}

static void ml_strcpy(char *dest, const char *src) {
    while (*src != '\0') *dest++ = *src++;
    *dest = '\0';
}

// array head hanya tumbuh, tidak pernah menyusut
static boolean set_page_capacity(Multilist *ml, int new_cap) {
    if (new_cap <= ml->page_capacity) return true;

    TagRelation **temp = malloc(new_cap * sizeof(TagRelation *));
    if (temp == NULL) return false;

    for (int i = 0; i < ml->page_capacity; i++) temp[i] = ml->page_head[i];
    for (int i = ml->page_capacity; i < new_cap; i++) temp[i] = NULL;

    free(ml->page_head);
    ml->page_head = temp;
    ml->page_capacity = new_cap;
    return true;
}

// CONSTRUCTOR AND DESTRUCTOR
Multilist create_multilist() {
    Multilist ml = {NULL, NULL, 0};

    set_page_capacity(&ml, MULTILIST_DEFAULT_CAPACITY);
    return ml;
}

void delete_multilist(Multilist *ml) {
    Tag *tag = ml->tag_head;

    // semua relasi bisa dibebaskan lewat rantai tag
    while (tag != NULL) {
        Tag *nextTag = tag->next;
        TagRelation *rel = tag->head;

        while (rel != NULL) {
            TagRelation *nextRel = rel->next_tag;
            free(rel);
            rel = nextRel;
        }

        free(tag);
        tag = nextTag;
    }

    free(ml->page_head);
    ml->tag_head = NULL;
    ml->page_head = NULL;
    ml->page_capacity = 0;
}

// KATALOG TAG
Tag *add_tag(Multilist *ml, int tag_id, const char *name) {
    if (tag_id <= 0 || name == NULL) return NULL;
    if (ml_strlen(name) > TAG_NAME_MAX) return NULL;
    if (find_tag_by_id(ml, tag_id) != NULL) return NULL;

    Tag *tag = malloc(sizeof(Tag));
    if (tag == NULL) return NULL;

    tag->id = tag_id;
    ml_strcpy(tag->name, name);
    tag->head = NULL;
    tag->next = ml->tag_head;
    ml->tag_head = tag;
    return tag;
}

Tag *find_tag_by_id(Multilist *ml, int tag_id) {
    for (Tag *tag = ml->tag_head; tag != NULL; tag = tag->next) {
        if (tag->id == tag_id) return tag;
    }

    return NULL;
}

boolean delete_tag(Multilist *ml, int tag_id) {
    Tag **link = &ml->tag_head;
    while (*link != NULL && (*link)->id != tag_id) {
        link = &(*link)->next;
    }

    Tag *tag = *link;
    if (tag == NULL) return false;

    // lepas semua relasi tag ini dari rantai halaman masing-masing
    TagRelation *rel = tag->head;
    while (rel != NULL) {
        TagRelation *nextRel = rel->next_tag;

        TagRelation **pageLink = &ml->page_head[rel->page_id];
        while (*pageLink != rel) pageLink = &(*pageLink)->next_page;
        *pageLink = rel->next_page;

        free(rel);
        rel = nextRel;
    }

    *link = tag->next;
    free(tag);
    return true;
}

// RELASI HALAMAN-TAG
boolean attach_tag(Multilist *ml, int page_id, int tag_id) {
    if (page_id <= 0) return false;

    Tag *tag = find_tag_by_id(ml, tag_id);
    if (tag == NULL) return false;

    if (page_id >= ml->page_capacity) {
        if (!set_page_capacity(ml, page_id + 1)) return false;
    }

    TagRelation *rel = malloc(sizeof(TagRelation));
    if (rel == NULL) return false;

    rel->page_id = page_id;
    rel->tag = tag;

    rel->next_page = ml->page_head[page_id];
    ml->page_head[page_id] = rel;

    rel->next_tag = tag->head;
    tag->head = rel;
    return true;
}

boolean detach_tag(Multilist *ml, int page_id, int tag_id) {
    if (page_id <= 0 || page_id >= ml->page_capacity) return false;

    TagRelation **link = &ml->page_head[page_id];
    while (*link != NULL && (*link)->tag->id != tag_id) {
        link = &(*link)->next_page;
    }

    TagRelation *rel = *link;
    if (rel == NULL) return false;

    *link = rel->next_page;

    TagRelation **tagLink = &rel->tag->head;
    while (*tagLink != rel) tagLink = &(*tagLink)->next_tag;
    *tagLink = rel->next_tag;

    free(rel);
    return true;
}

boolean is_tag_attached(Multilist *ml, int page_id, int tag_id) {
    if (page_id <= 0 || page_id >= ml->page_capacity) return false;

    for (TagRelation *rel = ml->page_head[page_id]; rel != NULL; rel = rel->next_page) {
        if (rel->tag->id == tag_id) return true;
    }

    return false;
}

void detach_page(Multilist *ml, int page_id) {
    if (page_id <= 0 || page_id >= ml->page_capacity) return;

    TagRelation *rel = ml->page_head[page_id];
    while (rel != NULL) {
        TagRelation *nextRel = rel->next_page;

        TagRelation **tagLink = &rel->tag->head;
        while (*tagLink != rel) tagLink = &(*tagLink)->next_tag;
        *tagLink = rel->next_tag;

        free(rel);
        rel = nextRel;
    }

    ml->page_head[page_id] = NULL;
}
