// A program containing errors!
#include <iostream>
#include <string>

using namespace std;

int main() {
    string commit("I have learned something new again!"),
    line1,
    line2;

    cout << "commit is: " << commit << endl;
    cout << "commit is " << commit.length() << " len" << endl;

    getline(cin, line1);
    getline(cin, line2);

    string con = line1 + "*" + line2;

    cout << con << endl;

    return 0;
}