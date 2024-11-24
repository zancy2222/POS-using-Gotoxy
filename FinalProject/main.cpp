#include "UserManager.h"
#include "ProductManager.h"
#include "PaymentManager.h"

void showHelpMenu() {
    system("cls");
    setPurpleText();
    drawBorder();
    gotoxy(10, 2); cout << "ONE BITE Help Menu";

    gotoxy(10, 4); cout << "About the Program:";
    gotoxy(10, 5); cout << "ONE BITE is a food ordering system that allows users";
    gotoxy(10, 6); cout << "to register, log in, add products to a cart, and make payments.";
    gotoxy(10, 7); cout << "It simplifies the process of managing orders and provides a user-friendly experience.";

    gotoxy(10, 9); cout << "Credits:";
    gotoxy(10, 10); cout << "Developed by: [Your Name]";
    gotoxy(10, 11); cout << "For educational purposes and practical learning.";

    gotoxy(10, 13); cout << "How to Use the Program:";
    gotoxy(10, 14); cout << "1. Start by registering a new user account.";
    gotoxy(10, 15); cout << "2. Log in using your registered username and password.";
    gotoxy(10, 16); cout << "3. Navigate to the dashboard to add products to your cart.";
    gotoxy(10, 17); cout << "4. View your cart to check selected items and quantities.";
    gotoxy(10, 18); cout << "5. Proceed to payment to finalize your order.";
    gotoxy(10, 19); cout << "6. Use the Help menu for guidance at any time.";
    gotoxy(10, 20); cout << "7. Logout or exit when you’re done.";

    gotoxy(10, 22); cout << "Press Enter to return to the main menu.";
    _getch();
}

int main() {
    while (true) {
        system("cls");
        setPurpleText();
        drawBorder();
        // Displaying the text without using std::
        gotoxy(10, 2); cout << "  OOOOOOOOO   BBBBBBBBB   ";
        gotoxy(10, 3); cout << " O         O  B         B  ";
        gotoxy(10, 4); cout << " O         O  B         B  ";
        gotoxy(10, 5); cout << " O         O  BBBBBBBBB   ";
        gotoxy(10, 6); cout << " O         O  B         B  ";
        gotoxy(10, 7); cout << " O         O  B         B  ";
        gotoxy(10, 8); cout << "  OOOOOOOOO   BBBBBBBBB   ";

        gotoxy(10, 10); cout << "1. Register";
        gotoxy(10, 11); cout << "2. Login";
        gotoxy(10, 12); cout << "3. Help";
        gotoxy(10, 13); cout << "4. Exit";
        gotoxy(10, 14); cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                while (true) {
                    system("cls");
                    setPurpleText();
                    drawBorder();
                    gotoxy(10, 2); cout << "ONE BITE Dashboard";
                    gotoxy(10, 4); cout << "1. Add Product to Cart";
                    gotoxy(10, 5); cout << "2. View Cart";
                    gotoxy(10, 6); cout << "3. Process Payment";
                    gotoxy(10, 7); cout << "4. Logout";
                    gotoxy(10, 8); cout << "Enter your choice: ";

                    int dashboardChoice;
                    cin >> dashboardChoice;

                    switch (dashboardChoice) {
                    case 1: addProductToCart(); break;
                    case 2: viewCart(); break;
                    case 3: processPayment(); break;
                    case 4: goto mainMenu;  // Exit to main menu
                    default:
                        gotoxy(10, 9); cout << "Invalid choice. Press Enter to try again.";
                        _getch();
                    }
                }
            }
            break;
        case 3:
            showHelpMenu();
            break;
        case 4:
            cout << "Thank you for using ONE BITE!";
            return 0;
        default:
            gotoxy(10, 9); cout << "Invalid choice. Press Enter to try again.";
            _getch();
        }
    mainMenu: continue;  // Label for returning to main menu
    }
}
