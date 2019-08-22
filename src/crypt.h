/**
 * scrypt-lite
 * crypt.h
 * 
 * @autor Leon Latsch
 * @version 1.0
 */

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "lib/aes256/aes256.hpp"

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
int encrypt(std::string inFile, std::string outFile, std::vector<unsigned char> vectorKey);

/**
 * Decrypt a file with a key
 * 
 * @param in_file the input file to be decrypted
 * @param out_file the output file
 * @param vecot_key a vecor containing the AES key
 * 
 * @return 0 if no errors occured
 */
int decrypt(std::string inFile, std::string outFile, std::vector<unsigned char> vectorKey);