#ifndef PAYMENTMANAGER_H
#define PAYMENTMANAGER_H

#include <vector>
#include "Utils.h"
#include "ProductManager.h"

void processPayment();

void processPayment() {
    system("cls");
    setPurpleText();
    drawBorder();
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
    gotoxy(10, 4); cout << "Your total is: PHP: " << fixed << setprecision(2) << total;
    gotoxy(10, 5); cout << "Enter payment amount: ";
    cin >> payment;

    if (payment >= total) {
        gotoxy(10, 6); cout << "Payment successful!";
        gotoxy(10, 7); cout << "Change: PHP: " << fixed << setprecision(2) << payment - total;
        cart.clear();
    }
    else {
        gotoxy(10, 6); cout << "Insufficient payment. Transaction canceled.";
    }
    gotoxy(10, 8); cout << "Press Enter to continue.";
    _getch();
}

#endif
