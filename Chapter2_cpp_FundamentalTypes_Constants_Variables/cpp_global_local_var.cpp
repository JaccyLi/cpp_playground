#include <iostream>
using namespace std;

void outLocal();

// global variable
const double pi = 3.1415926;

int main() {
    // local variable
    double area, circuit, radius;
    cout << "Inpu a radius: ";
    cin >> radius;

    area = pi * radius * radius;
    circuit = 2 * pi * radius;

    // 默认cout输出float类型数时, 最多输出6位, 后缀不为0
    cout << "Raduis is : " << radius << endl;
    cout << "Area is   : " << area << endl;
    cout << "Circuit is: " << circuit << endl;

    outLocal();
}

void outLocal() {
    char ch = 'A';
    cout << "I'm a local variable from outLoal(): " << ch << endl;
}