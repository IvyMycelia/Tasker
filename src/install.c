#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#define MKDIR(path) mkdir(path, 0755)
#endif

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "install.h"

void install() {
        char* home = getenv("HOME");            // Linux / MacOS
        char* appdata = getenv("APPDATA");      // Windows

        char base_path[512];
#ifdef _WIN32
        snprintf(base_path, sizeof(base_path), "%s/.tskr", appdata);
#else
        snprintf(base_path, sizeof(base_path), "%s/.tskr", home);
#endif
        printf("Creating base folder at %s\n", base_path);
        if (MKDIR(base_path) != 0) {
                if (errno != EEXIST) perror("Failed to create base folder");
        }
        else printf("Created base folder\n");

        char logs_path[512];
        snprintf(logs_path, sizeof(logs_path), "%s/logs", base_path);
        printf("Creating logs folder at %s\n", logs_path);
        if (MKDIR(logs_path) != 0) {
                if (errno != EEXIST) perror("Failed to create logs folder");
        }
        else printf("Created logs folder\n");

	/* === CONFIG FILE === */
        char cfg_path[512];
        snprintf(cfg_path, sizeof(cfg_path), "%s/.cfg", base_path);

        FILE *cfg = fopen(cfg_path, "a");
        if (!cfg) perror("Failed to create .cfg file");
	else fclose(cfg);

	/* === COMMAND CONFIG FILE === */
	char cmd_cfg_path[512];
	snprintf(cmd_cfg_path, sizeof(cmd_cfg_path), "%s/.cmd.cfg", base_path);

	FILE *cmd_cfg = fopen(cmd_cfg_path, "a");
	if (!cmd_cfg) perror("Failed to create .cmd.cfg file");
	else fclose(cmd_cfg);
}
