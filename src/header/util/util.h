#ifndef UTIL_H
#define UTIL_H

#include"header/boolean.h"

char* Util_strdup (const char* src);

char* Util_strndup(const char* src, int size);

void Util_strreplace(char** old_string, char* new_string);

boolean Util_streq(const char* string1, const char* string2);


#endif
