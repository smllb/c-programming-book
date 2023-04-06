#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0

int currentLineColumn = 0;
int currentLineStringIndex = 0;

int main() {
    // ler STRINGS separadas por espaço. a cada 3, fazer um \n

    char c;
    int status = OUT;
    char lineBuffer[3][255];

    while ((c = getchar()) != EOF) {

        if (c == '\t' || c == '\n' || c == ' ') {
            status = OUT;
            if (currentLineColumn == 2) {


                for (int x = 0; x < currentLineColumn+1; x++) {
                    printf("%s", lineBuffer[x]);
                    putchar(' ');
                    //lineBuffer[x][0] = '\0'; // reset the string
                }
                putchar('\n');
                currentLineColumn = 0;
            } else if (c == '\n') {
                for (int x = 0; x < currentLineColumn+1; x++) {
                    printf("%s", lineBuffer[x]);
                    putchar(' ');
                   // lineBuffer[x][0] = '\0'; // reset the string

                }

            } else {

                    currentLineColumn++;
              }

            currentLineStringIndex = 0; // reset the index

        } else {
            status = IN;
            lineBuffer[currentLineColumn][currentLineStringIndex++] = c;
        }

    }

    return 0;
}
