//C program designed to detect the presence of comments within a source code input by the user.

/*
Programming Logic:
The program utilises a simple logic to detect comments within a C source code. It
iterates through each character of the input string and checks for specific patterns
that indicate the presence of comments:
● For single-line comments: It checks for the occurrence of "//" in the input
string.
● For multi-line comments: It checks for the occurrence of "/" at the beginning
and "/" at the end of the input string.
Upon detecting these patterns, appropriate flags are set to indicate the presence of
comments.
*/


#include <stdio.h>
int main()
{
    int i, c = 0, n;
    char str[1000];
    printf("Enter your source code: ");
    gets(str);
    n = strlen(str);
    for (i = 0; i <= n - 1; i++)
    {
        if (str[i] == '/')
        {
            if (str[i + 1] == '/')
            {
                c = 1;
            }
        }
        if (str[i] == '/' && str[i + 1] == '*' && str[n - 1] == '/' && str[n - 2] == '*')
        {
            c = 2;
        }
    }
    if (c == 1)
    {
        printf("Single Line Comment Detected...");
    }
    else if (c == 2)
    {
        printf("Multi-line Comment Detected...");
    }
    else
    {
        printf("No Comment Detected...");
    }
    return 0;
}
