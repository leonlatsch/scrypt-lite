/**
 * scrypt-lite
 * crypt.cpp
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

#include "lib/AES/AES.h"
#include "progressbar.h"

#define BUFFER_SIZE 1024

using namespace std;

int encrypt(string inFile, string outFile, unsigned char key[]) {
    unsigned int fileLen = 0; // In bytes

    FILE *in, *out;

    // Read files
    in = fopen(inFile.c_str(), "rb");
    if (in == 0) {
        return 1;
    }

    out = fopen(outFile.c_str(), "wb");
    if (out == 0) {
        return 1;
    }

    double processed;
    AES aes(256);
    fileLen = ftell(in);

    while (!feof(in)) {
        unsigned char buffer[BUFFER_SIZE];
        unsigned int bufferLen;

        bufferLen = fread(buffer, 1, BUFFER_SIZE, in);
        if(bufferLen > 0) {
            fwrite(aes.EncryptECB(buffer, bufferLen, key, fileLen), bufferLen, 1, out);
        }

        processed += bufferLen;
        double p = (processed / fileLen) * 100; // calculate percentage proccessed
        printProgress(p / 100); // show updated progress
        
    }
    cout << endl;

    fclose(in);
    fclose(out);

   return 0; 
}

int decrypt(string inFile, string outFile, unsigned char key[]) {
    unsigned int fileLen = 0;

    FILE *in, *out;

    in = fopen(inFile.c_str(), "rb");
    if (in == 0) {
        return 1;
    }

    out = fopen(outFile.c_str(), "wb");
    if (out == 0) {
        return 1;
    }

    double processed;
    AES aes(256);
    fileLen = ftell(in);

    while (!feof(in)) {
        unsigned char buffer[BUFFER_SIZE];
        unsigned int bufferLen;

        bufferLen = fread(buffer, 1, BUFFER_SIZE, in);
        if(bufferLen > 0)  {
            fwrite(aes.EncryptECB(buffer, bufferLen, key, fileLen), bufferLen, 1, out);
        }
        processed += bufferLen;
        double p = (processed / fileLen) * 100; // calculate percentage proccessed
        printProgress(p / 100); // show updated progress
    }
    cout << endl;

    fclose(in);
    fclose(out);

    return 0;
}
