#include <stdio.h>

int main() {

    int c;
    
    while ((c = getchar()) != EOF) {

        printf("Evaluating getchar() != EOF: %d\n", (getchar() != EOF));
        putchar(c);
        printf("\n");

    }

}
