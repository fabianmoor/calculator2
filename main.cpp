#include "tester.cpp"
#include <thread>

using namespace std;

// från start av program båda listorna null
//
// if input == char:
//    input -> lista2
// 
// if lista2 not_empty():
//    input -> lista3
//    else:
//        input -> lista1
//

int main() {
    
    float leftcolumn;
    int leftcount;
    float rightcolumn;
    int rightcount;

    char method;
    float key;
    float sum;

    leftcolumn = 0;
    rightcolumn = 0;

    leftcount = 0;
    rightcount = 0;
    method = '0';
    sum = 0;
    while (true) {
        printCalculator(leftcolumn, rightcolumn, sum, method);
        key = getch();
        if (key == 127) { // Backspace key
            if (rightcolumn != 0) {
                rightcolumn = (int)(rightcolumn / 10);
            } else if (method != '0') {
                method = '0';
            } else if (leftcolumn != 0) {
                leftcolumn = (int)(leftcolumn / 10);
            }
        } else if (is_Char(key)) {
            method = key;
            cout << method << endl;
        } else {
            int digit = key - '0';
            if (method == '0') {
                leftcolumn = calculate(digit, leftcolumn);
                leftcount++;
            } else {
                rightcolumn = calculate(digit, rightcolumn);
                rightcount++;
            }
        }
    
        // Calculate the result if rightcolumn is not equal to 0
        if (rightcolumn != 0) {
            switch (method) {
                case '+':
                    sum = leftcolumn + rightcolumn;
                    break;
                case '-':
                    sum = leftcolumn - rightcolumn;
                    break;
                case '*':
                    sum = leftcolumn * rightcolumn;
                    break;
                case '/':
                    sum = leftcolumn / rightcolumn;
                    break;
            }
        } else {
            sum = 0;
        }
    }
    return 0;
}
