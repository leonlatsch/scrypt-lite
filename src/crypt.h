// crypt.h / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <vector>

using namespace std;

/**
 * Encrypt a file with a key
 * 
 * @param in_file the input file to be encrypted
 * @param out_file the output file
 * @param vecot_key a vecor containing the AES key
 * 
 * @return 0 if no errors occured
 */
int encrypt(string in_file, string out_file, vector<unsigned char> vector_key);

/**
 * Decrypt a file with a key
 * 
 * @param in_file the input file to be decrypted
 * @param out_file the output file
 * @param vecot_key a vecor containing the AES key
 * 
 * @return 0 if no errors occured
 */
int decrypt(string in_file, string out_file, vector<unsigned char> vector_key);