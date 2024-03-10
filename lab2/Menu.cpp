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


void Menu::display() const{
    cout << "Menu:\n";
    cout << "Name: " << name << endl;
    cout << "Price: " << price << " USD" << endl;
    cout << "Weight: " << weight << " g" << endl;
    cout << "Displaying information about menu" << endl;
}
void Menu::describeDish(){
    cout << "Basic dish from the menu." << endl;
}

ostream &operator <<(ostream &os, Menu &dish) {
   os << "Dish name: " << dish.name << endl
   << "Dish price: " << dish.price << endl
   << "Dish weight: " << dish.weight << endl;
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
