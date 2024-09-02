#include <stdio.h>

float convertTemperature(float temp, char from, char to) {
    if (from == to) {
        return temp;
    }

    switch (from) {
        case 'f':
            temp = (temp - 32) * 5.0 / 9.0; // Convert Fahrenheit to Celsius
            break;
        case 'k':
            temp -= 273.15; // Convert Kelvin to Celsius
            break;
        // 'c' (Celsius) requires no conversion
    }

    switch (to) {
        case 'f':
            return temp * 9.0 / 5.0 + 32; // Convert Celsius to Fahrenheit
        case 'k':
            return temp + 273.15; // Convert Celsius to Kelvin
        // 'c' (Celsius) requires no conversion
    }

    return temp;
}

int main() {
    float temp, output;
    char inputUnit, outputUnit;
    int isInfinite = 0; // enter bools
    
    while (isInfinite | 1) {
        printf("\nEnter input unit (f/c/k): ");
        scanf(" %c", &inputUnit);

        if (inputUnit != 'f' && inputUnit != 'c' && inputUnit != 'k') {
            printf("Invalid input unit! Please try again.\n");
            continue;
        }

        printf("Enter temperature value in %c: ", inputUnit);
        scanf("%f", &temp);

        printf("Enter desired output unit (f/c/k): ");
        scanf(" %c", &outputUnit);

        if (outputUnit != 'f' && outputUnit != 'c' && outputUnit != 'k') {
            printf("Invalid output unit! Please try again.\n");
            continue;
        }

        output = convertTemperature(temp, inputUnit, outputUnit);
        printf("Converted temperature: %.2f%c\n", output, outputUnit);
        break;
    }

    return 0;
}
