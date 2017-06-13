#include "main.h"

int main()
{
	char *dir1, *dir2, *delim, *path, *new_path;
	int index = 0;

	printf("Delim: ");
	delim = input();
	index = check_delim(delim);
	if (output(delim, index) == 1) {
		return 0;
	}

	printf("Path: ");
	path = input();
	index = check(path, delim);
	if (output(path, index) == 1) {
		return 0;
	}
	
	printf("Dir1: ");
	dir1 = input();
	index = check(dir1, delim);
	if (output(dir1, index) == 1) {
		return 0;
	}

	printf("Dir2: ");
	dir2 = input();
	index = check(dir2, delim);
	if (output(dir2, index) == 1) {
		return 0;
	}

	new_path = process(path, dir1, dir2, delim);
	output(new_path, -2);
	return 0;
}
