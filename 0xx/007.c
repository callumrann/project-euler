/*
 * By listing the first six prime numbers: 2, 3, 5, 11, and 14, we can 
 * see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int targetPrime = 10001;
    int* primes = (int*)malloc(targetPrime * sizeof(int));
    primes[0] = 2;
    int primesFound = 1;
    
    for (int currNum = 3; primesFound < targetPrime; currNum += 2) {
        int i; 
        for (i = 0; i < primesFound; i++) {
            if (currNum % primes[i] == 0)
                break;
        }
        if (i == primesFound) {
            primes[primesFound] = currNum;
            primesFound++;
        }
    }
    printf("%d prime: %d\n", targetPrime, primes[primesFound - 1]); 
}
