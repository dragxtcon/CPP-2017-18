// Waylon Peng, Period 1
// Sep262017
// Lab 3a: Leap Year (3.25)
// Asks the user for a year, and says whether or not it is a leap year.

#include <iostream>
using namespace std;

int main() {
    // Get year value.
    cout << "Enter a year." << endl; 
    int year = 0;
    cin >> year;

    // Check if year is divisible by 4 (leap year w/o exceptions)
    if (year % 4 == 0) {
        if (year < 1582) { // Check if exceptions need to be applied
            cout << year << " is a leap year." << endl; //No exceptions needed, year is a leap year
        }
        else if (year % 100 == 0) {
            if (year / 100 % 4 == 0) {
                cout << year << " is a leap year." << endl; // Leap year because divisible by 4, 100, and 400.
            }
            else cout << year << " is not a leap year." << endl; // Not a leap year because divisible by 100 but not 400.
        }
    }
    else cout << year << " is not a leap year." << endl; // Not a leap year
}