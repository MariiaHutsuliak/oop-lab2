#include "HealthyMenu.h"
#include "Menu.h"
#include <iostream>
using namespace std;

HealthyMenu::HealthyMenu()
        : HealthyMenu{"None", 0, 0, 0, 0} {}

HealthyMenu::HealthyMenu(string new_name)
        : HealthyMenu{new_name, 0, 0, 0, 0} {}

HealthyMenu::HealthyMenu(string new_name, double new_price)
        : HealthyMenu{new_name, new_price, 0, 0, 0} {}

HealthyMenu::HealthyMenu(string new_name, double new_price, double new_weight)
        : HealthyMenu{new_name, new_price, new_weight, 0, 0} {}

HealthyMenu::HealthyMenu(string new_name, double new_price, double new_weight, double new_calories, double new_fatContent)
        : Menu{new_name, new_price, new_weight}, calories{new_calories}, fatContent{new_fatContent} {}

HealthyMenu::HealthyMenu(HealthyMenu &&other) noexcept
        : Menu{move(other)}, calories{other.calories}, fatContent{other.fatContent} {}
HealthyMenu::~HealthyMenu() {}

void HealthyMenu::displayHealthyMenu(const vector<shared_ptr<HealthyMenu>>& healthyMenu) {
    cout << "Healthy Menu:\n";
    for (size_t i = 0; i < healthyMenu.size(); ++i) {
        cout << i + 1 << ". " << *healthyMenu[i] << endl;
    }
}
void HealthyMenu::addHealthyMenuItem(vector<shared_ptr<HealthyMenu>>& healthyMenu) {
    auto newItem = make_unique<HealthyMenu>();
    cin >> *newItem;
    healthyMenu.push_back(move(newItem));
    cout << "New item added to the healthy menu:\n" << *healthyMenu.back() << endl;
}

void HealthyMenu::changeHealthyMenuItem(vector<shared_ptr<HealthyMenu>>& healthyMenu) {
    displayHealthyMenu(healthyMenu);
    int choice;
    cout << "Enter the number of the item you want to change: ";
    cin >> choice;
    if (choice >= 1 && choice <= static_cast<int>(healthyMenu.size())) {
        cout << "Enter the new details for the item:" << endl;
        cin >> *healthyMenu[choice - 1];
        cout << "Healthy menu item changed:" << endl << *healthyMenu[choice - 1] << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}


ostream &operator <<(ostream &os, HealthyMenu &dish) {
    os << "Dish name: " << dish.name << endl
       << "Dish price: " << dish.price << endl
       << "Dish weight: " << dish.weight << endl
       << "Dish calories: " << dish.calories << endl
       << "Dish fat content: " << dish.fatContent << endl;
    return os;
};

istream &operator >>(istream &is, HealthyMenu &dish){
    cout << "Enter name of the dish: ";
    is >> dish.name;
    cout << "Enter price of the dish: ";
    is >> dish.price;
    cout << "Enter weight of the dish: ";
    is >> dish.weight;
    cout << "Enter number of calories: ";
    is >> dish.calories;
    cout << "Enter fat content: ";
    is >> dish.fatContent;
    return is;
}