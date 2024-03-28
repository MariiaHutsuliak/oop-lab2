#include "ShoppingCart.h"
using namespace std;
#include <iostream>
ShoppingCart::ShoppingCart() : totalCost(0) {}

ShoppingCart::~ShoppingCart() {}

void ShoppingCart::addItem(const string& name, double price) {
    items.push_back(CartItem(name, price));
    totalCost += price;
}

void ShoppingCart::displayCart() {
    cout << "Items in Cart:\n";
    for (const auto& item : items) {
        cout << item.name << " - $" << item.price << std::endl;
    }
    int pay;
    cout << "Total cost: $" << totalCost << std::endl;
    cout << "Waiting for payment: ";
    cin >> pay;
    cout << endl << "Thank you for choosing our restaurant!";

}