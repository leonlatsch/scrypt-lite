// main.cpp / This file contains the main() method

#include <iostream>

using namespace std;

int METHOD; // Either 0 (encryption) or 1 (decryption)

void greeting()
{
    const char *breakLine = "############################################\n";

    const char *line0 = " ____     ____                          _\n";
    const char *line1 = "/ ___|   / ___|  _ __   _   _   _ __   | |_ \n";
    const char *line2 = "\\___ \\  | |     | '__| | | | | | '_ \\  | __|\n";
    const char *line3 = " ___) | | |___  | |    | |_| | | |_) | | |_ \n";
    const char *line4 = "|____/   \\____| |_|     \\__, | | .__/   \\__|\n";
    const char *line5 = "                        |___/  |_|          \n";

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

int error(int code, string const &message) {
    cerr << message << endl;
    return code;
}

int main(int argc, char** argv)
{
    // Print a ASCII Logo
    greeting();

    // Exit on wrong usage
    if (argc < 3) {
        cerr << "Usage: scrypt-lite [OPERATION] [FILENAME]" << endl;
        return 0;
    }

    // Read arguments
    const char *method = argv[1];
    const char *filename = argv[2];

    // Set method or exit
    if (method == "-e" || method == "--encrypt") {
        METHOD = 0;
    } else if (method == "-d" || method == "--decrypt") {
        METHOD = 1;
    } else {
        return error(1, "Invalid method");
    }
}
