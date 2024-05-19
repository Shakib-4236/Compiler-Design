/*

Programming Logic:
    1. Define the arrays and variables that are needed.
    2. Enter the string to be processed together with the grammatical rules.
    3. Put the LR(0) parsing method into practice.
    4. Verify that the supplied string complies with the grammatical rules.
    5. Show the steps and outcomes of parsing.

*/



#include<stdio.h>
#include<string.h>
int k=0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];
void check();
void main() {
    printf("Set Grammar:\nE -> E + E\nE -> E * E\nE -> (E)\nE -> id\n");
    printf("Enter a String: ");
    scanf("%s", a);
    c = strlen(a);
    strcpy(act, "Shifted ");
    printf("Stack\t Input\t\t Action");
    for (k = 0, i = 0; j < c; k++, i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i] = a[j];
            stk[i + 1] = a[j+ 1];
            stk[i +2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, act);
            check();
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%sSymbol", stk, a, act);
            check();
        }
    }
}
void check() {
    strcpy(ac, "Reduced to E");
    if (stk[i] == 'i' && stk[i + 1] == 'd') {
        stk[i] = 'E';
        stk[i + 1] = '\0';
        printf("\n$%s\t%s$\t%s", stk, a, ac);
        j++;
    } else if (stk[i] == 'E' && stk[i + 1] == '+' && stk[i + 2] == 'E') {
        stk[i] = 'E';
        stk[i + 1] = '\0';
        stk[i + 2] = '\0';
        printf("\n$%s\t%s$\t%s", stk, a, ac);
        i = i - 2;
    } else if (stk[i] == 'E' && stk[i + 1] == '*' && stk[i + 2] == 'E') {
        stk[i] = 'E';
        stk[i + 1] = '\0';
        stk[i + 2] = '\0';
        printf("\n$%s\t%s$\t%s", stk, a, ac);
        i = i - 2;
    } else if (stk[i] == '(' && stk[i + 1] == 'E' && stk[i + 2] == ')') {
        stk[i] = 'E';
        stk[i + 1] = '\0';
        stk[i + 2] = '\0';
        printf("\n$%s\t$%s\t%s", stk, a, ac);
        i = i - 2;
    }
}
