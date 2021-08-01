/*
The int variable x contains the number 7. 
Calculate the value of the following logical expressions:
a.x < 10 && x >= –1
b.!x && x >= 3
c.x++ == 8 || x == 7
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 7;
    bool a,b,c;

    a = x < 10 && x >= -1; // 7 < 10 && 7 >= -1 --> true && true --> true
    b = !x && x >= 3;      // !7 && 7 >= 3 --> false && true --> false
    c = x++ == 8 || x == 7; // 7 == 8 || 8 == 7 --> false || false --> false

    cout << "a: " << boolalpha << a << endl;
    cout << "b: " << boolalpha << b << endl;
    cout << "c: " << boolalpha << c << endl;

    return 0;
}
