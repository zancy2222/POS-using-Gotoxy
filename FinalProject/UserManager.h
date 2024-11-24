#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "Utils.h"

User currentUser;

void registerUser();
bool loginUser();

void registerUser() {
    system("cls");
    setPurpleText();
    drawBorder();
    gotoxy(10, 2); cout << "ONE BITE Registration";

    gotoxy(10, 4); cout << "First Name: "; cin >> currentUser.firstName;
    gotoxy(10, 5); cout << "Middle Name: "; cin >> currentUser.middleName;
    gotoxy(10, 6); cout << "Last Name: "; cin >> currentUser.lastName;
    gotoxy(10, 7); cout << "Gender: "; cin >> currentUser.gender;
    gotoxy(10, 8); cout << "Birthdate (DD/MM/YYYY): "; cin >> currentUser.birthDate;
    gotoxy(10, 9); cout << "Username: "; cin >> currentUser.username;

    string confirmPassword;
    while (true) {
        gotoxy(10, 10); cout << "Password: "; maskInput(currentUser.password);
        gotoxy(10, 11); cout << "Confirm Password: "; maskInput(confirmPassword);
        if (currentUser.password == confirmPassword) break;
        else {
            gotoxy(10, 12); cout << "Passwords do not match. Please try again.";
            _getch();
            gotoxy(10, 12); cout << string(50, ' ');
        }
    }
    gotoxy(10, 13); cout << "Registration successful! Press Enter to continue.";
    _getch();
}

bool loginUser() {
    system("cls");
    setPurpleText();
    drawBorder();
    gotoxy(10, 2); cout << "ONE BITE Login";

    string username, password;
    gotoxy(10, 4); cout << "Username: "; cin >> username;
    gotoxy(10, 5); cout << "Password: "; maskInput(password);

    if (username == currentUser.username && password == currentUser.password) {
        gotoxy(10, 6); cout << "Login successful! Press Enter to continue.";
        _getch();
        return true;
    }
    gotoxy(10, 6); cout << "Invalid username or password. Press Enter to go back.";
    _getch();
    return false;
}

#endif
