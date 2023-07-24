#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to evaluate prefix notation exp using preorder traversal
int prefixexp(char exp[], int* index) {
    char ch;
    while (exp[*index] == ' ') {
        (*index)++;
    }
    ch = exp[(*index)++];

    if (ch == '\0') {
        return 0;
    }

    if (isdigit(ch)) {
        return ch - '0';
    }

    int opr1 = prefixexp(exp, index);
    int opr2 = prefixexp(exp, index);

    switch (ch) {
        case '+':
            return opr1 + opr2;
        case '-':
            return opr1 - opr2;
        case '*':
            return opr1 * opr2;
        case '/':
            return opr1 / opr2;
        default:
            printf("Invalid operator!\n");
            exit(1);
    }
}

int main() {
    printf("Enter the prefix notation expression: ");

    char exp[100];
    fgets(exp, sizeof(exp), stdin);

    int index = 0;
    int result = prefixexp(exp, &index);

    printf("Result: %d\n", result);

    return 0;
}
