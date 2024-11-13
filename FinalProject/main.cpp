#include "UserManager.h"
#include "ProductManager.h"
#include "PaymentManager.h"

int main() {

    while (true) {
        system("cls");
        setPurpleText();
        drawBorder();
        gotoxy(10, 2); std::cout << "  OOOOOOOOO   BBBBBBBBB   ";
        gotoxy(10, 3); std::cout << " O         O  B         B  ";
        gotoxy(10, 4); std::cout << " O         O  B         B  ";
        gotoxy(10, 5); std::cout << " O         O  BBBBBBBBB   ";
        gotoxy(10, 6); std::cout << " O         O  B         B  ";
        gotoxy(10, 7); std::cout << " O         O  B         B  ";
        gotoxy(10, 8); std::cout << "  OOOOOOOOO   BBBBBBBBB   ";

        gotoxy(10, 10); std::cout << "1. Register";
        gotoxy(10, 11); std::cout << "2. Login";
        gotoxy(10, 12); std::cout << "3. Exit";
        gotoxy(10, 13); std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            if (loginUser()) {
                while (true) {
                    system("cls");
                    setPurpleText();
                    drawBorder();

                    gotoxy(10, 2); std::cout << "ONE BITE User Menu";
                    gotoxy(10, 4); std::cout << "1. Add Product to Cart";
                    gotoxy(10, 5); std::cout << "2. View Cart";
                    gotoxy(10, 6); std::cout << "3. Process Payment";
                    gotoxy(10, 7); std::cout << "4. Logout";
                    gotoxy(10, 9); std::cout << "Choose an option: ";
                    int userChoice;
                    std::cin >> userChoice;

                    if (userChoice == 1) {
                        addProductToCart();
                    }
                    else if (userChoice == 2) {
                        viewCart();
                    }
                    else if (userChoice == 3) {
                        processPayment();
                    }
                    else if (userChoice == 4) {
                        break;
                    }
                }
            }
        }
        else if (choice == 3) {
            gotoxy(10, 10); std::cout << "Thank you for using ONE BITE!";
            _getch();
            break;
        }
    }
    return 0;
}
