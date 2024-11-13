#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>
using namespace std;

class Cart {
private:
    vector<pair<Product, int>> items;

public:
    void addProduct(const Product& product, int quantity);
    void viewCart() const;
    double calculateTotal() const;
    void clearCart();
};

#endif
