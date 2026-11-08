#ifndef MULTILIST_H
#define MULTILIST_H

#include "header/boolean.h"

#define TAG_NAME_MAX 500

// satu node relasi, menjadi anggota dua rantai sekaligus
typedef struct Tag Tag;
typedef struct TagRelation TagRelation;

struct TagRelation {
    int page_id;
    Tag *tag;
    TagRelation *next_page;     // rantai tag pada halaman yang sama
    TagRelation *next_tag;      // rantai halaman pada tag yang sama
};

struct Tag {
    int id;
    char name[TAG_NAME_MAX + 1];
    TagRelation *head;          // rantai halaman untuk tag ini
    Tag *next;                  // katalog tag
};

// multilist = katalog tag + array head per halaman (index = page_id)
typedef struct {
    Tag *tag_head;
    TagRelation **page_head;
    int page_capacity;
} Multilist;

// CONSTRUCTOR AND DESTRUCTOR
Multilist create_multilist();
void delete_multilist(Multilist *ml);

// KATALOG TAG
Tag *add_tag(Multilist *ml, int tag_id, const char *name);
Tag *find_tag_by_id(Multilist *ml, int tag_id);
boolean delete_tag(Multilist *ml, int tag_id);

// RELASI HALAMAN-TAG
boolean attach_tag(Multilist *ml, int page_id, int tag_id);
boolean detach_tag(Multilist *ml, int page_id, int tag_id);
boolean is_tag_attached(Multilist *ml, int page_id, int tag_id);
void detach_page(Multilist *ml, int page_id);

#endif
