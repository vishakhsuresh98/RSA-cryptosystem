#include <math.h>

#include "encrypt.h"
#include "key_struct.h"
#include "large_pow_modulo.h"

int encrypt(int plaintext, struct key_struct key)
{
    int ciphertext = large_pow_modulo(plaintext, key.e, key.n);
    return ciphertext;
}