#include <iostream>
#include <iomanip> // setprecision()
using namespace std;

void ex();

int main() {
    long double x = 3.145;

    cout << "1-->: " << showpoint << x << endl;

    cout.precision(4);
    cout << "2-->: "<< showpoint << x << endl;
    cout << "3-->: "<< noshowpoint << x << endl;
    cout << "4-->: "<< fixed << x << endl;
    
    cout << setprecision(7);
    cout << "5-->: "<< x << endl;

    // get current precision
    const int p = cout.precision();
    cout << "6-->: " << p << endl; 

    cout.precision(12);
    const int pn = cout.precision();
    cout << "7-->: " << pn << endl; 

    cout << "from ex(): \n";
    ex();
}

void ex() {
    double x = 12.0;
    cout.precision(2);// Precision 2
    cout << " By default:   " << x << endl;
    cout << " showpoint:  " << showpoint<< x << endl;
    cout << " fixed:      " << fixed<< x << endl;
    cout << " scientific: " << scientific<< x << endl;
}