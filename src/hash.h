/**
 * scrypt-lite
 * hash.h
 * 
 * @autor Leon Latsch
 * @version 1.0
 */

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <vector>

/**
 * Hash a string with SHA-256 as vector
 */
std::vector<unsigned char> sha256Hash(std::string str);