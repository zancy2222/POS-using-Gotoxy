#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

// User structure to store profile information
struct User {
    string firstName, middleName, lastName, gender, birthDate;
    string username, password;
};

// Product structure
struct Product {
    string name;
    double price;
};

// Global variables
User currentUser;
vector<Product> products = { {"Burger", 5.99}, {"Pizza", 8.99}, {"Soda", 1.50}, {"Fries", 2.99},
                             {"Pasta", 7.50}, {"Salad", 4.99}, {"Ice Cream", 3.50}, {"Coffee", 2.50},
                             {"Tea", 1.75}, {"Smoothie", 4.00} };
vector<pair<Product, int>> cart;  // Stores product and quantity
bool isLoggedIn = false;

// Function to set cursor position (using gotoxy)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Utility functions for display and input masking
void maskInput(string& input) {
    char ch;
    input = "";
    while ((ch = _getch()) != 13) {  // Enter key ASCII code
        input.push_back(ch);
        cout << '*';
    }
    cout << endl;
}

// Confirmation prompt
bool confirmAction(const string& message) {
    char choice;
    cout << message << " (Y/N): ";
    cin >> choice;
    return choice == 'Y' || choice == 'y';
}

// Registration function
void registerUser() {
    system("cls");
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
            gotoxy(10, 12); cout << string(50, ' ');  // Clear the line
        }
    }
    gotoxy(10, 13); cout << "Registration successful! Press Enter to continue.";
    _getch();
}

// Login function
bool loginUser() {
    system("cls");
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

// Add Product to Cart
void addProductToCart() {
    system("cls");
    gotoxy(10, 2); cout << "ONE BITE Product Menu";

    gotoxy(10, 4); cout << "Available Products:";
    for (size_t i = 0; i < products.size(); ++i) {
        gotoxy(10, 5 + i); cout << i + 1 << ". " << products[i].name << " - $" << fixed << setprecision(2) << products[i].price;
    }

    int choice, quantity;
    gotoxy(10, 5 + products.size() + 1); cout << "Enter product number to add to cart, or 0 to go back: ";
    cin >> choice;

    if (choice == 0) return;
    if (choice < 1 || choice >(int)products.size()) {
        gotoxy(10, 5 + products.size() + 2); cout << "Invalid selection. Press Enter to go back.";
        _getch();
        return;
    }

    gotoxy(10, 5 + products.size() + 3); cout << "Enter quantity: ";
    cin >> quantity;

    cart.push_back({ products[choice - 1], quantity });
    gotoxy(10, 5 + products.size() + 4); cout << "Product added to cart. Press Enter to continue.";
    _getch();
}

// View Cart function
void viewCart() {
    system("cls");
    gotoxy(10, 2); cout << "ONE BITE Cart";

    if (cart.empty()) {
        gotoxy(10, 4); cout << "Your cart is empty. Press Enter to go back.";
        _getch();
        return;
    }

    double total = 0;
    gotoxy(10, 4); cout << "Items in Cart:";
    for (size_t i = 0; i < cart.size(); ++i) {
        gotoxy(10, 5 + i);
        cout << "- " << cart[i].first.name << " x" << cart[i].second
            << " @ $" << cart[i].first.price << " = $" << fixed << setprecision(2)
            << cart[i].first.price * cart[i].second;
        total += cart[i].first.price * cart[i].second;
    }
    gotoxy(10, 6 + cart.size()); cout << "Total: $" << fixed << setprecision(2) << total;
    _getch();
}

// Payment function
void processPayment() {
    system("cls");
    gotoxy(10, 2); cout << "ONE BITE Payments";

    if (cart.empty()) {
        gotoxy(10, 4); cout << "Your cart is empty. Add items to cart before proceeding to payment. Press Enter to go back.";
        _getch();
        return;
    }

    double total = 0;
    for (const auto& item : cart) {
        total += item.first.price * item.second;
    }

    double payment;
    gotoxy(10, 4); cout << "Your total is: $" << fixed << setprecision(2) << total;
    gotoxy(10, 5); cout << "Enter payment amount: ";
    cin >> payment;

    if (payment >= total) {
        gotoxy(10, 6); cout << "Payment successful!";
        gotoxy(10, 7); cout << "Change: $" << fixed << setprecision(2) << payment - total;
        cart.clear();
    }
    else {
        gotoxy(10, 6); cout << "Insufficient payment. Transaction canceled.";
    }
    gotoxy(10, 8); cout << "Press Enter to continue.";
    _getch();
}

// Profile function with update capability
void profile() {
    while (true) {
        system("cls");
        gotoxy(10, 2); cout << "ONE BITE Profile";
        gotoxy(10, 4); cout << "1. Update First Name";
        gotoxy(10, 5); cout << "2. Update Last Name";
        gotoxy(10, 6); cout << "3. Update Gender";
        gotoxy(10, 7); cout << "4. Back to Main Menu";
        gotoxy(10, 8); cout << "Select an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: gotoxy(10, 9); cout << "New First Name: "; cin >> currentUser.firstName; break;
        case 2: gotoxy(10, 9); cout << "New Last Name: "; cin >> currentUser.lastName; break;
        case 3: gotoxy(10, 9); cout << "New Gender: "; cin >> currentUser.gender; break;
        case 4: return;
        default: gotoxy(10, 10); cout << "Invalid choice. Please try again."; _getch(); break;
        }
    }
}

// Main Menu
void mainMenu() {
    int choice;
    while (true) {
        system("cls");
        gotoxy(10, 2); cout << "Welcome to ONE BITE!";
        gotoxy(10, 4); cout << "1. Menu (Products)";
        gotoxy(10, 5); cout << "2. View Cart";
        gotoxy(10, 6); cout << "3. Payments for Orders";
        gotoxy(10, 7); cout << "4. Profile";
        gotoxy(10, 8); cout << "5. Logout";
        gotoxy(10, 9); cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1: addProductToCart(); break;
        case 2: viewCart(); break;
        case 3: processPayment(); break;
        case 4: profile(); break;
        case 5:
            if (confirmAction("Are you sure you want to log out?")) {
                isLoggedIn = false;
                gotoxy(10, 10); cout << "Logged out successfully. Press Enter to return to the main menu.";
                _getch();
                return;
            }
            break;
        default: gotoxy(10, 10); cout << "Invalid choice. Please try again."; _getch(); break;
        }
    }
}

// Entry point
int main() {
    while (true) {
        system("cls");
        gotoxy(10, 2); cout << "Welcome to ONE BITE System";
        gotoxy(10, 4); cout << "1. Register";
        gotoxy(10, 5); cout << "2. Login";
        gotoxy(10, 6); cout << "3. Exit";
        gotoxy(10, 7); cout << "Select an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: registerUser(); break;
        case 2:
            if (loginUser()) mainMenu();
            break;
        case 3:
            if (confirmAction("Are you sure you want to exit?")) exit(0);
            break;
        default: gotoxy(10, 8); cout << "Invalid choice. Please try again."; _getch(); break;
        }
    }
    return 0;
}

