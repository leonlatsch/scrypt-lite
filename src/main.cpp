// main.cpp / This file contains the main() method

#include <sys/stat.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int METHOD; // Either 0 (encryption) or 1 (decryption)
string FILENAME; // The name of the source file
string EXTENSION; // Extension for the output file

void greeting() {
    const char *breakLine = "############################################\n";

    const char* line0 = " ____     ____                          _\n";
    const char* line1 = "/ ___|   / ___|  _ __   _   _   _ __   | |_ \n";
    const char* line2 = "\\___ \\  | |     | '__| | | | | | '_ \\  | __|\n";
    const char* line3 = " ___) | | |___  | |    | |_| | | |_) | | |_ \n";
    const char* line4 = "|____/   \\____| |_|     \\__, | | .__/   \\__|\n";
    const char* line5 = "                        |___/  |_|          \n";

    cout << endl;
    cout << breakLine;
    cout << line0;
    cout << line1;
    cout << line2;
    cout << line3;
    cout << line4;
    cout << line5;
    cout << endl;
    cout << breakLine;
    cout << endl;
}

void info(string const message) {
    cout << "[" << "\033[1;36mINFO\033[0m" << "] " << message << endl;
}

int error(int code, string const &message) {
    cerr << "[" << "\033[1;31mERROR\033[0m"  <<"] " << message << endl;
    exit(code);
}

void initialize() {
    EXTENSION = ".crypt";
}

inline bool exists(const string& file) {
    struct stat buffer;
    return (stat (file.c_str(), &buffer) == 0);
}

int main(int argc, char** argv) {
    initialize();

    greeting(); // Print a ASCII Logo

    // Exit on wrong usage
    if (argc < 3) {
        info("Usage: scrypt-lite [OPERATION] [FILENAME]");
        return 0;
    }

    // Read arguments
    string method = argv[1];
    string filename = argv[2];

    // Set method or exit
    if (method == "-e" || method == "--encrypt") {
        METHOD = 0;
    } else if (method == "-d" || method == "--decrypt") {
        METHOD = 1;
    } else {
        error(1, "Invalid method");
    }

    FILENAME = filename;

    // Display mode message
    string modeMessage = "Mode: ";
    if (METHOD == 0) {
        modeMessage += "Encryption";
    } else {
        modeMessage += "Decryption";
    }

    info(modeMessage);
    info("File: " + FILENAME);
    info("");

    if (!exists(FILENAME)) {
        error(1, "File does not exist");
    }
}
