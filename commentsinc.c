#include <stdio.h>
#include <string.h>

void check_comments(const char *code) {
    int i = 0;
    int single_line = 0, multi_line = 0;

    while (code[i] != '\0') {
        if (code[i] == '/' && code[i + 1] == '/') {
            single_line = 1;
            break;
        }
        else if (code[i] == '/' && code[i + 1] == '*') {
            multi_line = 1;
            break;
        }
        i++;
    }

    if (single_line) {
        printf("Single-line comment found.\n");
    } else if (multi_line) {
        printf("Multi-line comment found.\n");
    } else {
        printf("No comments found.\n");
    }
}

int main() {
    char code[256];

    printf("Enter a line of code: ");
    fgets(code, sizeof(code), stdin);

    check_comments(code);

    return 0;
}
