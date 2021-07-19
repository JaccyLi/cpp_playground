#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // output char
    int char1 = '0';
    char char2 = 'A';
    cout <<"the ascii value: " << char1 << " is char '0'" << endl;
    cout << "char2 is: " << char2 << endl;

    // output boolean
    bool isShe = true;
    bool imJack = true;
    bool doorOpen = 0;
    cout << "Is she? " << isShe  << endl;
    cout << "I'm Jack? " << boolalpha << imJack  << endl;
    cout << "Door is Open? " << doorOpen << endl;

    // output string
    string s("Summer is Over ");
    cout << left
         << setfill('?')
         << setw(30) << s << endl;
    cout << right 
         << setfill('?')
         << setw(30) << s << endl;
}