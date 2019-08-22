// crypt.cpp / scrypt-lite
// Inspired by https://github.com/Urban82/Aes256/blob/master/utils/ due to no documentation

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "lib/aes256/aes256.hpp"
#include "progressbar.h"

#define BUFFER_SIZE 1024*1024

using namespace std;

int encrypt(string in_file, string out_file, vector<unsigned char> vector_key) {
    ByteArray key, enc;
    size_t file_len, key_len = 0; // In bytes

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

    Aes256 aes(key);

    fseeko64(in, 0, SEEK_END);
    file_len = ftell(in);
    fseeko64(in, 0, SEEK_SET);

    enc.clear();
    aes.encrypt_start(file_len, enc);
    fwrite(enc.data(), enc.size(), 1, out);

    double processed;

    while (!feof(in)) {
        unsigned char buffer[BUFFER_SIZE];
        size_t buffer_len;

        buffer_len = fread(buffer, 1, BUFFER_SIZE, in);
        if(buffer_len > 0) {
            enc.clear();
            aes.encrypt_continue(buffer, buffer_len, enc);
            fwrite(enc.data(), enc.size(), 1, out);
        }
        processed += buffer_len;
        double p = (processed / file_len) * 100; // calculate percentage proccessed
        printProgress(p / 100); // show updated progress
        
    }
    cout << endl;

    enc.clear();
    aes.encrypt_end(enc);
    fwrite(enc.data(), enc.size(), 1, out);

    fclose(in);
    fclose(out);

   return 0; 
}

int decrypt(string in_file, string out_file, vector<unsigned char> vector_key) {
    ByteArray key, dec;
    size_t file_len, key_len = 0;

    FILE *in, *out;

    srand(time(0));

    while (vector_key[key_len] != 0) {
        key.push_back(vector_key[key_len++]);
    }

    in = fopen(in_file.c_str(), "rb");
    if (in == 0) {
        return 1;
    }

    out = fopen(out_file.c_str(), "wb");
    if (out == 0) {
        return 1;
    }

    Aes256 aes(key);

    fseeko64(in, 0, SEEK_END);
    file_len = ftell(in);
    fseeko64(in, 0, SEEK_SET);

    aes.decrypt_start(file_len);
    double processed;

    while (!feof(in)) {
        unsigned char buffer[BUFFER_SIZE];
        size_t buffer_len;

        buffer_len = fread(buffer, 1, BUFFER_SIZE, in);
        if(buffer_len > 0)  {
            dec.clear();
            aes.decrypt_continue(buffer, buffer_len, dec);
            fwrite(dec.data(), dec.size(), 1, out);
        }
        processed += buffer_len;
        double p = (processed / file_len) * 100; // calculate percentage proccessed
        printProgress(p / 100); // show updated progress
    }
    cout << endl;

    dec.clear();
    aes.decrypt_end(dec);
    fwrite(dec.data(), dec.size(), 1, out);

    fclose(in);
    fclose(out);

    return 0;
}
