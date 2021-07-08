#include <iostream>
using namespace std;

void p1(string arg1);
void p2(string arg1, string arg2);
void p3(string a);

int main() {

    string hello = "hello, from p1()";
    p1(hello);
    string im = "im a artist";
    string am = "am a soap man";
    p2(im, am);
    string mm = "\42"; // 34 --> "
    p3(mm);
    string hexmm = "\x27"; // 39 --> '
    p3(hexmm);
    string twolineStr = "I'm a one \
line string, heiheihei...";
    p3(twolineStr);

}

void p1(string arg1) {
    cout << arg1 << endl;
    cout << endl;
}


void p2(string arg1, string arg2) {
    cout << "from p2():" << endl;
    cout << "\n" << arg1 << endl;
    cout << "\t" << arg2 << endl;

    cout << "\v" << "oh, i'm down" << endl;

    cout << "\f" << "oh, i'm feed, i'm \"full\"" << endl;

    cout << "\a" << "ding?";

    cout << endl;
}


void p3(string a) {

    cout << "from p3():"<< endl; 
    cout << "what is: " << a << endl; 

}