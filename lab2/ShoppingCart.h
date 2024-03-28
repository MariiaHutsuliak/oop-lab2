#ifndef LAB2_SHOPPINGCART_H
#define LAB2_SHOPPINGCART_H
#include <vector>
#include <string>
#include "CartItem.h"

class ShoppingCart {
private:
    std::vector<CartItem> items;
    double totalCost;
public:
    ShoppingCart();
    ~ShoppingCart();
    void addItem(const std::string& name, double price);
    void displayCart();
};

#endif //LAB2_SHOPPINGCART_H
