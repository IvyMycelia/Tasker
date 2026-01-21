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

int install() {
	/* === HOME DIRECTORY */
        char* home = getenv("HOME");            // Linux / MacOS
        char* appdata = getenv("APPDATA");      // Windows



	/* === BASE FOLDER === */
        char base_path[512];
	#ifdef _WIN32
        	snprintf(base_path, sizeof(base_path), "%s/.tskr", appdata);
	#else
        	snprintf(base_path, sizeof(base_path), "%s/.tskr", home);
	#endif
        printf("Creating base folder at %s\n", base_path);
        if (MKDIR(base_path) != 0) {
                if (errno != EEXIST) {
			perror("Failed to create base folder");
			return 1;
		}
        } 
	else { 
		printf("Created base folder\n"); 
	}
	


	/* === SETTINGS FOLDER === */
	char settings_path[512];
	snprintf(settings_path, sizeof(settings_path), "%s/settings", base_path);
	printf("Creating settings folder at %s\n", settings_path);
	if (MKDIR(settings_path) != 0) {
		if (errno != EEXIST) {
			perror("Failed to create settings folder");
			return 2;
		}
	} 
	else {
		printf("Created settings folder\n");
	}



	/* === CACHE FOLDER === */
	char cache_path[512];
	snprintf(cache_path, sizeof(cache_path), "%s/cache", base_path);
	printf("Creating cache folder at %s\n", cache_path);
        if (MKDIR(cache_path) != 0) {
                if (errno != EEXIST) {
			perror("Failed to create cache folder");
			return 3;
		}
        }
	else {
		printf("Created cache folder\n");
	}



	/* === LOGS FOLDER === */
        char logs_path[512];
        snprintf(logs_path, sizeof(logs_path), "%s/logs", base_path);
        printf("Creating logs folder at %s\n", logs_path);
        if (MKDIR(logs_path) != 0) {
                if (errno != EEXIST) {
			perror("Failed to create logs folder");
        		return 4;
		}
	}
	else {
		printf("Created logs folder\n");
	}



	/* === SETTINGS CONFIG FILE === */
        char cfg_path[512];
        snprintf(cfg_path, sizeof(cfg_path), "%s/settings.conf", settings_path);

        FILE *cfg = fopen(cfg_path, "a");
        if (!cfg) { 
		perror("Failed to create settings.conf file");
		return 5;
	}
	else fclose(cfg);



	/* === COMMANDS SOURCE FILE === */
	char cmd_cfg_path[512];
	snprintf(cmd_cfg_path, sizeof(cmd_cfg_path), "%s/commands.src", settings_path);

	FILE *cmd_cfg = fopen(cmd_cfg_path, "a");
	if (!cmd_cfg) {
		perror("Failed to create commands.src file");
		return 6;
	}
	else fclose(cmd_cfg);


	return 0;
}
