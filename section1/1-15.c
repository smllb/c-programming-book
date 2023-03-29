#include <stdio.h>

int printFahrenheitToCelsius(int upper, int step) {

    float fahr, celsius;
    fahr = 0;

    while (fahr <= upper) {
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;

    }
    return 0;
}

int main() {

printFahrenheitToCelsius(500 , 50);

}
