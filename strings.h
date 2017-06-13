#ifndef STRING_H
#define STRING_H
#include <stdlib.h>

int slen(const char* path);
int sspn(const char* path, char* del);
char** stok(const char* path, const char* del);
int scmp(const char* path, const char* path_2);
void scpy(const char* path, char* cpy);

#endif
