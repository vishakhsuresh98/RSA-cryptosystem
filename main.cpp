#include <time.h>
#include <string>

#include "key_struct.h"
#include "generate_key.h"
#include "encrypt.h"
#include "decrypt.h"

// Driver program to test the above functions 
int main() 
{  
    srand(time(NULL));
    ifstream in_ptr;
    ofstream out_ptr;

    cout << "RSA" << endl;
    cout << "---\n\n" << endl;

    // encryption process
    cout << "Encryption process :\n" << endl;
    string input;
    in_ptr.open("plaintext.txt"); 
    getline(in_ptr, input);
    int plaintext = stoi(input);
    cout << "Plaintext - " << plaintext << endl;
    key_struct key = generate_key(plaintext);
    cout << "Public key - {" << key.e << " , " << key.n << "}" << endl;
    cout << "Private key - {" << key.d << " , " << key.n << "}" << endl;
    
    int ciphertext = encrypt(plaintext, key); 
    cout << "Ciphertext - " << ciphertext << endl; 
    cout << "\n\n";
    in_ptr.close();

    // decryption process
    cout << "Decryption process :\n" << endl;
    cout << "Ciphertext - " << ciphertext << endl; 
    plaintext = decrypt(ciphertext, key); 
    cout << "Plaintext - " << plaintext << endl; 
    cout << "\n";
    in_ptr.close();

    return 0; 
} 
