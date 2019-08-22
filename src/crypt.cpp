/**
 * scrypt-lite
 * crypt.cpp
 * 
 * @see https://github.com/Urban82/Aes256/blob/master/utils/
 * 
 * @autor Leon Latsch
 * @version 1.0
 */

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

int encrypt(string inFile, string outFile, vector<unsigned char> vectorKey) {
    ByteArray key, enc;
    size_t fileLength, keyLength = 0; // In bytes

    FILE *in, *out;

    srand(time(0));

    // Convert key
    while (vectorKey[keyLength] != 0) {
        key.push_back(vectorKey[keyLength++]);
    }

    // Read files
    in = fopen(inFile.c_str(), "rb");
    if (in == 0) {
        return 1;
    }

    out = fopen(outFile.c_str(), "wb");
    if (out == 0) {
        return 1;
    }

    Aes256 aes(key);

    fseeko64(in, 0, SEEK_END);
    fileLength = ftell(in);
    fseeko64(in, 0, SEEK_SET);

    enc.clear();
    aes.encrypt_start(fileLength, enc);
    fwrite(enc.data(), enc.size(), 1, out);

    double processed;

    while (!feof(in)) {
        unsigned char buffer[BUFFER_SIZE];
        size_t bufferLength;

        bufferLength = fread(buffer, 1, BUFFER_SIZE, in);
        if(bufferLength > 0) {
            enc.clear();
            aes.encrypt_continue(buffer, bufferLength, enc);
            fwrite(enc.data(), enc.size(), 1, out);
        }
        processed += bufferLength;
        double p = (processed / fileLength) * 100; // calculate percentage proccessed
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

int decrypt(string inFile, string outFile, vector<unsigned char> vectorKey) {
    ByteArray key, dec;
    size_t fileLength, keyLength = 0;

    FILE *in, *out;

    srand(time(0));

    while (vectorKey[keyLength] != 0) {
        key.push_back(vectorKey[keyLength++]);
    }

    in = fopen(inFile.c_str(), "rb");
    if (in == 0) {
        return 1;
    }

    out = fopen(outFile.c_str(), "wb");
    if (out == 0) {
        return 1;
    }

    Aes256 aes(key);

    fseeko64(in, 0, SEEK_END);
    fileLength = ftell(in);
    fseeko64(in, 0, SEEK_SET);

    aes.decrypt_start(fileLength);
    double processed;

    while (!feof(in)) {
        unsigned char buffer[BUFFER_SIZE];
        size_t bufferLength;

        bufferLength = fread(buffer, 1, BUFFER_SIZE, in);
        if(bufferLength > 0)  {
            dec.clear();
            aes.decrypt_continue(buffer, bufferLength, dec);
            fwrite(dec.data(), dec.size(), 1, out);
        }
        processed += bufferLength;
        double p = (processed / fileLength) * 100; // calculate percentage proccessed
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
