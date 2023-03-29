#include <stdio.h>


int main() {

    char c;
    int lines =0, blanks =0, tabs =0;
    while ((c = getchar()) != EOF) {

        switch (c){
            case ' ':
                blanks++;
            break;
            case '\n':
                lines++;
            break;
            case '\t':
                tabs++;
            break;
        }

        printf("lines: %d | blanks: %d | tabs: %d | character: %c\n", lines, blanks, tabs, c);
    }


}