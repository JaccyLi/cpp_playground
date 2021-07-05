#include <iostream>
using namespace std;

void intSize();
void charSize();
void intArithmetic();
void charArithmetic();

int main() {

    intSize();
    charSize();
    intArithmetic();
    charArithmetic();
}

void intSize() {
    int a;
    unsigned int b;
    signed int c;
    cout << "size of a is: " << sizeof(a) << endl;
    cout << "size of b is: " << sizeof(b) << endl;
    cout << "size of c is: " << sizeof(c) << endl;
}

void charSize() {
    char a;
    unsigned char b;
    signed char c;

    cout << "size of char a: " << sizeof(a) << endl;
    cout << "size of unsigned char b: " << sizeof(b) << endl;
    cout << "size of signed char c: " << sizeof(c) << endl;

}

void intArithmetic() {
    int a = 122;
    int b = 233;
    int c = a + b;

    cout << "122 + 233 = " << c << endl;
}

void charArithmetic() {
    char chara = 'A', charb = 'b';
    cout << "'A' = " << chara + 0<< endl;
    cout << "'b' = " << charb + 0<< endl;
    cout << "'A' + 'b' = " << chara + charb << endl;
}