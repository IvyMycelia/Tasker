#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "install.h"
#include "list.h"

int main(int argc, char *argv[]) {
	if (init_paths() != 0) {
		fprintf(stderr, "Failed to initialize paths\n");
		return 1;
	}

	if (argc < 2) {
		fprintf(stderr, "Please provide an argument. Use `tskr --help` to see available commands\n");
		return -1;
	}

	if (!strcmp(argv[1], "init")) {
		if (argc < 3) {
			fprintf(stderr, "Please provide a name for the log\n");
			return -1;
		}
		char log_file[512];
		snprintf(log_file, sizeof(log_file), "%s/%s.tsk", logs_path, argv[2]);
		FILE *log = fopen(log_file, "a");
		if (!log) perror("Could not create log file");
		else {
			printf("Created file: `%s.tsk`\n", argv[2]);
			fclose(log);
		}
	}
	else if (!strcmp(argv[1], "list")) {
		if (list_task_logs(logs_path) != 0) {
			fprintf(stderr, "Failed to list task logs\n");
			return 1;
		}
	}
	else if (!strcmp(argv[1], "test")) {
		printf("Hello, World!\n");
	} 
	else if (!strcmp(argv[1], "install")) {
		int install_status = install();
		if (install_status != 0) {
			printf("Could not successfully install all items: ");
			switch (install_status) {
				case 1:
					printf("Failed at creating base folder\n");
					break;

				case 2:
                                        printf("Failed at creating settings folder\n");
                                        break;

				case 3:
                                        printf("Failed at creating cache folder\n");
                                        break;

				case 4:
                                        printf("Failed at creating logs folder\n");
                                        break;

				case 5:
                                        printf("Failed at creating settings.conf file\n");
                                        break;

				case 6:
                                        printf("Failed at creating commands.src file\n");
                                        break;
				
				default:
					printf("Unknown error occured :c\n");
			}
		}
	} 
	else {
		fprintf(stderr, "Argument not recognized: %s\n", argv[1]);
		return -1;
	}
}
