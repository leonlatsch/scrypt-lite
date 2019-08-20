// commons.cpp / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <iostream>

void info(std::string const message) {
    std::cout << "[" << "\033[1;36mINFO\033[0m" << "] " << message << std::endl;
}

void error(std::string const &message) {
    std::cerr << "[" << "\033[1;31mERROR\033[0m"  <<"] " << message << std::endl;
}