/*
 * The sum of the sqaures of the first ten natural numbers is,
 *  1^2 + 2^2 + ...+ 10^2 = 385.
 * 
 * The square of the sum of the first ten natural numbers is,
 *  (1 + 2 + ... + 10)^2 = 55^2 = 3025.
 * 
 * Hence the difference between the sum of the squares of the first ten 
 * natural numbers and the square sum is 3025 - 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one 
 * hundred natural numbers and the square of the sum.
 */

#include <stdio.h>

int main() {

    int num = 100;

    int sumSquares = 0;
    int squareSums = 0;

    for (int i = 1; i <= num; i++) {
        sumSquares += i * i;
        squareSums += i;
    }
    squareSums *= squareSums;
    int diff = squareSums - sumSquares;
    printf("Answer: %d\n", diff);
}
