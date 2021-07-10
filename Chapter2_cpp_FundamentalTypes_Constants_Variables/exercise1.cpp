#include <iostream>
#include <typeinfo>
using namespace std;

// display the memory required by all fundamental types
int main() {
    bool a = 1;
    short b = 2;
    int c = 3;
    long d = 444444;
    float e = 2.718281828459;
    double f = 2.718281828459;
    long double g = 2.718281828459;
    char ch = 0x11;

    cout << "Size of a: " << sizeof(a) << " bytes" << endl;
    cout << "Size of b: " << sizeof(b) << " bytes" << endl;
    cout << "Size of c: " << sizeof(c) << " bytes" << endl;
    cout << "Size of d: " << sizeof(d) << " bytes" << endl;
    cout << "Size of e: " << sizeof(e) << " bytes" << endl;
    cout << "Size of f: " << sizeof(f) << " bytes" << endl;
    cout << "Size of g: " << sizeof(g) << " bytes" << endl;

    cout << "typid(bool)  : " << typeid(bool).name() << endl;
    cout << "typid(int)   : " << typeid(int).name() << endl;
    cout << "typid(short) : " << typeid(short).name() << endl;
    cout << "typid(long)  : " << typeid(long).name() << endl;
    cout << "typid(double): " << typeid(double).name() << endl;
    cout << "typid(char)  : " << typeid(char).name() << endl;
    cout << "typid(float) : " << typeid(float).name() << endl;

    cout << "typid(a): " << typeid(a).name() << endl;
    cout << "typid(b): " << typeid(b).name() << endl;
    cout << "typid(c): " << typeid(c).name() << endl;
    cout << "typid(d): " << typeid(d).name() << endl;
    cout << "typid(e): " << typeid(e).name() << endl;
    cout << "typid(f): " << typeid(f).name() << endl;
    cout << "typid(g): " << typeid(g).name() << endl;
}