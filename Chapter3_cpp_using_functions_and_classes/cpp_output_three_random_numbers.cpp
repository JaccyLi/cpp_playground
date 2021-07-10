#include <iostream>    // Declaration of cin and cout
#include <cstdlib>     // Prototypes of srand() and rand(): void srand( unsigned int seed );
                       //                                   int rand( void );

using namespace std;

// Desc: 
int main() {
    unsigned int seed;
    int r1, r2, r3;

    cout << "\n\n";
    cout << " --- Gen Random Numbers --- \n" << endl;
    cout << "Input a int number to initialize the genetator: ";

    cin >> seed;

    srand(seed);

    r1 = rand();
    r2 = rand();
    r3 = rand();

    cout << "Generated three numbers: "
         << r1 << "    " << r2 << "    " << r3 << endl << endl;

}