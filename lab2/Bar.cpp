#include "Bar.h"
#include <iostream>
#include <fstream>

Bar::Bar(string newName, double newPrice, string newSpecial)
        : name{newName}, price{newPrice}, special{newSpecial} {}

Bar::Bar(const Bar &other)
        : name{other.name}, price{other.price}, special{other.special} {}
Bar::~Bar(){}


void Bar::displayBar(const vector<unique_ptr<Bar>>& barMenu) {
    cout << "Bar Menu:\n";
    for (size_t i = 0; i < barMenu.size(); ++i) {
        cout << i + 1 << ". " << *barMenu[i] << endl;
    }
}
void Bar::addBarItem(vector<unique_ptr<Bar>>& barMenu) {
    unique_ptr<Bar> barPos = make_unique<Bar>();
    cin >> *barPos;
    barMenu.push_back(move(barPos));
    cout << "New item added to the bar menu:\n" << *barMenu.back() << endl;
}
void Bar::changeBarItem(vector<unique_ptr<Bar>>& barMenu) {
    int choice;
    cout << "Enter the number of the item you want to change: ";
    cin >> choice;
    if (choice >= 1 && choice <= barMenu.size()) {
        cout << "Enter the new details for the item:" << endl;
        cin >> *barMenu[choice - 1];
        cout << "Bar item changed:" << endl << *barMenu[choice - 1] << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

istream& operator>>(istream& is, Bar& cocktail) {
    cout << "Enter name: ";
    is >> cocktail.name;
    cout << "Enter price: ";
    is >> cocktail.price;
    cout << "Enter special: ";
    is >> cocktail.special;
    return is;
}

ostream& operator<<(ostream& os, Bar& cocktail) {
    os << "Name: " << cocktail.name << endl;
    os << "Price: " << cocktail.price << " USD" << endl;
    os << "Special: " << cocktail.special << endl;
    return os;
}