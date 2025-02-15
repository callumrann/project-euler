/*
 * 2520 is the smallest number that can be divided by each of the numbers 
 * from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all 
 * of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // idea is to ensure all prime factors from 20 to 2 exist
    int num = 20;
    int* primeFactors = (int*)calloc(num + 1, sizeof(int));
    // some wasted space with evens, but easier to follow code 
     
    for (int i = 2; i <= num; i++) {
        int* currentPrimeFactors = (int*)calloc(i + 1, sizeof(int));
        int current = i;
        // factor out 2 first 
        while (current % 2 == 0) {
            currentPrimeFactors[2]++;
            current /= 2;
        }
        // factor out odds
        for (int j = 3; j <= current; j += 2) {
            while (j * j <= current && current % j == 0) {
                currentPrimeFactors[j]++;
                current /= j;
            }
            if (j == 2) j--;
        }

        if (current > 1) currentPrimeFactors[current]++;
        
        for (int j = 0; j < i + 1; j++) {
            if (currentPrimeFactors[j] > primeFactors[j])
                primeFactors[j] = currentPrimeFactors[j];
        }
       
        free(currentPrimeFactors);
    }

    int result = 1;
    for (int i = 2; i <= num; i++) {
        for (int j = 1; j <= primeFactors[i]; j++)
            result *= i;
    }

    free(primeFactors);
    printf("Answer: %d\n", result);
}
