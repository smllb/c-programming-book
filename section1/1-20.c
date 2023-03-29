#include <stdio.h>

int actualColumn = 0;

void updateActualColumn () {
    actualColumn++;
    if (actualColumn >7) {
        actualColumn = 0;
    }   
}

int main()
{
    char c;  
    int nextTabStop;
    while(( c = getchar()) != EOF ) {
        nextTabStop = 7-actualColumn;
    //printf("nextabstop %d|", nextTabStop);
        if (c == '\t') {
            for (int i=0;i<nextTabStop;i++) {
                //printf("%d", i);
                updateActualColumn();
                //printf("%d", actualColumn);
                putchar(' ');
            }    

        } else if (c == '\n') {
            actualColumn = 0;

        } else {
           // printf("%d", actualColumn);
            putchar(c);
            updateActualColumn();

        }
        
    }   

    return 0;
}
