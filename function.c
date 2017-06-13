#include "main.h"

char *input()
{
	char *path = malloc(sizeof(char) * MAX_PATH);
	if (path == NULL) {
		return NULL;
	}
	fgets(path, MAX_PATH, stdin);
	path[slen(path)] = '\0';
	return path;
}

int check(const char *path, char* del)
{
	int index;
	int flg = 1, flg2 = 1;
	char arr[] = {'\\', ':', '\n', '\0', del[0]};
	if (slen(path) > MAX_PATH) {
		return -1;
	}
	index = sspn(path, del);
	if (index != 0) {
		return index;
	}
	for (int i = 0; path[i] != '\0'; i++) {
		if (path[i] == del[0] && flg2 == 0) {
			flg = 1;
			flg2 = 1;
		} else if (path[i] == del[0] && flg2 == 1) {
			return i + 1;
		}
		if (path[i] == arr[1] && flg2 == 1) {
			if (path[i - 1] >= 'a' && path[i - 1] <= 'z') {
				flg = 0;
			} else if (path[i - 1] >= 'A' && path[i - 1] <= 'Z') {
				flg = 0;
			}
			if (flg == 0 && path[i + 1] == arr[0]) {
				flg2 = 0;
			} else {
				return i + 1;
			}
		} else if (path[i] == arr[0]) {
			if (path[i - 1] == arr[1]) {
				if (flg == 1) {
					return i + 1;
				}
			} else if (path[i - 1] >= 'a' && path[i - 1] <= 'z') {
				if (flg == 1) {
					return i + 1;
				}
			} else if (path[i - 1] >= 'A' && path[i - 1] <= 'Z') {
				if (flg == 1) {
					return i + 1;
				}
			} else {
				return i + 1;
			}
			for (int j = 2; j < 5; j++) {
				if (path[i + 1] == arr[j]) {
					return i + 1;
				}
			}
		}
	}
	return 0;
}

int check_delim(char *del)
{
	char arr[] = {'+', ':', ' '};
	int index = 1;
	for (int i = 0; i < slen(arr); i++) {
		if (del[0] == arr[i]) {
			index = 0;
			return index;
		}
	}
	return index;
}

char *process(char *path, char *dir1, char *dir2, char *del)
{
	char *new_path = malloc(sizeof(char) * MAX_PATH), **dir;
	if (new_path == NULL) {
		return NULL;
	}
	int step = 0, step_swap;
	dir = stok(path, del);
	if (dir == NULL) {
		return NULL;
	}
	for (int i = 0; i < dir_n; i++) {
		if (scmp(dir[i], dir1) != -1) {
			step_swap = scmp(dir[i], dir1);
			scpy(dir2, &new_path[step]);
			scpy(&dir[i][step_swap], &new_path[slen(new_path)]);
			if (i != dir_n - 1) {
				new_path[slen(new_path)] = del[0];
				step = slen(new_path);
			}
			continue;			
		}
		scpy(dir[i], &new_path[step]);
		if (i != dir_n - 1) {
			new_path[slen(new_path)] = del[0];
			step = slen(new_path);
		}
	}
	return new_path;
}

int output(char *path, int index)
{
	int back = 0;
	if (path == NULL) {
		printf("Memory error");
		back = 1;
	} else if (index == -2) {
		printf("New path: %s\n", path);
	} else if (index == -1) {
		printf("String too long");
		back = 1;
	} else if (index > 0) {
		printf("Error symbol #: %d\n", index);
		back = 1;
	}
	return back;
}
