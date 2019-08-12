// main.cpp / This file contains the main() method

#include <iostream>

using namespace std;

void greeting()
{
    const char *line0 = " ____     ____                          _\n";
    const char *line1 = "/ ___|   / ___|  _ __   _   _   _ __   | |_ \n";
    const char *line2 = "\\___ \\  | |     | '__| | | | | | '_ \\  | __|\n";
    const char *line3 = " ___) | | |___  | |    | |_| | | |_) | | |_ \n";
    const char *line4 = "|____/   \\____| |_|     \\__, | | .__/   \\__|\n";
    const char *line5 = "                        |___/  |_|          \n";

    cout << endl;
    cout << "############################################" << endl;
    cout << line0;
    cout << line1;
    cout << line2;
    cout << line3;
    cout << line4;
    cout << line5;
    cout << endl;
    cout << "############################################" << endl;
    cout << endl;
}

int main(int argc, char** argv)
{
    greeting();
}
