#include <iostream>
using namespace std;

void printRow(int width);
int main() {
    cout << "Enter grid width:";
    int width;
    cin >> width;

    cout << "╔";
    for (int i = 0; i < width - 1; i++) {
        cout << "═══╦";
    }
    cout << "═══╗" << endl;

    for (int i = 0; i < width - 1; i++) {
        printRow(width);
    }

}

void printRow(int width) {
    for (int i = 0; i < 2; i++) {
        cout << "║";
        for (int i = 0; i < width; i++) {
            cout << "   ║";
        }
        cout << endl;
    }


    cout << "╠";
    for (int i = 0; i < width - 1; i++) {
        cout << "═══╬";
    }
    cout << "═══╣";

    return;
}