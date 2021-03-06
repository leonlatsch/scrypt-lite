/**
 * scrypt-lite
 * main.cpp
 * 
 * @autor Leon Latsch
 * @version 2.0
 */

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include "hash.h"
#include "common.h"
#include "crypt.h"

using namespace std;

int MODE; // Either 0 (encryption) or 1 (decryption)
string FILENAME_IN;  // The name of the source file
string FILENAME_OUT; // The name if the dest file
string EXTENSION; // Extension for the output file
vector<unsigned char> KEY; // Password used for key generatiron
string EMPTY; // EMPTY STRING
string VERSION;

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
    cout << "V: " << VERSION << endl;
    cout << endl;
}


void initialize() {
    EXTENSION = ".crypt";
    EMPTY = "";
    VERSION = "DEV-2.0"; // Change this to version number on release
}

void genFiles(string filename) {
    if (MODE == 0 ) {
         FILENAME_IN = filename;
         FILENAME_OUT = filename + EXTENSION;
    } else {
        FILENAME_IN = filename;
        replace(filename, EXTENSION, EMPTY);
        FILENAME_OUT = filename;
    }
}

int main(int argc, char** argv) {
    initialize();

    greeting(); // Print a ASCII Logo

    // Exit on wrong usage
    if (argc < 3) {
        info("Usage: scrypt [OPERATION] [FILENAME]");
        info("Operations:");
        info("    -e --encrypt | Encryption-Mode");
        info("    -d --decrypt | Decryption-Mode");
        return 0;
    }

    // Read arguments
    string mode = argv[1];
    string filename = argv[2];

    // Set method or exit
    if (mode == "-e" || mode == "--encrypt") {
        MODE = 0;
    } else if (mode == "-d" || mode == "--decrypt") {
        MODE = 1;
    } else {
        error("Invalid method");
        exit(1);
    }

    genFiles(filename);

    // Display mode message
    string modeMessage = "Mode: ";
    if (MODE == 0) {
        modeMessage += "Encryption";
    } else {
        modeMessage += "Decryption";
    }

    info(modeMessage);
    info("Input: " + FILENAME_IN);
    info("Output: " + FILENAME_OUT);

    if (!exists(FILENAME_IN)) {
        error("File does not exist");
        exit(1);
    }

    if (MODE == 1 && !endsWith(FILENAME_IN, EXTENSION)) {
        error(FILENAME_IN + " can't be decrypted");
        error("Look for the .crypt extension");
        exit(1);
    }

    if (getFileBytes(FILENAME_IN) < 1) {
        error("File " + FILENAME_IN + " is empty");
        exit(1);
    }

    info("Size: " + getFileSize(FILENAME_IN));
    info(EMPTY);

    string password = "a";

    if (MODE == 0) {
        string confirmPassword = "b";

        while (password != confirmPassword) {
            password = read("Enter a password: ", false);
            confirmPassword = read("Confirm your password: ", false);
            if (password != confirmPassword) {
                warn("The passwords didn't match. Try again");
            }
        }
    } else {
        password = read("Enter a password: ", false);
    }

    KEY = sha256Hash(password); // Save the password hash in global variable

    info(EMPTY);

    if (MODE == 0) {
        info("Encrypting...");
        int result = encrypt(FILENAME_IN, FILENAME_OUT, KEY);

        if (result != 0) {
            error("Could not encrypt: " + FILENAME_IN);
            exit(1);
        } else {
            info("Done");
        }
    } else {
        info("Decrypting...");
        int result = decrypt(FILENAME_IN, FILENAME_OUT, KEY);

        if (result != 0)  {
            error("Could not decrypt: " + FILENAME_IN);
            exit(1);
        } else {
            info("Done");
        }
    }
}
