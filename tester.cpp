#include <cstring>
#include <string>
#include <iostream>
#include <termios.h>
#include <unistd.h>


// Check if list is empty
bool is_varEmpty(char x) {
    return x == 0;
}

// Function that checks if variable is Char
bool is_Char(char x) {
    return (typeid(x) == typeid(char));
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

    // Read a single character from the user
    read(STDIN_FILENO, &ch, 1);

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return ch;
}


float calculate(int x, float y, float result) {
    // Multiply the result by 10 and add x to the ones place
    result = result * 10 + x;

    // Convert y to an integer by truncating the decimal part
    int yAsInt = static_cast<int>(y);

    // Multiply the result by 10 and add yAsInt to the ones place
    result = result * 10 + yAsInt;

    return result;
}


//   1 - 12
//   if 

//int main() {
//    std::cout << "Enter a character: ";
//    char input = getch();
//    std::cout << "\nYou entered: " << input << std::endl;
//
//    return 0;
//}


//
//int main() {
//    char x = 'x';
//
//    std::cout << is_Char(x) << std::endl;
//
//}
//char x[1] = {'*'};

//int main() {
//    std::cout << is_listEmpty(x) << std::endl;
//  return 0;
//}

