#include "LuxuryBar.h"
#include "Bar.h"
#include <iostream>
using namespace std;

LuxuryBar::LuxuryBar(string newName, double newPrice, string newSpecial, bool newPremiumQuality, string newOrigin)
        : Bar{newName, newPrice, newSpecial}, premiumQuality{newPremiumQuality}, origin{newOrigin} {}

LuxuryBar::LuxuryBar(const LuxuryBar &other)
        : Bar{other}, premiumQuality{other.premiumQuality}, origin{other.origin}{}

LuxuryBar& LuxuryBar::operator=(const LuxuryBar& other) {
    Bar::operator=(other);

    premiumQuality = other.premiumQuality;
    origin = other.origin;

    return *this;
}

istream& operator>>(istream& is, LuxuryBar& cocktail) {
    cout << "Enter name: ";
    is >> cocktail.name;
    cout << "Enter price: ";
    is >> cocktail.price;
    cout << "Enter special: ";
    is >> cocktail.special;
    cout << "Enter origin: ";
    is >> cocktail.origin;
    cout << "Enter premium quality: ";
    is >> cocktail.premiumQuality;
    return is;
}

ostream& operator<<(ostream& os, LuxuryBar& cocktail) {
    os << "Name: " << cocktail.name << endl;
    os << "Price: " << cocktail.price << " USD" << endl;
    os << "Special: " << cocktail.special << endl;
    os << "Origin: " << cocktail.origin << endl;
    os << "Premium quality: " << cocktail.premiumQuality << endl;
    return os;
}
LuxuryBar::~LuxuryBar(){};

void LuxuryBar::displayLuxuryBar(const vector<unique_ptr<LuxuryBar>>& luxuryBarMenu) {
    cout << "Luxury Bar Menu:\n";
    for (size_t i = 0; i < luxuryBarMenu.size(); ++i) {
        cout << i + 1 << ". " << *luxuryBarMenu[i] << endl;
    }
}
void LuxuryBar::addLuxuryBarItem(vector<unique_ptr<LuxuryBar>>& luxuryBarMenu) {
    unique_ptr<LuxuryBar> luxuryPos = make_unique<LuxuryBar>();
    cin >> *luxuryPos;
    luxuryBarMenu.push_back(move(luxuryPos));
    cout << "New item added to the luxury bar menu:\n" << *luxuryBarMenu.back() << endl;
}
void LuxuryBar::changeLuxuryBarItem(vector<unique_ptr<LuxuryBar>>& luxuryBarMenu) {
    int choice;
    cout << "Enter the number of the item you want to change: ";
    cin >> choice;
    if (choice >= 1 && choice <= luxuryBarMenu.size()) {
        cout << "Enter the new details for the item:" << endl;
        cin >> *luxuryBarMenu[choice - 1];
        cout << "Luxury bar item changed:" << endl << *luxuryBarMenu[choice - 1] << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

