// commons.h / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <sys/stat.h>
#include <iostream>

using namespace std;

void info(std::string const message);

void error(std::string const &message);

bool exists(const std::string& file);

void setStdinEcho(bool enable = true);

string read(string message, bool withEcho = true);