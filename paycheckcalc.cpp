// Waylon Peng, Period 1
// Sep262017
// Lab 3b: Paycheck Calculator (3.16)
// Asks user for hourly wage and hours worked, then calculates pay. Overtime (>40 hours) earns 150%.

#include <iostream>
using namespace std;

int main() {
    // Get hourly wage
    cout << "Enter your hourly wage." << endl;
    double wage = 0;
    cin >> wage;
    //Get hours worked
    cout << "Enter hours worked." << endl;
    double hours = 0;
    cin >> hours;

    if (hours < 40) { // If no overtime, just calculate pay simply
        cout << "Your pay is $" << wage * hours;
    }
    else { // If overtime, calculate 40 hours of normal work, then overtime hours (hours - 40) times 150% of wage
        cout << "Your pay is $" << wage * 40 + wage * 1.5 * (hours - 40);
    }
}