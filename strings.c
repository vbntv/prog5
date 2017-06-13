#include "strings.h"

int dir_n = 1;

int slen(const char* path)
{
	int len = 0;
	for (int i = 0; path[i] != '\0'; i++) {
		len++;
	}
	return len;
}

int sspn(const char* path, char *del)
{
	char arr[] = {'?', '"', '<', '>', '|', '/', '*'};
	for (int i = 0; path[i] != '\0'; i++) {
		for (int j = 1; j < slen(arr); j++) {
			if (path[i] == arr[j]) {
				return i + 1;
			}
		}
	}
	return 0;
}

char** stok(const char* path, const char* del)
{
	char **dir, *cpy, buf[1];
	int step = 0, j = 0;
	for (int i = 0; path[i] != '\0'; i++) {
		if (path[i] == del[0]) {
			dir_n++;
		}
	}
	dir = malloc(sizeof(char*) * dir_n);
	if (dir == NULL) {
		return NULL;
	}
	cpy = malloc(sizeof(char) * slen(path));
	if (cpy == NULL) {
		return NULL;
	}
	scpy(path, cpy);
	for (int i = 0; path[i] != '\0'; i++) {
		if (path[i] == del[0] || path[i] == '\n') {
			buf[0] = cpy[i];
			cpy[i] = '\0';
			dir[j] = malloc(sizeof(char) * slen(&cpy[step]) + 1);
			if (dir[j] == NULL) {
				free(dir);
				return NULL;
			}
			scpy(&cpy[step], dir[j]);
			step = i + 1;
			j++;
			cpy[i] = buf[0];
		}
	}
	return dir;
}

int scmp(const char* path, const char* path_2)
{
	int i;
	for (i = 0; path[i] != '\0' || path_2[i] != '\0'; i++) {
		if (path[i] == '\n' || path_2[i] == '\n') {
			break;
		} else if (path[i] == '\0' || path_2[i] == '\0') {
			return i;
		} else if (path[i] != path_2[i]) {
			return -1;	
		}
	}
	return	i;
}

void scpy(const char* path, char* cpy)
{
	int i;
	for (i = 0; path[i] != '\0'; i++) {
		if (path[i] == '\n') {
			continue;
		}
		cpy[i] = path[i];
	}
	cpy[i] = '\0';
}
