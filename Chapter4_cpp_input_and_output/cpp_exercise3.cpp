#include <iostream>
#include <iomanip>
using namespace std;

// Desc: 
int main() {
    long article_number;
    int pieces;
    double price;

    cout << "input article number: ";
    cin >> article_number;
    cout << "input pieces: ";
    cin >> pieces;
    cout << "input price per piece: ";
    cin >> price;

    cout << setw(20) << setfill(' ') << left
         << setw(20) << "Article Number"
         << setw(20) << "Number of Pieces"
         << setw(20) << "Price per piece" 
         << endl
         << setw(20) << article_number 
         << setw(20) << pieces 
         << setw(20) << fixed << setprecision(4) << price 
         << endl;
}