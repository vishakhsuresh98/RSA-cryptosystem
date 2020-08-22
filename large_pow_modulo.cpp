#include "large_pow_modulo.h"

int large_pow_modulo(int a, int b, int c)
{
    /**
     * if a^b = p*q, then (a^b)%c = ((p%c)*(q%c))%c
     */
    if(b == 1) {
        return a % c;
    }
    else if(b % 2 == 0) {
        // split into 2 equal halves
        int result = large_pow_modulo(a, b / 2, c);
        return (result * result) % c; 
    }
    else {
        // split into 
        int result1 = a % c;;
        int result2 = large_pow_modulo(a, b - 1, c);
        return (result1 * result2) % c;
    }
}