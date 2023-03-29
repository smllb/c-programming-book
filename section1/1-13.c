#include <stdio.h>

#define IN 1
#define OUT 0

/* count digits, white space, others */
int main()
{
    int state = OUT, len = 0;
    char c;
    
    while(( c = getchar()) != EOF ) {

        if (c != ' ' && c != '\n'  && c != '\t') {
            state = IN;
            len++;
            putchar(c);
        } else {
            state = (state == IN) ? OUT : state; 
            printf(" ");
            for (int i=0;i<len;i++) {
                printf("|");

            }
            printf("\n");
            len = 0;
        }
    }

    return 0;
}
