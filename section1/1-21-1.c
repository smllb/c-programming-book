#include <stdio.h>

#define IN 1
#define OUT 0

int actualColumn = 0, status, numberOfBlanksEntered = 0;
FILE* ptr;

void updateActualColumn () {
    actualColumn++;
    if (actualColumn >8) {
        actualColumn = 1;
    }

}

void resetNumberOfBlanksEntered () {
    numberOfBlanksEntered = 0;

}

void updateNumberOfBlanksEntered () {
    numberOfBlanksEntered++;

}

int retrieveNextTabSpot() {
    int nextStop = 8-actualColumn;
    return nextStop;

}
void updateNextTabSpot(int* nextTabSpot) {
    *nextTabSpot = 8-actualColumn;

}
void putSpaces(int* amountOfBlanksEntered, int nextTabSpot) {
    int amountOfSpacesToBePut = *amountOfBlanksEntered;
    for (int i = 0; i < amountOfSpacesToBePut; i++) {
        updateActualColumn();
        (*amountOfBlanksEntered)--;
        putchar(' ');

    }
}
void printLogToFile(char* content, int x) {
    ptr = fopen("output.txt", "a");
    fprintf(ptr, content, x);
    fclose(ptr);

}
void cleanLogFile () {
    ptr = fopen("output.txt", "w");
    fclose(ptr);

}
void entabInput(int* amountOfBlanksEntered) {


    int nextTabSpot = retrieveNextTabSpot();
    printLogToFile("Inside entabInput | Entering with nextTabSpot: %d\n", nextTabSpot);
    printLogToFile("Inside entabInput | Entering with amountOfBlanksEntered: %d\n", *amountOfBlanksEntered);
    if (*amountOfBlanksEntered > 8 && nextTabSpot > 3) {
        // subtract the amount of blanks entered by the current value of tab stop, then put a /t to get the spaces while updating the actual column as follows
        *amountOfBlanksEntered -= nextTabSpot;
        putchar('\t');
        for (int i = 0; i < nextTabSpot; i++) updateActualColumn();

        // if the value is still not 0 but less than 3 (reasonable value), fill the rest with blank spaces
        if (*amountOfBlanksEntered != 0 && *amountOfBlanksEntered < 3) {
            updateNextTabSpot(&nextTabSpot);
            putSpaces(amountOfBlanksEntered, nextTabSpot);

        } else {
            entabInput(amountOfBlanksEntered); // samsara

        }
    } else {
        //just fill with spaces since the number is low
        printLogToFile("Inside entabInput first layer ELSE | Preparing to use putSpaces ", 0);
        putSpaces(amountOfBlanksEntered, nextTabSpot);

    }
}
    int main() {
        cleanLogFile();

        char c;
        while ((c = getchar()) != EOF) {
            if (c == ' ') {
                status = IN;
                updateNumberOfBlanksEntered();


            } else if (c == '\n') {
                actualColumn = 0;


            } else {

                if (status == IN) {
                    entabInput(&numberOfBlanksEntered);
                    status = OUT;
                }

                if (status == OUT) {
                    numberOfBlanksEntered = 0;
                    putchar(c);
                    updateActualColumn();
                    resetNumberOfBlanksEntered();
                }

            }
        }

        return 0;

    }
