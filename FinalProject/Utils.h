#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setPurpleText() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);  // Purple color
}

void maskInput(string& input) {
    char ch;
    input = "";
    while ((ch = _getch()) != 13) {  // Enter key ASCII code
        input.push_back(ch);
        cout << '*';
    }
    cout << endl;
}

void drawBorder() {
    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

bool confirmAction(const string& message) {
    char choice;
    cout << message << " (Y/N): ";
    cin >> choice;
    return choice == 'Y' || choice == 'y';
}

#endif
