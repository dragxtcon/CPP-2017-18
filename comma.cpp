// Waylon Peng, Period 1
// Sep172017
// Lab 2b: Comma Inserter (2.17)
// Asks the user for a number between 1000 and 999999, and inserts a comma in the correct place.

#include <iostream>
using namespace std;

int main() {
    cout << "Enter a number between 1000 and 999999." << endl; // Outputs prompt
    string in = "1000"; // Declares in and gets value from user
    cin >> in;

    // Outputs the first non-last-3 digits of input number, a comma, then the last 3 digits.
    cout << in.substr(0, in.length() - 3) << "," << in.substr(in.length() - 3, 3);

    return 0;
}
