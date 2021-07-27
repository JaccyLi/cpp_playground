#include <iostream>
#include <iomanip>

using namespace std;

// Desc: 
int main() {

    //a.   Left-justify the number 0.123456 in an output field with a width of 15.
    cout << setfill('=') << setw(15) << left << 0.123456 << endl;

    //b.   Output the number 23.987 as a fixed point number rounded to two dec-imal places, 
    //     right-justifying the output in a field with a width of 12.
    cout << right << setw(12) << fixed << setprecision(2) << 23.987 << endl;

    //c.   Output the number –123.456 as an exponential and with four decimalspaces. 
    //     How useful is a field width of 10?
    cout << scientific << setprecision(4) << -123.456 << endl;

    return 0;

}