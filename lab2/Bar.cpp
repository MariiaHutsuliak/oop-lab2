#include "Bar.h"
#include <iostream>


Bar::Bar(string newName, double newPrice, string newSpecial)
        : name{newName}, price{newPrice}, special{newSpecial} {} // список ініціалізації

Bar::Bar(const Bar &other)
        : name{other.name}, price{other.price}, special{other.special} {}
Bar::~Bar(){}




void Bar::display() {
    cout << "Bar Information:\n";
    cout << "Name: " << name << endl;
    cout << "Price: " << price << " USD" << endl;
    cout << "Special: " << special << endl;
}

void Bar::updateBar(string newName, double newPrice, string newSpecial) {
    name = newName;
    price = newPrice;
    special = newSpecial;
}