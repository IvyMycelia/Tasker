#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "list.h"

#ifdef _WIN32
	#include <windows.h>
#else
	#include <dirent.h>
#endif

static int has_tsk_extension(const char *name) {
	size_t len = strlen(name);
	return (len > 4 && strcmp(name + len - 4, ".tsk") == 0);
}

int list_task_logs(const char *logs_path) {
	#ifdef _WIN32
		char search_path[512];
		snprintf(search_path, sizeof(search_path), "%s\\*.tsk", logs_path);
		
		WIN32_FIND_DATAA fd;
		HANDLE h = FindFirstFileA(search_path, &fd);
		if (h == INVALID_HANDLE_VALUE) {
			perror("FindFirstFile");
			return 1;
		}

		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				printf("%s\n", fd.cFileName);
			}
		} while (FindNextFileA(h, &fd));

		FindClose(h);
	#else
		DIR *dir = opendir(logs_path);
		if (!dir) {
			perror("opendir");
			return 1;
		}

		struct dirent *ent;
		while ((ent = readdir(dir)) != NULL) {
			if (ent->d_name[0] == '.') continue;
			if (!has_tsk_extension(ent->d_name)) continue;

			printf("%s\n", ent->d_name);
		}

		closedir(dir);
	#endif
	
	return 0;
}
