#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "current default field width: " << cout.width() << endl;
    cout << "aaa" << endl;
    cout.width(8);
    int w = cout.width();
    cout << "AAA" << endl;
    cout << "current field width w: " << w << endl;
    int w2 = cout.width();
    cout << "current field width w2: " << w2 << endl;
    cout.width(2);
    int nw = cout.width();
    cout << "current default field width again?: " << nw << endl;
    cout << "current default field width: " << "5 space ahead of me?" << endl;

    for (int i=0;i<10;i++)
    {
        if (i%2 == 0)
        {
            cout << '|' << setw(10);
        }
        else if (i%2 == 1)
        {
            cout << 'A' << '|';
            cout << endl;
        }
    }

    cout << setfill('*') << setw(30) << '\0' << endl;
    cout << '|' << setfill(' ') << setw(29) << '|' << endl;
    cout.fill('=');
    cout << setw(30) << '\0' << endl;

    cout.width(8); cout.fill('0');
    cout << internal << -123 << endl;
    cout << left << cout.width(8) << 'H' << endl;

}

/*
Output: 
current default field width: 0
aaa
     AAA
current field width w: 8
current field width w2: 0
current default field width again?: 2
current default field width: 5 space ahead of me?
|         A|
|         A|
|         A|
|         A|
|         A|
*****************************
|                            |
=============================
-0000123
00000000H
*/