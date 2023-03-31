#include <stdio.h>

int actualColumn = 0;

void updateActualColumn () {
    actualColumn++;
    if (actualColumn >8) {
        actualColumn = 0;
    }
    // printf("actclmn %x ", actualColumn);
    printf("actclmn %x ", actualColumn);
}


int retrieveNextSpot() {
    int nextStop = 8-actualColumn;
    return nextStop;

}

int updateColumnAndReturnNextTabSpot() {
    updateActualColumn();
    int nextTabSpot = retrieveNextSpot();
    return nextTabSpot;
}
int main()
{
    char c;  
    int nextTabStop;
    while(( c = getchar()) != EOF ) {
        
        if (c == '\t') {
                putchar(' ');
            
        } else if (c == '\n') {
            actualColumn = 0;

        } else {
           // printf("%d", actualColumn);

            putchar(c);
            nextTabStop = updateColumnAndReturnNextTabSpot();
            

        }
        
    }   

    return 0;
}
