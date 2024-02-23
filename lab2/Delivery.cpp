#include "Delivery.h"
#include <iostream>
using namespace std;

Delivery::Delivery()
        : Delivery{false, 0}{}
Delivery::Delivery(bool available, double deliveryPrice)
        :isAvailable{available}, price{deliveryPrice}{}
Delivery::~Delivery(){};

void Delivery::setAvailability(bool available) {
    isAvailable = available;
}
void Delivery::displayInfo() {
    cout << "Delivery Information:\n";
    cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    cout << "Price: " << price << " USD" << endl;
}
