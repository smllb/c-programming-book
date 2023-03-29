#include <stdio.h>

int main() {

  char c, lastCharSeen;

  while ((c = getchar()) != EOF) {
    
    if (c != ' ' && c != '\t') {
     putchar(c);
    } 
    
  }

}
