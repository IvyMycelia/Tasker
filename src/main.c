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
		install();
	} 
	else {
		fprintf(stderr, "Argument not recognized: %s\n", argv[1]);
		return -1;
	}
}
