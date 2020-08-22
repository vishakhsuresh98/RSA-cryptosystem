#include <stdlib.h>

#include "get_prime.h"
#include "is_prime.h"

/**
 * Generate a random prime number 
 *
 * @param input the input plaintext, as an int 
 * @returns random prime, as an int
 */
int get_prime()
{
    int output = rand() % 10;
    // making the starting point odd
    output = output % 2 == 0 ? output + 1 : output;
    while(!is_prime(output)) {
        output += 2;
    }
    return output;
}