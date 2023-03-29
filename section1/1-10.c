#include <stdio.h>

int main() {

  char c, lastCharSeen;

  while ((c = getchar()) != EOF) {
    
    if (c == '\t') {     
     printf("\\t");
     
    } else if (c == '\b') {
     printf("\\b");

    } else {
     putchar(c);

    }

  }

}
