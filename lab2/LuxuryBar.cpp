#include "LuxuryBar.h"
#include "Bar.h"
#include <iostream>
using namespace std;

LuxuryBar::LuxuryBar(string newName, double newPrice, string newSpecial, bool newPremiumQuality, string newOrigin)
        : Bar{newName, newPrice, newSpecial,} premiumQuality{newPremiumQuality};, origin{newOrigin} {}

LuxuryBar::LuxuryBar(const LuxuryBar &other)
        : Bar{other}, premiumQuality{other.premiumQuality}, origin{other.origin}{}
~LuxuryBar::LuxuryBar(){};

void LuxuryBar::display() {
    cout << "Name: " << name << endl;
    cout << "Price: " << price << " USD" << endl;
    cout << "Special: " << special << endl;
    cout << "Premium Quality: " << (premiumQuality ? "Yes" : "No") << endl;
    cout << "Origin: " << origin << endl;
}