#include <stdio.h>

void main() {
    char c;
    
    while ((c = getchar()) != EOF) {   

         if (c == ' ') {
            printf("\n");

        } else {
            putchar(c);
        }
 } 
}

