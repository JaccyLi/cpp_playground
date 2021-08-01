// Evaluating operands in logical expressions.
#include <iostream>

using namespace std;
int main(){
    cout << boolalpha;
    // Outputs boolean values
    // as true or false
    bool res = false;
    int y = 5;
    res = 7 || (y = 0);
    cout << "Result of (7 || (y = 0)): " << res // true
         << endl;
    cout << "Value of y: " << y << endl; // 0
    int  a, b, c;
    a = b = c = 0;
    res = ++a || ++b && ++c;
    cout << '\n'<< "  res = " << res // true
         << ",   a = " << a          // 1
         << ",   b = " << b          // 0
         << ",   c = " << c << endl; // 0
    a = b = c = 0;
    res = ++a && ++b || ++c;
    cout << "  res = " << res // true
         << ",   a = " << a   // 1
         << ",   b = " << b   // 1
         << ",   c = " << c << endl; // 0
    return 0;
 }