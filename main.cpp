// main.cpp / This file contains the main() method

#include <iostream>
#define MULTI_LINE_STRING(a)

using namespace std;

void greeting()
{
    const char *line1 = "/ ___|   / ___|  _ __   _   _   _ __   | |_ \n";
    const char *line2 = "\\___ \\  | |     | '__| | | | | | '_ \\  | __|\n";
    const char *line3 = " ___) | | |___  | |    | |_| | | |_) | | |_ \n";
    const char *line4 = "|____/   \\____| |_|     \\__, | | .__/   \\__|\n";
    const char *line5 = "                        |___/  |_|          \n";

    cout << "" << endl;
    cout << line1;
    cout << line2;
    cout << line3;
    cout << line4;
    cout << line5;
}

int main(int argc, char** argv)
{
    greeting();
}
