#ifndef LAB2_CARTITEM_H
#define LAB2_CARTITEM_H

#include <string>

class CartItem {
public:
    std::string name;
    double price;
    CartItem(const std::string& _name, double _price);
    ~CartItem();
};

#endif //LAB2_CARTITEM_H
