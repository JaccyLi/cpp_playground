#include <iostream>
#include <iomanip>
using namespace std;

// Desc: find which variable defining is wrong
int main() {

    int b = '?'; // 
    cout << b << endl;
    char c('\''); // escaped ' is a plain '
    cout << c << endl;
/*
    int a(2.5); // wrong, 2.5 is not a int
    int b = '?'; // 1
    char z(500); // 500 exceed the limit of char
    int big = 40000; // On 16-bit systems, int values are <= 32767
    double he's(1.2E+5); // ' is not valid in names
    const long large; // const must initialize
    char c('\''); // 1
    unsigned char ch = '\201'; // 1
    unsigned size(40000); // 1
    float val = 12345.12345; // exceed the accuracy of 6 digits
*/
    float val = 12345.12345; // exceed the accuracy of 6 digits
    cout << val << endl; // cout 12345.1
    cout << fixed << setprecision(9);
    cout << val << endl; // cout 12345.1
    double valD = 12345.12345; // exceed the accuracy of 6 digits
    cout << valD << endl; // cout 12345.1

}