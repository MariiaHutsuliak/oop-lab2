#include "Delivery.h"
#include <iostream>
using namespace std;

Delivery::Delivery()
        : Delivery{false, 0}{} // делегування
Delivery::Delivery(bool available, double deliveryPrice)
        :isAvailable{available}, price{deliveryPrice}{} // список ініціалізації

Delivery::Delivery(Delivery&& other) noexcept
        : isAvailable(std::move(other.isAvailable)), price(std::move(other.price)) {
    other.isAvailable = false;
    other.price = 0.0; }

Delivery::~Delivery(){};

void Delivery::setAvailability(bool available) {
    isAvailable = available;
}
void Delivery::displayInfo() {
    cout << "Delivery Information:\n";
    cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    cout << "Price: " << price << " USD" << endl;
}
