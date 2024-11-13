#include <stdio.h>

int main() {
    enum states { q0, q1, qf };
    char input[20];
    enum states curr_state = q0;

    printf("Enter a binary string: ");
    fgets(input, sizeof(input), stdin);  // Using fgets to read input

    for (int i = 0; input[i] != '\0'; ++i) {  // Loop until the end of the string
        switch (curr_state) {
            case q0:
                if (input[i] == '0') curr_state = q1;
                else return printf("The string %s is not accepted.\n", input);
                break;
            case q1:
                if (input[i] == '1') curr_state = qf;
                else return printf("The string %s is not accepted.\n", input);
                break;
            case qf:
                // Once in qf, always accept
                break;
        }
    }

    if (curr_state == qf)
        printf("The string %s is accepted.\n", input);
    else
        printf("The string %s is not accepted.\n", input);

    return 0;
}
