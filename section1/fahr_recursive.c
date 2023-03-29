#include <stdio.h>

float  computeFahrToCelsius(int upper, float fahr) {

    if (fahr <= upper) {    
        printf("%3.0f\t %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
        computeFahrToCelsius(300, fahr+=20);
        
    } else {      
        return 0;
    }

}

int main() {

    computeFahrToCelsius(300, 0);

}

