#include <stdio.h>

/* Temperature Conversions:
 * C => F : C * 1.8 + 32
 * C => K : C + 273.15
 * F => C : (F - 32) * (5.0/9.0)
 * F => K : (F - 32) * (5.0/9.0) + 273.15
 * K => C : K - 273.15
 * K => F : (K - 273.15) * 1.8 + 32 */

// converts given temp in given scale to celsius
double toCelsius(double temp, char scale) {
	switch (scale)
	{
		case 'C': return temp; // C to C
		case 'F': return (temp - 32) * (5.0/9.0); // F to C
		case 'K': return temp - 273.15; // K to C
	}
	return 1; // should not be reached unless an error occurred
}

// converts celsius to other temperature scales
double fromCelsius(double celsius, char scale) {
	switch (scale)
	{
		case 'C': return celsius; // C to C
		case 'F': return celsius * 1.8 + 32; // C to F
		case 'K': return celsius + 273.15; // K to C
	}
	return 1; // should not be reached unless an error occurred
}

// prints conversion, temperature category, and weather advisory from given temp & scale
void printConversion(double temp, char scale, char new_scale) {
	double celsius = toCelsius(temp, scale); // get celsius of temp
	double conv_temp = fromCelsius(celsius, new_scale); // convert to user-desired scale

	printf("\nConverted temperature: %.2f %c\n", conv_temp, new_scale);


	printf("\nTemperature category: ");
	if (celsius < 0){ 
		printf("Freezing \nWeather advisory: Stay inside\n"); return;
	}
	if (celsius >= 0 && celsius < 10){ 
		printf("Cold \nWeather advisory: Wear a jacket\n"); return;
	}
	if (celsius >= 10 && celsius < 25){ 
		printf("Comfortable \nWeather advisory: Wear sunscreen\n"); return;
	}
	if (celsius >= 25 && celsius < 35){ 
		printf("Hot \nWeather advisory: Hydrate lots and wear sunscreen!\n"); return;
	}
	if (celsius >= 35){ 
		printf("Extreme Heat \nWeather advisory: Stay inside and enjoy the AC\n"); return;
	}
}

// check for scale validity
int isValidScale(char c) {
    return c == 'C' || c == 'F' || c == 'K';
}

// main function
int main(void) {
    double temp; // initialize temp
    char og_scale, conv_scale; // initialize original and desired scale

    printf("\nEnter the temperature value: "); // prompt user temp
    while (scanf("%lf", &temp) != 1) { // loop until valid input
        printf("Invalid number. Enter the temperature value: "); // reprompt user
        while (getchar() != '\n'); // clears bad input 
    }

    /* The leading space in " %c" skips any leftover whitespace/newline
     * still sitting in the input buffer from the previous scanf. */
    printf("Enter the original scale (C, F, or K): "); // prompt og scale
    scanf(" %c", &og_scale);
    while (!isValidScale(og_scale)) { // loop until valid scale
        printf("Invalid scale. Enter the original scale (C, F, or K): "); // reprompt user
        scanf(" %c", &og_scale);
    }

    printf("Enter the scale to convert to (C, F, or K): "); // prompt desired scale
    scanf(" %c", &conv_scale);
    while (!isValidScale(conv_scale)) { // loop until valid scale
        printf("Invalid scale. Enter the scale to convert to (C, F, or K): "); // reprompt user
        scanf(" %c", &conv_scale);
    }

    printConversion(temp, og_scale, conv_scale); // run conversion function w/ given input 

    return 0; // ran successfully
}
