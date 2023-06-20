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
    int key;
    float sum;

    leftcolumn = 0;
    rightcolumn = 0;

    leftcount = 0;
    rightcount = 0;

    sum = 0;
    method = '0';
    
    while (true) {
        key = getch();
        // Om ingen method är funnen så 
        // kollar vi vilken lista vi ska
        // lägga key-pressen i.
        if (is_Char(key)) {
            method = key;        
            cout << method << endl;
        } else {            
            if (is_varEmpty(method)) {
                leftcolumn = calculate(key, 0.0, leftcolumn);
                leftcount++;
            } else {
                rightcolumn = calculate(key, 0.0, rightcolumn);
                rightcount++;
            }
        }

        cout << leftcolumn << " " << rightcolumn << endl;
    }

    return 0;

}
