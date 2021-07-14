#include <iostream>
#include <cmath>
using namespace std;

void calculateSquareRoot(double nu);
void calculateSquareRootFormat(double nu);

int main() {
    double a(4), b(12.25), c(0.0121);

    cout << "Number\tSquare Root" << endl;

    calculateSquareRootFormat(a);
    calculateSquareRootFormat(b);
    calculateSquareRootFormat(c);

    calculateSquareRoot(a);
    calculateSquareRoot(b);
    calculateSquareRoot(c);

    double x;
    cout << "Input a number to get square root: ";
    cin >> x;
    calculateSquareRoot(x);

}

void calculateSquareRoot(double nu) {
    double squareRoot = sqrt(nu);
    cout << "The square root of " << nu << " is: " << squareRoot;
    cout << endl;
}

void calculateSquareRootFormat(double nu) {
    double squareRoot = sqrt(nu);
    cout << nu << "\t" << squareRoot << "\n";
}