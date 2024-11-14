//code to find if a input is keyword or identifier
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Array of C keywords
const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while"
};
#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

// Function to check if a string is a keyword
int isKeyword(const char* str) {
    for (int i = 0; i < NUM_KEYWORDS; ++i) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is a valid identifier
int isIdentifier(const char* str) {
    if (!isalpha(str[0]) && str[0] != '_') {  
        return 0;
    }
    for (int i = 1; str[i] != '\0'; ++i) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[50];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

    if (isKeyword(input)) {
        printf("'%s' is a keyword.\n", input);
    } else if (isIdentifier(input)) {
        printf("'%s' is an identifier.\n", input);
    } else {
        printf("'%s' is not a valid identifier.\n", input);
    }

    return 0;
}
