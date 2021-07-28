#include <iostream>
using namespace std;

// Desc: 
int main() {
    double dnumber = 6.0;
    int inumber = 8;

    cout << ++inumber << endl; // inumber: 9
    cout << dnumber-- << endl; // dnumber: 6.0
    cout << inumber + dnumber*inumber - dnumber << endl; // inumber: 9, dnumber: 5;

    cout << -dnumber * inumber + inumber % 3 * dnumber / inumber << endl;
    cout << (-dnumber * inumber) + (inumber % 2 * dnumber / inumber) << endl;

    //cout << 5.0/9 << endl;

}