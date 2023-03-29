#include <stdio.h>

int power(int base, int expn) {
    
    int p = base;
    for (int i = 0; i < expn-1; i++) {
        p *= base;
        printf("p: %d | iteration: %d\n", p, i);
    }
    return p;

}

int main() {
    int p = power(2,5);
    printf("this is p: %d\n", p);
}

