#include <iostream>

using namespace std;

// Desc: 
int main() {

    int a = 20;
    double b = 1.23;
    cout << "minus a: " << - a << endl;

    int c = - a;
    cout << "c : " << c << endl;

    cout << "a++: " << a++ << endl;   // 20
    cout << "a: " << a << endl;       // 21
    cout << "++a: " << ++a << endl;   // 22

    cout << "b--: " << b-- << endl;   // 1.23
    cout << "b: " << b << endl;       // 0.23
    cout << "--b: " << --b << endl;   // -0.77

    return 0;
}