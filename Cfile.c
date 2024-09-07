#include <stdio.h>
#include <stdlib.h>

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
        default:
            return temp;
    }

    return temp;
}

int main(int argc, char **argv) {
    float temp, output;
    char inputUnit, outputUnit;

    if (argc == 4) {
        // CLI input mode
        inputUnit = argv[1][0];
        temp = atof(argv[2]);
        outputUnit = argv[3][0];
    } else {
        // Interactive mode
        while (1) {
            printf("\nEnter input unit (f/c/k): \n");
            scanf(" %c", &inputUnit);

            if (inputUnit != 'f' && inputUnit != 'c' && inputUnit != 'k') {
                printf("Invalid input unit! Please try again.\n");
                continue;
            }

            printf("Enter temperature value in %c: \n", inputUnit);
            scanf("%f", &temp);

            printf("Enter desired output unit (f/c/k): \n");
            scanf(" %c", &outputUnit);

            if (outputUnit != 'f' && outputUnit != 'c' && outputUnit != 'k') {
                printf("Invalid output unit! Please try again.\n");
                continue;
            }

            break;
        }
    }

    output = convertTemperature(temp, inputUnit, outputUnit);
    printf("Converted temperature: %.2f%c\n", output, outputUnit);

    return 0;
}
