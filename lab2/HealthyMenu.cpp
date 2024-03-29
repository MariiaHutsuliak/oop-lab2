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

void HealthyMenu::displayHealthyMenu(const vector<unique_ptr<HealthyMenu>>& healthyMenu) {
    cout << "Healthy Menu:\n";
    for (size_t i = 0; i < healthyMenu.size(); ++i) {
        cout << i + 1 << ". " << *healthyMenu[i] << endl;
    }
}
void HealthyMenu::addHealthyMenuItem(vector<unique_ptr<HealthyMenu>>& healthyMenu) {
    unique_ptr<HealthyMenu> healthyPos = make_unique<HealthyMenu>();
    cin >> *healthyPos;
    healthyMenu.push_back(move(healthyPos));
    cout << "New item added to the healthy menu:\n" << *healthyMenu.back() << endl;
}
void HealthyMenu::changeHealthyMenuItem(vector<unique_ptr<HealthyMenu>>& menu) {

    int choice;
    cout << "Enter the number of the item you want to change: ";
    cin >> choice;
    if (choice >= 1 && choice <= menu.size()) {
        cout << "Enter the new details for the item:" << endl;
        cin >> *menu[choice - 1];
        cout << "Healthy menu item changed:" << endl << *menu[choice - 1] << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

ostream &operator <<(ostream &os, HealthyMenu &dish) {
    os << "Name: " << dish.name << endl
       << "Price: " << dish.price << endl
       << "Weight: " << dish.weight << endl
       << "Calories: " << dish.calories << endl
       << "Fat content: " << dish.fatContent << endl;
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