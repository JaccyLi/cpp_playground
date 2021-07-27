// Example program
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

int main()
{

    string line, remain;
    getline(cin, line, '.');
    cin >> remain;

    cout << "line: " << line << endl;
    cout << "remain: " << remain << endl;

}