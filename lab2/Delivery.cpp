#include "Delivery.h"
#include <iostream>
using namespace std;

Delivery::Delivery()
        : Delivery{false, 0}{} // делегування
Delivery::Delivery(bool available, double deliveryPrice)
        :isAvailable{available}, price{deliveryPrice}{} // список ініціалізації

Delivery::~Delivery(){};

void Delivery::operator+(const Delivery &rhs){
    price+=rhs.price;
}

void Delivery::setAvailability(bool available) {
    isAvailable = available;
}
void Delivery::display() {
    cout << "---------------------------------------" << endl;
    cout << "Delivery Information:\n";
    cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    cout << "Price: " << price << " USD" << endl;
    cout << "Currently there is no delivery person, if you are interested in "
            "this vacancy please contact: 0506729181" << endl;
    cout << "---------------------------------------" << endl;
}

