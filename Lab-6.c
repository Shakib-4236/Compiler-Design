/*

Programming Logic:
The software uses a straightforward logic to accomplish its goal:
    ● The user is prompted to enter a sentence that ends in "$."
    ● It extracts tokens by parsing the statement character by character after receiving the input.
    ● The 2D array called "tokens" is where tokens are kept.
    ● Whether a token represents an operator or an identifier determines which category it belongs in.
    ● Malloc() is used to dynamically create memory for identifiers in order to mimic an address in the
      symbol table.
    ● The symbol table including the tokens, their addresses, and types is finally displayed by the
      application.

*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main() {
    void *pt;
    char str[50], tokens[10][10];
    int n = 0, i = 0, j = 0, token_number = 0, char_index = 0, firstCharValid = 0;
    printf("Enter a $-terminated statement: ");
    fgets(str, sizeof(str), stdin);
    n = strlen(str);
    printf("Entered statement: ");
    for (i = 0; i < n - 2; i++) {
        printf("%c", str[i]);
    }
    for (i = 0; i < n; i++) {
        if (!isspace(str[i])) {
            if (str[i] == '$') {
                tokens[token_number][char_index] = '\0';
                token_number++;
                char_index = 0;
            } else {
                tokens[token_number][char_index] = str[i];
                char_index++;
            }
        } else {
            tokens[token_number][char_index] = '\0';
            token_number++;
            char_index = 0;
        }
    }
    printf("\n\n-------------------------------------\n");
    printf("| Symbol Table |\n");
    printf("-------------------------------------\n");
    printf("| Symbol | Address | Type |\n");
    printf("-------------------------------------\n");
    for (i = 0; i < token_number; i++) {
        for (j = 0; tokens[i][j] != '\0'; j++) {
            if (isalnum(tokens[i][j]) && firstCharValid == 0) {
                pt = malloc(tokens[i][j]);
                firstCharValid = 1;
                printf("| %s | %#010x | Identifier |\n", tokens[i], pt);
            } else if (tokens[i][j] == '+' || tokens[i][j] == '-' || tokens[i][j] == '*' || tokens[i][j] == '/' || tokens[i][j]
                       == '=') {
                pt = malloc(tokens[i][j]);
                printf("| %c | %#010x | Operator |\n", tokens[i][j], pt);
            }
        }
        firstCharValid = 0;
    }
    printf("-------------------------------------\n\n");
    return 0;
}
