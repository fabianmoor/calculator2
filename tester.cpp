#include <iostream>
#include <cstring>
#include <string>

bool is_listEmpty(char* x) {
  return std::strlen(x) == 0;
}


bool is_Char(char x) {
    return (typeid(x) == typeid(char));
}

int main() {
    char x = 'x';

    std::cout << is_Char(x) << std::endl;

}
//char x[1] = {'*'};

//int main() {
//    std::cout << is_listEmpty(x) << std::endl;
//  return 0;
//}


