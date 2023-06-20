#include <cstring>
#include <string>
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Check if list is empty
bool is_varEmpty(char x) {
    return x == 0;
}

// Function that checks if variable is Char
bool is_Char(int x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || x == '/' || x == '+' || x == '*' || x == '-';
}

char getch() {
    char ch;
    struct termios oldSettings, newSettings;

    // Save current terminal settings
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;

    // Disable terminal echo
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    // Loop until a valid input is entered
    do {
        // Read a single character from the user
        read(STDIN_FILENO, &ch, 1);
    } while (ch != '+' && ch != '-' && ch != '*' && ch != '/' && (ch < '0' || ch > '9') && ch != 127);

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return ch;
}

float calculate(int x, float result) {
    // Multiply the result by 10 and add x to the ones place
    result = result * 10 + x;
    return result;
}


void printCalculator(float left, float right, float sum, char oper) {
    system("clear");
    cout << "------------------------" << endl;
    cout << "|        Fabians       |" << endl;
    cout << "|       Calculator     |" << endl;
    cout << "|                      |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|                      |" << endl;
    cout << "| " << left;
        if (oper != '0') {
            cout << " " << oper;
        }
        if (right != 0) {
            cout << " " << right;
        }
    cout << endl;
    cout << "| " << sum << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "|                      |" << endl;
    cout << "------------------------" << endl; 
}

