#include <stdio.h>
#include <stdlib.h>

char base_path[512];
char settings_path[512];
char cache_path[512];
char logs_path[512];

int init_paths(void) {
        char *home = getenv("HOME");
        #ifdef _WIN32
                char *appdata = getenv("APPDATA");
                if (!appdata) {
                        fprintf(stderr, "APPDATA not set\n");
                        return 1;
                }
                snprintf(base_path, sizeof(base_path), "%s/.tskr", appdata);
        #else
                if (!home) {
                        fprintf(stderr, "HOME not set\n");
                        return 1;
                }
                snprintf(base_path, sizeof(base_path), "%s/.tskr", home);
        #endif

        snprintf(settings_path, sizeof(settings_path), "%s/settings", base_path);
        snprintf(cache_path,    sizeof(cache_path),    "%s/cache",    base_path);
        snprintf(logs_path,     sizeof(logs_path),     "%s/logs",     base_path);

        return 0;
}
