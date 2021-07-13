#include <iostream> // Declaration of cin, cout
#include <string>   // Declaration of class string
using namespace std;

int main() {
    string tip("Tell me your name: "),
    name,
    line(50, '*'),  // string with 50 *
    greet = "Hey, ";

    cout << tip;
    getline(cin, name);  // get a sring in one line

    greet = greet + name;

    cout << line << endl
         << greet << endl;
    cout << "Good name, your name is " << name.length() << " characters long!" << endl;

    cout << line << endl;

    return 0;
}