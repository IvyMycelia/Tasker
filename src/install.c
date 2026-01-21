#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#define MKDIR(path) mkdir(path, 0755)
#endif

#include <stdio.h>
#include <errno.h>

#include "install.h"

static int ensure_dir(const char *path) {
    	if (MKDIR(path) != 0 && errno != EEXIST) {
        	perror(path);
        	return 1;
    	}
    	return 0;
}

int install(void) {
    	if (init_paths() != 0) {
        	return 1;
    	}

    	if (ensure_dir(base_path))     return 2;
    	if (ensure_dir(settings_path)) return 3;
    	if (ensure_dir(cache_path))    return 4;
    	if (ensure_dir(logs_path))     return 5;

    	char cfg_path[512];
    	snprintf(cfg_path, sizeof(cfg_path), "%s/settings.conf", settings_path);
    	FILE *cfg = fopen(cfg_path, "a");
    	if (!cfg) {
        	perror("settings.conf");
        	return 6;
    	}
    	fclose(cfg);

    	char cmd_path[512];
    	snprintf(cmd_path, sizeof(cmd_path), "%s/commands.src", settings_path);
    	FILE *cmd = fopen(cmd_path, "a");
    	if (!cmd) {
        	perror("commands.src");
        	return 7;
    	}
    	fclose(cmd);

    	return 0;
}



