#include <stdio.h>

int main() {
    enum states { q0, q1, qf };
    char input[20];
    enum states curr_state = q0;

    printf("Enter a binary string: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; ++i) {
        switch (curr_state) {
            case q0:
                if (input[i] == '0') curr_state = q1;
                break;
            case q1:
                if (input[i] == '1') curr_state = qf;
                else if (input[i] == '0') curr_state = q1;
                break;
            case qf:
                if (input[i] == '0') curr_state = q1;
                else if (input[i] == '1') curr_state = q0;
                break;
        }
    }

    if (curr_state == qf)
        printf("The string %s is accepted.\n", input);
    else
        printf("The string %s is not accepted.\n", input);

    return 0;
}
