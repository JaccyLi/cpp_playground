#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include <limits>

using namespace std;

// FileName:          cpp_input_formatting.cpp
// Date:              2021-07-19
// 

int main()
{
    float x, y = 3.14;
    string title; 

    cout << "input a title: ";
    cin >> setw(16);
    //cin.width(16);
    cin >> title;
    //cin.clear();
    //cin.sync();
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "input a float: ";
    cin >> x;
    cout <<"title: " << title << endl;
    cout << fixed << setprecision(2) << x << endl;

    return 0;
}
