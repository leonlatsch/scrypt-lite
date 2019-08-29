/**
 * scrypt-lite
 * common.cpp
 * 
 * @autor Leon Latsch
 * @version 1.1
 */

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <iostream>
#include <sys/stat.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>

using namespace std;

void info(string const &message) {
    cout << "[" << "\033[1;36mINFO\033[0m" << "] " << message << endl;
}

void error(string const &message) {
    cerr << "[" << "\033[1;31mERROR\033[0m"  <<"] " << message << endl;
}

void warn(string const &message) {
    cout << "[" << "\033[1;33mWARN\033[0m" << "] " << message << endl;
}

bool exists(string const &file) {
    struct stat buffer;
    return (stat (file.c_str(), &buffer) == 0);
}

bool endsWith (string const &fullString, string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

string getFileSize(string &filename) {
    FILE *file = fopen(filename.c_str(), "rb");
    fseeko64(file, 0, SEEK_END);
    double fileLen = ftell(file);
    fseeko64(file, 0, SEEK_SET);
    fclose(file);
    
    double kb = fileLen / 1024;
    double mb = kb / 1024;
    double gb = mb / 1024;

    ostringstream strs;
    strs << fixed;
    strs << setprecision(2);

    if (gb >= 1) {
        strs << gb;
        return strs.str() + "GB";
    } else if (mb >= 1) {
        strs << mb;
        return strs.str() + "MB";
    } else if (kb >= 1) {
        strs << kb;
        return strs.str() + "KB";
    } else {
        strs << fileLen;
        return strs.str() + "Bytes";
    }
}

int getFileBytes(string &filename) {
    FILE *file = fopen(filename.c_str(), "rb");
    fseeko64(file, 0, SEEK_END);
    int fileLen = ftell(file);
    fseeko64(file, 0, SEEK_SET);
    fclose(file);

    return fileLen;
}

void setStdinEcho(bool enable = true) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

string read(string message, bool withEcho = true) {
    cout << "[" << "\033[1;32mREAD\033[0m" << "] " << message;
    setStdinEcho(false);
    string content;
    cin >> content;
    setStdinEcho(true);
    cout << endl;
    return content;
}

bool replace(string &str, const string &from, const string &to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
