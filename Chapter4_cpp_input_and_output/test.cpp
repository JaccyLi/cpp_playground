// Example program
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

int main()
{
 string name;
 cin.width(6);
 cin >> name;
 cout << name << endl;
 
 cin.sync();
 
 float remain;
 cin >> remain;
 cout << remain << endl;

}