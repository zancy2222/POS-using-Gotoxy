#pragma once
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
    gotoxy(10, 2); std::cout << "ONE BITE Payments";

    if (cart.empty()) {
        gotoxy(10, 4); std::cout << "Your cart is empty. Add items to cart before proceeding to payment. Press Enter to go back.";
        _getch();
        return;
    }

    double total = 0;
    for (const auto& item : cart) {
        total += item.first.price * item.second;
    }

    double payment;
    gotoxy(10, 4); std::cout << "Your total is: PHP: " << std::fixed << std::setprecision(2) << total;
    gotoxy(10, 5); std::cout << "Enter payment amount: ";
    std::cin >> payment;

    if (payment >= total) {
        gotoxy(10, 6); std::cout << "Payment successful!";
        gotoxy(10, 7); std::cout << "Change: PHP: " << std::fixed << std::setprecision(2) << payment - total;
        cart.clear();
    }
    else {
        gotoxy(10, 6); std::cout << "Insufficient payment. Transaction canceled.";
    }
    gotoxy(10, 8); std::cout << "Press Enter to continue.";
    _getch();
}

#endif
