/*
What values do the following arithmetic expressions have?
a.3/10  --> 0
b.11%4  --> 3
c.15/2.0 --> 7.5
d.3 + 4 % 5  --> 7
e.3 * 7 % 4 --> 1
f.7 % 4 * 3 --> 9
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "a: " << 3/10 << endl;
    cout << "b: " << 11%4 << endl;
    cout << "c: " << 15/2.0 << endl;
    cout << "d: " << 3+4%5 << endl;
    cout << "e: " << 3*7%4 << endl;
    cout << "f: " << 7%4*3 << endl;

    return 0;
}
