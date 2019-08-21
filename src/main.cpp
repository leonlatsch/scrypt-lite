// main.cpp / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include "hash.h"
#include "common.h"
#include "crypt.h"

using namespace std;

int METHOD; // Either 0 (encryption) or 1 (decryption)
string FILENAME; // The name of the source file
string EXTENSION; // Extension for the output file
string PASSWORD; // Password used for key generatiron
string EMPTY; // EMPTY STRING

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


void initialize() {
    EXTENSION = ".crypt";
    EMPTY = "";
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
        error("Invalid method");
        exit(1);
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
    info("Output: " + FILENAME + EXTENSION);
    info(EMPTY);

    if (!exists(FILENAME)) {
        error("File does not exist");
        exit(1);
    }

    info(EMPTY);
    PASSWORD = sha256Hash(read("Enter a password: ", false));
    info(EMPTY);
    vector<unsigned char> raw_key(PASSWORD.begin(), PASSWORD.end());

    if (METHOD == 0) {
        info("Encrypting...");
        int result = encrypt(FILENAME, FILENAME + EXTENSION, raw_key);

        if (result != 0) {
            error("Could not encrypt: " + FILENAME);
            exit(1);
        } else {
            info("Done");
        }
    } else {
        info("Decrypting...");
        string file_name_buffer;
        replace(FILENAME, EXTENSION, EMPTY);
        int result = decrypt(FILENAME, file_name_buffer, raw_key);

        if (result != 0)  {
            error("Could not decrypt: " + FILENAME);
            exit(1);
        } else {
            info("Done");
        }
    }
}
