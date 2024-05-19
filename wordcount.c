#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: WordCount [parameter] [input_file_name]\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    char buffer[MAX_LEN];
    int char_count = 0;
    int word_count = 0;
    int in_word = 0;
    int i;

    while (fgets(buffer, MAX_LEN, file)) {
        for (i = 0; i < strlen(buffer); i++) {
            char_count++;
            if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {
                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                word_count++;
            }
        }
    }

    fclose(file);

    if (strcmp(argv[1], "-c") == 0) {
        printf("×Ö·ûÊý£º%d\n", char_count);
    } else if (strcmp(argv[1], "-w") == 0) {
        printf("µ¥´ÊÊý£º%d\n", word_count);
    } else {
        printf("Invalid parameter.\n");
        return 1;
    }

    return 0;
}

