#include <iostream>
using namespace std;

// Desc: 
int main() {
    int code;
    char ch_code;
    cout << "input a positive integer: ";
    cin >> code;

    ch_code = code;
    cout << "the character input is : " << ch_code << endl;
    cout << "decimal of input is    : " << code << endl;
    cout << "octal of input is      : " << oct << code << endl;
    cout << "hexadecimal of input is: " << hex << code << endl;

    return 0;
}