/**
 * scrypt-lite
 * hash.cpp
 * 
 * @autor Leon Latsch
 * @version 1.0
 */

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include "lib/picosha2.h"

using namespace std;

vector<unsigned char> sha256Hash(string str) {
    vector<unsigned char> hash(32);
    picosha2::hash256(str.begin(), str.end(), hash.begin(), hash.end());
    return hash;
}