// crypt.cüü / scrypt-lite

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

#define BUFFER_SIZE 1024*1024

using namespace std;

int encrypt(string in_file, string out_file, vector<unsigned char> vector_key) {
    ByteArray key, enc;
    size_t file_len, key_len = 0;

    FILE *in, *out;

    srand(time(0));

    // Convert key
    while (vector_key[key_len] != 0) {
        key.push_back(vector_key[key_len++]);
    }

    // Read files
    in = fopen(in_file.c_str(), "rb");
    if (in == 0) {
        return 1;
    }

    out = fopen(out_file.c_str(), "wb");
    if (out == 0) {
        return 1;
    }

    //TODO
    fclose(in);
    fclose(out);

   return 0; 
}

int decrypt(string in_file, string out_file, vector<unsigned char> vector_key) {
    return 0;
}