#include <math.h>

#include "decrypt.h"
#include "key_struct.h"
#include "large_pow_modulo.h"

int decrypt(int ciphertext, struct key_struct key)
{
    int plaintext = large_pow_modulo(ciphertext, key.d, key.n);
    return plaintext;
}