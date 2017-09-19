// Waylon Peng, Period 1
// Sep172017
// Lab 2a: Sum, Difference, Product, and Average. (2.4)
// Asks the user for two integers, then prints their sum, difference, product, and average.

#include <iostream>
using namespace std;

int main() {
    cout << "Enter two integers." << endl; // Outputs prompt
    int int1 = 0; // Declares int1 and gets value from user
    cin >> int1;
    int int2 = 0; // Declares int2 and gets value from user
    cin >> int2;

    cout << "Sum: " << int1 + int2 << endl; // Outputs calculated sum
    cout << "Difference: " << int1-int2 << endl; // Outputs difference
    cout << "Product: " << int1*int2 << endl; // Outputs product
    cout << "Average: " << ((double)int1+int2)/2 << endl; // Outputs average

    return 0;
}
