#include "Menu.h"
#include <iostream>
#include <vector>
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

Menu::~Menu(){}


void Menu::display() {
    std::cout << "Menu:\n";
    std::cout << "Name: " << name << endl;
    std::cout << "Price: " << price << " USD" << endl;
    std::cout << "Weight: " << weight << " g" << endl;
}

void Menu::updateItem(string &newName, double newPrice, double newWeight) {
    name = newName;
    price = newPrice;
    weight = newWeight;
}