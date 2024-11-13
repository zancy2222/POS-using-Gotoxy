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
    gotoxy(10, 2); std::cout << "ONE BITE Registration";

    gotoxy(10, 4); std::cout << "First Name: "; std::cin >> currentUser.firstName;
    gotoxy(10, 5); std::cout << "Middle Name: "; std::cin >> currentUser.middleName;
    gotoxy(10, 6); std::cout << "Last Name: "; std::cin >> currentUser.lastName;
    gotoxy(10, 7); std::cout << "Gender: "; std::cin >> currentUser.gender;
    gotoxy(10, 8); std::cout << "Birthdate (DD/MM/YYYY): "; std::cin >> currentUser.birthDate;
    gotoxy(10, 9); std::cout << "Username: "; std::cin >> currentUser.username;

    std::string confirmPassword;
    while (true) {
        gotoxy(10, 10); std::cout << "Password: "; maskInput(currentUser.password);
        gotoxy(10, 11); std::cout << "Confirm Password: "; maskInput(confirmPassword);
        if (currentUser.password == confirmPassword) break;
        else {
            gotoxy(10, 12); std::cout << "Passwords do not match. Please try again.";
            _getch();
            gotoxy(10, 12); std::cout << std::string(50, ' ');
        }
    }
    gotoxy(10, 13); std::cout << "Registration successful! Press Enter to continue.";
    _getch();
}

bool loginUser() {
    system("cls");
    setPurpleText();
    drawBorder();
    gotoxy(10, 2); std::cout << "ONE BITE Login";

    std::string username, password;
    gotoxy(10, 4); std::cout << "Username: "; std::cin >> username;
    gotoxy(10, 5); std::cout << "Password: "; maskInput(password);

    if (username == currentUser.username && password == currentUser.password) {
        gotoxy(10, 6); std::cout << "Login successful! Press Enter to continue.";
        _getch();
        return true;
    }
    gotoxy(10, 6); std::cout << "Invalid username or password. Press Enter to go back.";
    _getch();
    return false;
}

#endif
