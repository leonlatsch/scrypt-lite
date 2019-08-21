// crypt.h / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <vector>

using namespace std;

int encrypt(string in_file, string out_file, vector<unsigned char> vector_key);

int decrypt(string filename, string extension, vector<unsigned char> vector_key);