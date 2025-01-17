#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void error(FILE *file) {
    if (file == NULL) {
      perror("Error opening source file");
      exit(EXIT_FAILURE);
    }
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    error(src);

    FILE *dest = fopen(destination, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
	while (fgets(buffer, BUFFER_SIZE, src) != NULL) {
    	fputs(buffer, dest);
	}
	fputs("\n", dest);


    fclose(src);
    fclose(dest);
}

void append_to_file(const char *filename, const char *text) {
    FILE *file = fopen(filename, "a");
    error(file);

    fprintf(file, "%s\n", text);
    fclose(file);
}

void print_file_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    error(file);

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file_path> <string_to_append> <copy_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filePath = argv[1];
    const char *textToAppend = argv[2];
    const char *copyPath = argv[3];

    copy_file(filePath, copyPath);

    append_to_file(copyPath, textToAppend);

    printf("Content of the new file after appending the string:\n");
    print_file_content(copyPath);

    return EXIT_SUCCESS;
}
