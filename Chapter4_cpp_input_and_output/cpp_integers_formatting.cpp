#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = -2;
    cout << showpos << a << endl;
    cout << noshowpos;

    int aNumber;
    cout << "Please input an integer: ";
    cin >> aNumber;

    cout << "Octal\tDecimal\tHexadecimal\tHexadecimal upper\n"
    << oct << aNumber << "\t"
    << dec << aNumber << "\t"
    << hex << aNumber << "\t\t"
    << uppercase << hex<< aNumber << "\t\n";

    cout << dec << b << "   " << hex << b << endl;
    return 0;
}