#include <stdio.h>

enum states {q0, q1, q2, q3, q4, qr};

int main() {
    char input[100];
    enum states curr_state = q0;
    int i;

    // Initialize input buffer
    for (i = 0; i < 100; i++)
        input[i] = '\0';

    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

    i = 0;
    while (1) {
        switch (curr_state) {
            case q0:
                if (input[i] == '0') {
                    curr_state = q1;
                    input[i] = 'x';
                    i++;
                } else if (input[i] == 'y') {
                    curr_state = q3;
                    i++;
                } else {
                    curr_state = qr;  // Invalid transition
                }
                break;

            case q1:
                if (input[i] == '0') {
                    curr_state = q1;
                    i++;
                } else if (input[i] == 'y') {
                    curr_state = q1;
                    i++;
                } else if (input[i] == '1') {
                    curr_state = q2;
                    input[i] = 'y';
                    i--;
                } else {
                    curr_state = qr;
                }
                break;

            case q2:
                if (input[i] == '0') {
                    curr_state = q2;
                    i--;
                } else if (input[i] == 'y') {
                    curr_state = q2;
                    i--;
                } else if (input[i] == 'x') {
                    curr_state = q0;
                    i++;
                } else {
                    curr_state = qr;
                }
                break;

            case q3:
                if (input[i] == 'y') {
                    curr_state = q3;
                    i++;
                } else if (input[i] == '\0') {
                    curr_state = q4;
                } else {
                    curr_state = qr;
                }
                break;
        }

        if (curr_state == qr || curr_state == q4)
            break;
    }

    if (curr_state == q4) {
        printf("\nThe string %s is accepted.\n", input);
    } else {
        printf("\nThe string %s is not accepted.\n", input);
    }

    return 0;
}
