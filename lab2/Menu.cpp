#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;


Menu::Menu()
        :Menu{"None", 0, 0} {}
Menu::Menu(string new_name)
        :Menu{new_name, 0, 0} {}
Menu::Menu(string new_name, double new_price)
        :Menu{new_name, new_price, 0} {}
Menu::Menu(string new_name, double new_price, double new_weight)
        :name{new_name}, price{new_price}, weight{new_weight} {}
// делегування і ініціалізація

Menu::Menu(Menu &&other) noexcept
        :name{other.name}, price{other.price},weight{other.weight}{}

Menu::~Menu(){}

void Menu::displayMenu(const vector<shared_ptr<Menu>>& menu) {
    cout << "Menu:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << *menu[i] << endl;
    }
}
void Menu::addMenuItem(vector<shared_ptr<Menu>>& menu) {
    auto newItem = make_unique<Menu>();
    cin >> *newItem;
    menu.push_back(move(newItem));
    cout << "New item added to the menu:\n" << *menu.back() << endl;
}
void Menu::changeMenuItem(vector<shared_ptr<Menu>>& menu) {
    displayMenu(menu);
    int choice;
    cout << "Enter the number of the item you want to change: ";
    cin >> choice;
    if (choice >= 1 || choice << menu.size()) {
        cout << "Enter the new details for the item:" << endl;
        cin >> *menu[choice - 1];
        cout << "Menu item changed:" << endl << *menu[choice - 1] << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

ostream &operator <<(ostream &os, Menu &dish) {
   os << "Name: " << dish.name <<  endl
   << "Price: " << dish.price << " USD" << endl
   << "Weight: " << dish.weight <<" g" << endl;
   return os;
};

istream &operator >>(istream &is, Menu &dish){
    cout << "Enter name of the dish: ";
    is >> dish.name;
    cout << "Enter price of the dish: ";
    is >> dish.price;
    cout << "Enter weight of the dish: ";
    is >> dish.weight;
    return is;
}
