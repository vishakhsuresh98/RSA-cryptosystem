#include <stdlib.h>

#include "get_next_prime.h"
#include "is_prime.h"

/**
 * Generate the next prime number 
 *
 * @param input the input prime, as an int 
 * @returns next prime, as an int
 */
int get_next_prime(int input)
{
    int output;
    if(input == 2) {
        output = 3;
    }
    else {
        output = input + 2;
        while(!is_prime(output)) {
            output += 2;
        }
    }
    return output;
}