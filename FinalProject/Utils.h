#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setPurpleText() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);  // Purple color
}

void maskInput(std::string& input) {
    char ch;
    input = "";
    while ((ch = _getch()) != 13) {  // Enter key ASCII code
        input.push_back(ch);
        std::cout << '*';
    }
    std::cout << std::endl;
}

void drawBorder() {
    for (int i = 0; i < 50; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

bool confirmAction(const std::string& message) {
    char choice;
    std::cout << message << " (Y/N): ";
    std::cin >> choice;
    return choice == 'Y' || choice == 'y';
}

#endif
