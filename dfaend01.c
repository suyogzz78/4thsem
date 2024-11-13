#include <stdio.h>
#include <string.h>

// DFA States
typedef enum { q0, q1, q2, q3 } State;

// Function to simulate the DFA
int endsWith01(const char* str) {
    State state = q0; // Initial state
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i]; // Current character
        switch (state) {
            case q0:
                if (c == '0') state = q1;
                else state = q0;
                break;
            case q1:
                if (c == '0') state = q1;
                else state = q2;
                break;
            case q2:
                if (c == '0') state = q1;
                else state = q0;
                break;
            case q3:
                state = q3; // Dead state, stay in q3
                break;
        }
    }
    return state == q2; // Accept if in q2
}

int main() {
    char str[100]; // Input string with a max length of 99 characters

    printf("Enter the binary string: ");
    scanf("%99s", str);

    if (endsWith01(str)) {
        printf("The string ends with '01'.\n");
    } else {
        printf("The string does not end with '01'.\n");
    }

    return 0;
}
