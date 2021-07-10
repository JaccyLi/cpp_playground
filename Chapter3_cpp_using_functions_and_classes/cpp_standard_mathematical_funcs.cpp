#include <iostream>
#include <cmath>
using namespace std;

// Desc: 
int main() {
    double a;
    cout << "Give a double number: ";
    cin >> a;
    cout << "sin(" << a << "): " << sin(a) << endl;
    cout << "cos(" << a << "): " << cos(a) << endl;
    cout << "tan(" << a << "): " << tan(a) << endl;
    cout << "atan(" << a << "): " << atan(a) << endl;
    cout << "cosh(" << a << "): " << cosh(a) << endl;
    cout << "sqrt(" << a << "): " << sqrt(a) << endl;
    cout << "pow(" << a << ", " << a << "): " << pow(a, a) << endl;
    cout << "exp(" << a << "): " << exp(a) << endl;
    cout << "log(" << a << "): " << log(a) << endl;
    cout << "log10(" << a << "): " << log10(a) << endl;
}