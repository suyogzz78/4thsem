#include <stdio.h>
#include <string.h>

// Function Prototypes
void printPrefix(char str[]);
void printSuffix(char str[]);
void printSubstring(char str[]);

int main() {
    char str[100]; // Declare a string with a maximum length of 99 characters
    int choice;

    printf("Enter the string: ");
    scanf("%99s", str); // Read the string input, limiting to 99 characters

    printf("\n1. Prefix Combination\n2. Suffix Combination\n3. Substring Combination\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printPrefix(str);
            break;
        case 2:
            printSuffix(str);
            break;
        case 3:
            printSubstring(str);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid option. Exiting.\n");
            break;
    }

    return 0;
}

// Function to print all prefixes of the string
void printPrefix(char str[]) {
    printf("\nPrefix Combinations are:\n");
    for (int i = 1; i <= strlen(str); i++) {
        char prefix[i + 1];
        strncpy(prefix, str, i);
        prefix[i] = '\0'; // Null-terminate the prefix string
        printf("%s\n", prefix);
    }
}

// Function to print all suffixes of the string
void printSuffix(char str[]) { 
    printf("\nSuffix Combinations are:\n");
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        printf("%s\n", &str[i]); // Print suffix starting from index i
    }
}

// Function to print all substrings of the string
void printSubstring(char str[]) {
    printf("\nSubstring Combinations are:\n");
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char substring[100]; // Temporary storage for substring
            strncpy(substring, &str[i], j - i); // Copy substring from index i
            substring[j - i] = '\0'; // Null-terminate the substring
            printf("%s\n", substring);
        }
    }
}
