// hash.cpp / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include "lib/picosha2.h"

using namespace std;

string sha256Hash(string str) {
    string hash = picosha2::hash256_hex_string(str);
    return hash;
}