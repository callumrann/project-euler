/*
 * A palindromic number reads the same both ways. The largest palindrome 
 * made from the product of two 2-digit numbers is 9009 = 91 x 99.
 *
 * Find the largest palindrom made from the product of two 3-digit
 * numbers.
 */

#include <stdio.h>

int main() {
    int largestPali = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;

            if (product < largestPali)
                break;

            int original = product;
            int reversed = 0;
            while (original > 0) {
                reversed = reversed * 10 + original % 10;    
                original /= 10; // prepare next digits
            }

            if (product == reversed)
                largestPali = product;
        }
    }
    printf("largest palidrome: %d\n", largestPali);
}
