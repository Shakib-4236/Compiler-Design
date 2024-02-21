/*To identify particular patterns in input strings, the program makes use of a finite state machine with
several states. The given rules serve as the basis for defining the states and transitions. A string supplied
from the user is read by the program, which then analyzes it character by character in accordance with
predefined state transitions. When the string reaches the end, it checks to see if the input string complies
with any of the preset guidelines.
*/


#include<stdio.h>
void main(){
    char s[20], c;
    int state = 0, i = 0;
    printf("Enter a string: ");
    gets(s);

    while (s[i] !='\0'){
        switch (state){
            case 0:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                        state = 2;
                else
                    state = 6;
                break;
            case 1:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                        state = 4;
                else
                    state = 6;
                break;
            case 3:
                c = s[i++];
                if (c == 'a')
                    state = 3;
                else if (c == 'b')
                        state = 2;
                else
                    state = 6;
                break;
            case 4:
                c = s[i++];
                if (c == 'a')
                    state = 6;
                else if (c == 'b')
                        state = 5;
                else
                    state = 6;
                break;
             case 5:
                c = s[i++];
                if (c == 'a')
                    state = 6;
                else if (c == 'b')
                        state = 5;
                else
                    state = 6;
                break;
             case 6:
                printf("\n%s is not recognized!!\n", s);
                exit (0);
        }
    }

    if (state == 1)
        printf("%s is accepted under rule 'a*'..\n", s);
    else if (state == 2 || state == 4)
        printf("%s is accepted under rule 'a*b+'..\n", s);
    else if (state == 5)
        printf("%s is accepted under rule 'abb'..\n", s);
    main();
}

