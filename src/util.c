#include<stdlib.h>
#include<stdio.h>
#include"header/util/util.h"

char* Util_strdup (const char* src){
    int size = Util_strlen(src);
    char* new = Util_strndup(src,size);
    return new;
    
}

char* Util_strndup(const char* src, int size){
    char* new_string =(char*) malloc(sizeof(char)*size +1);
    if (new_string == NULL){
        return NULL;
    }
    int i = 0;
    while(size>0 && src[i]!='\0'){
        new_string[i] = src[i];
        size--;
        i++;
    }
    new_string[i] = '\0';
    return new_string;
}

void Util_strreplace(char** old_string, char* new_string){
    if (old_string != NULL && *old_string != NULL){
        free(*old_string);
    }
    *old_string = Util_strdup(new_string);
}

int Util_strlen(const char* start)
{
    const char* end = start;
    while (*end != '\0')
        ++end;
    return end - start;
}

boolean Util_streq(const char* string1, const char* string2){
    if(string1 == string2){
        return true;
    }
    if(string1==NULL || string2 == NULL){
        return false;
    }
    int i =0;
    while(string1[i]!='\0'){
        if(string1[i]!=string2[i]){
            return false;
        }
        i++;
    }
    if (string2[i]=='\0'){
        return true;
    }
    return false;
}