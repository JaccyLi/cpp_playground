/*
a.  How are operands and operators in the following expression associated?
    x = –4 * i++ – 6 % 4; 

Insert parentheses to form equivalent expressions.
b.  What value will be assigned in part a to the variable x if the variable i has avalue of –2?
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, i=-2;
    x = -4 * i++ - 6 % 4; // x = (-4 * i++) - (6 % 4) = 8 - 2 = 6
    cout << "x: " << x << endl;

    return 0;
}
