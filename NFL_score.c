#include <stdio.h> // necessary for user i/o

/* Rundown of NFL Points: 
 * (TD+2pt) Touchdown + 2-point-conversion = 6 + 2 
 * (TD+FG)  Touchdown + 1-point Field Goal = 6 + 1
 * (TD)     Touchdown = 6
 * (FG)     Field Goal = 3
 * safety   Safety = 2 */

void printCombinations(int score) { // Function for tallying & printing points solutions
    printf("\nPossible combinations of scoring plays if a team's score is %d:\n", score);
 
	// a = number of TD+2pt plays (8 points each)
   	for (int a = 0; 8 * a <= score; a++) {
 
        // b = number of TD+FG plays (7 points each)
        for (int b = 0; 8 * a + 7 * b <= score; b++) {
 
            // c = number of plain TD plays (6 points each)
            for (int c = 0; 8 * a + 7 * b + 6 * c <= score; c++) {
 
                int remaining = score - 8 * a - 7 * b - 6 * c;
 
                /* d = number of 3-point field goals.
                 * Since 2*e is always even, 3*d must have the same
                 * parity as 'remaining' for e to come out as a whole
                 * number. So d starts at 0 or 1 (matching parity) and
                 * increases by 2 each time. */
                int dStart = remaining % 2;
 
                for (int d = dStart; 3 * d <= remaining; d += 2) {
                    // e = number of safeties
                    int e = (remaining - 3 * d) / 2; 
 
                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
                }
            }
        }
    }
}
 
int main(void) { // main function
    int score; // initialize score
 
    while (1) { // endless while loop until broken by user
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) { // if invalid input
            while (getchar() != '\n');  // clear each character until "\n"
            continue;                   // then prompt user again
        }
 
        if (score == 1) { // if given 1
            break;        // break
        }
 
        if (score < 0) { // if given negative num
            printf("Please enter a non-negative score.\n"); // warn user
            continue;    // then prompt them again
        }
 
        printCombinations(score); // run tallying & print function
        printf("\n"); // add space between solutions & prompt
    }
 
    return 0; // ran successfully --> return 0
}
