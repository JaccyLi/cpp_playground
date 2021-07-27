#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// FileName:          Chapter4_cpp_input_and_output/cpp_unformatted_input.cpp
// Date:              2021-07-22
// 

string header("--- Demo for Unformatted Input ---");

int main()
{
    string prefix, remain;

    cout << header
         << "\n\nPress <return> to continue\n"; 

    cin.get();

    cout << "\nPlease enter a sentence with several words!"
         << "\nEnd with <!> and <return>."
         << endl;

    cin >> prefix;                // Read the first word
    getline( cin, remain, '!');   // and the remaining text
                                  // up to the character !

    cout << "\nThe first word:   " << prefix 
         << "\nRemaining text: " << remain << endl;

    return 0;
}
