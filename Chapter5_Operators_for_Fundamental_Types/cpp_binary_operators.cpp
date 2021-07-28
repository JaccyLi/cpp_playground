#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// FileName:          cpp_binary_operators.cpp
// Date:              2021-07-28
// 


int main()
{
    int a = 234;
    float x, y = 3.14;

    float z = y * 1.5926;
    x = y * z + (z - y);

    int b = a % 12;

    cout << z << endl;
    cout << x << endl;
    cout << b << endl;
}
