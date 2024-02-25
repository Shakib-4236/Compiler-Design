/*
Enter a string: SHAKIB&sha#kib@
Uppercase character count: 6
Lowercase character count: 6
Number count: 0
Special character count: 3
Special characters: & # @
*/

#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100];
    int uppercase_count = 0, lowercase_count = 0, number_count = 0, special_count = 0;
    char special_chars[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            uppercase_count++;
        else if (islower(str[i]))
            lowercase_count++;
        else if (isdigit(str[i]))
            number_count++;
        else if (str[i] != ' ' && str[i] != '\n') {
            special_chars[special_count] = str[i];
            special_count++;
        }
    }
    special_chars[special_count] = '\0';

    printf("Uppercase character count: %d\n", uppercase_count);
    printf("Lowercase character count: %d\n", lowercase_count);
    printf("Number count: %d\n", number_count);

    if (special_count > 0) {
        printf("Special character count: %d\n", special_count);
        printf("Special characters: ");
        for (int i = 0; i < special_count; i++) {
            printf("%c ", special_chars[i]);
        }
        printf("\n");
    } else {
        printf("No special characters found.\n");
    }

    return 0;
}
