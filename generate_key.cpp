#include "generate_key.h"
#include "key_struct.h"
#include "get_prime.h"
#include "get_next_prime.h"
#include "gcd.h"

/**
 * Generate a random kay of length equal to that of the plaintext
 * 
 * @param plaintext the plaintext, as a string in hexadecimal number system
 * @returns random key, as a string in hexadecimal number system
 */
key_struct generate_key(int plaintext)
{
	key_struct key;
    int p = get_prime();
    int q = get_prime();
    int n = p * q;
    while(n < plaintext || p == q) {
        q = get_next_prime(q);
        n = p * q;
    }
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while(gcd(phi, e) != 1 && e < phi) {
        e++;
    }
    int d = 1;
    while((e * d) % phi != 1) {
        d++;
    }
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "phi = " << phi << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    cout << "n = " << n << endl;
	key.d = d;
    key.e = e;
    key.n = n;
	return key;
}