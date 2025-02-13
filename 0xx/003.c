/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143
 */

#include <stdio.h>

int main() {
    long number = 600851475143;
    long factor = 2;
    
    // remove even factors
    // redundant in this, but allows code to be reapplied
    while (number % factor == 0) {
        number /= factor;
    }
    
    // only check odds now
    factor++;
    while (factor * factor < number) { // if greater, won't result in new
        while (number % factor == 0) {
            number /= factor;
        }
        factor += 2;
    }
    
    long greatestPrime = (number > 2) ? number : factor;
    printf("Greatest Prime: %ld\n", greatestPrime);
}
