/*
Write a C program to take multiple identifiers from user and return their validity.

------Input & Output-------
Enter the identifiers:
csediu @123 _shakib sha_kib

Tokens and Validity:
"csediu" is valid
"@123" is invalid
"_shakib" is valid
"sha_kib" is valid

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

bool isValidIdentifier(char identifier[]);

int main() {
    char str[50], tokens[10][10];
    int n = 0, i = 0, j = 0, token_number = 0, char_index = 0;

    printf("Enter the identifiers:\n");
    fgets(str, sizeof(str), stdin);
    n = strlen(str);

    for (i = 0; i < n; i++) {
        if (!isspace(str[i])) {
            tokens[token_number][char_index] = str[i];
            char_index++;
        }
        else {
            tokens[token_number][char_index] = '\0';
            token_number++;
            char_index = 0;
        }
    }

    printf("\nTokens and Validity:\n");
    for (i = 0; i < token_number; i++) {
        printf("\"%s\" ", tokens[i]);
        if (isValidIdentifier(tokens[i])) {
            printf("is valid\n");
        } else {
            printf("is invalid\n");
        }
    }

    return 0;
}

bool isValidIdentifier(char identifier[]) {
    if (!isalpha(identifier[0]) && identifier[0] != '_')
        return false;

    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_')
            return false;
    }

    return true;
}
