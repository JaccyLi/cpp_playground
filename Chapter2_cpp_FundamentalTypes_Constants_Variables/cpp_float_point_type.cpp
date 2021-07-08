#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a = 11;
    long ab = 11;
    double b = 100;
    cout << fixed << setprecision(9);
    cout << a << endl;
    cout << a/3.3 << endl;
    cout << ab/3.3 << endl;
    cout << b/6.6 << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(ab) << endl;
    cout << sizeof(b) << endl;
}

