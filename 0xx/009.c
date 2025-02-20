/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, 
 * for which,
 * 
 *  a^2 + b^2 = c^2.
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean truplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>
#include <stdbool.h>

int findTriplet(int goal) {
    for (int a = 1;; a++) {
        int b = a + 1;
        int c = goal - a - b;
        for (; b < c; b++) {
            if (a * a + b * b == c * c) {
                return a * b * c;
            }
            c = goal - a - (b + 1);
        }
    }
    return -1;
}

int main() {
    int goal = 1000;
    int product = findTriplet(goal);
    if (product == -1) {
        printf("Error: no product found.");
        return -1;
    }
    printf("Triplet: %d\n", product);
}
