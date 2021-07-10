 //  Calculating powers with
//  the standard function pow()
#include <iostream> // Declaration of cout
#include <cmath> // Prototype of pow(), thus:
                 // double pow( double, double);
using namespace std;

double myCalc(double a, double b);

int main() {
    double x = 2.5, y;

    // By means of a prototype, the compiler generates
    // the correct call or an error message!

    // Computes x raised to the power 3:
    // y = pow("x", 3.0); // Error! String is not a number
    // y = pow(x + 3.0);  // Error! Just one argument
    y = pow(x, 3.0);   // ok!
    y = pow(x, 3);     // ok! The compiler converts the
                     // int value 3 to double.

    cout << "2.5 raised to 3 yields:       "
         << y << endl;

    // Calculating with pow() is possible:
    cout << "2 + (5 raised to the power 2.5) yields: "
    <<  2.0 + pow(5.0, x) << endl;

    double c = myCalc(2.33, 3.22);
    cout << "Im main() myCalc() returns: " << c << endl;

    return 0; 
}

double myCalc(double a, double b) {
    cout << "In myCalc(): ";
    cout << a << " + " << b << " = " <<  a + b << endl;
    return a+b;
}