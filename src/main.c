#include <string.h>
#include <stdio.h>
#include "install.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Please provide an argument. Use `tskr --help` to see available commands\n");
		return -1;
	}

	if (!strcmp(argv[1], "init")) {
		if (argc < 3) {
			fprintf(stderr, "Please provide a name for the log\n");
			return -1;
		}

		printf("Created file: `%s.dmp`\n", argv[2]);
	
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
