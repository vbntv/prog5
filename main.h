#ifndef MAIN_H
#define MAIN_H
#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH 260
extern int dir_n;

char *input();
int check(const char *path, char *del);
int check_delim(char *del);
char *process(char *path, char *dir1, char *dir2, char *del);
int output(char *path, int index);

#endif
