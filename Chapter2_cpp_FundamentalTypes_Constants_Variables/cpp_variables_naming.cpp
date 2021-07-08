#include <iostream>
using namespace std;

int globalVar;   // global variable
double globalVar2 = 3.1415926; // explicit initialization

int main() {

    char ch('A'); // local var, or char ch = 'A';

    cout << "value of globalVar :    " << globalVar << endl;
    cout << "value of globalVar2:    " << globalVar2 << endl;
    cout << "character in ch    :    " << ch << endl;

    int i, j = 123, k = 200; // local var without and with initialization

    cout << "i is :    " << i << endl;
    cout << "j is :    " << j << endl;
    cout << "k is :    " << k << endl;

    i = i + k;
    j = j + i;

    cout << "do: i = i + k, j = j + i" << endl;

    cout << "i is :    " << i << endl;
    cout << "j is :    " << j << endl;
    cout << "k is :    " << k << endl;
}