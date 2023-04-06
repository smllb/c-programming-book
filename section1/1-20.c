#include <stdio.h>

int actualColumn = 0;

void updateActualColumn () {
    actualColumn++;
    if (actualColumn >8) {
        actualColumn = 1;
    }

}


int retrieveNextTabSpot() {
    int nextStop = 8-actualColumn;
    return nextStop;

}

int main()
{
    char c;  
    int nextTabStop;
    while(( c = getchar()) != EOF ) {
        if (c == '\t') {

            nextTabStop = retrieveNextTabSpot();
            for (int i=0; i<nextTabStop;i++) {
                updateActualColumn();
                putchar(' ');
            };
            
        } else if (c == '\n') {
            actualColumn = 0;

        } else {

            putchar(c);
            updateActualColumn();

        }
        
    }   

    return 0;
}
