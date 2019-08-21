// commons.h / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <sys/stat.h>
#include <iostream>

using namespace std;

/**
 * Print a message with a [INFO] prefix
 * 
 * @param message the message to be printed
 */
void info(std::string const message);

/**
 * Print a message with a [ERROR] prefix
 * 
 * @param message the message to be printed
 */
void error(std::string const &message);

/**
 * Check wether a file does exist
 * 
 * @param file The filename of the file
 * 
 * @return true, if the file exists
 */
bool exists(const std::string& file);

/**
 * En/disables the echo of stdin
 * Used for password input
 */
void setStdinEcho(bool enable = true);

/**
 * Read a string from stdin
 */
string read(string message, bool withEcho = true);