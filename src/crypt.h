// crypt.h / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <vector>

using namespace std;

void encrypt(string filename, string extension, vector<char> key);

void decrypt(string filename, string extension, vector<char> key);