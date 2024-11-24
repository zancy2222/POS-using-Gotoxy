#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <vector>
#include <iomanip>
#include "Product.h"
#include "Utils.h"

vector<Product> products = { {"Burger", 5.99}, {"Pizza", 8.99}, {"Soda", 1.50}, {"Fries", 2.99},
                             {"Pasta", 7.50}, {"Salad", 4.99}, {"Ice Cream", 3.50}, {"Coffee", 2.50},
                             {"Tea", 1.75}, {"Smoothie", 4.00} };
vector<pair<Product, int>> cart;

void addProductToCart();
void viewCart();

void addProductToCart() {
    system("cls");
    setPurpleText();
    drawBorder();
    gotoxy(10, 2); cout << "ONE BITE Product Menu";

    gotoxy(10, 4); cout << "Available Products:";
    for (size_t i = 0; i < products.size(); ++i) {
        gotoxy(10, 5 + i); cout << i + 1 << ". " << products[i].name << " - PHP " << fixed << setprecision(2) << products[i].price;
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

void viewCart() {
    system("cls");
    setPurpleText();
    drawBorder();
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
            << " @ PHP:" << cart[i].first.price << " = PHP: " << fixed << setprecision(2)
            << cart[i].first.price * cart[i].second;
        total += cart[i].first.price * cart[i].second;
    }
    gotoxy(10, 6 + cart.size()); cout << "Total: PHP: " << fixed << setprecision(2) << total;
    _getch();
}

#endif
