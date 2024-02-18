/*Programming Logic:
The program initializes an array of C keywords.
It prompts the user to enter a string.
The program then iterates through the array of keywords, comparing each keyword with the
user-input string using the strcmp() function.
If a match is found, it sets a flag indicating that the input string is a keyword.
Finally, it prints whether the input string is a keyword or not based on the value of the flag.
*/


#include<stdio.h>
#include<string.h>
int main()
{
    char str[10];
    printf("Enter any string: ");
    gets(str);

    char keywords[40][10]={
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float",
        "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch",
        "typedef", "union", "unsigned", "void", "volatile", "while"};
        int i, flag = 0;
        for(i=0;i<40;i++){
            if(strcmp(str, keywords[i])==0){
                flag=1;
            }
        }
        if (flag == 1){
            printf("'%s' is a keyword...", str);
        }
        else{
            printf("'%s' is not a keyword...", str);
        }

    return 0;
}
