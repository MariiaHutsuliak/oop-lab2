#include <iostream>
using namespace std;
#include "Menu.h"
#include "Bar.h"
#include "Delivery.h"
#include "Appetizers.h"
#include "LuxuryBar.h"
#include "HealthyMenu.h"

int main() {
    cout << "---- Demonstrating Menu Items ----\n";
    Menu dish1("Steak", 100, 300);
    dish1.display();

    cout << "\n---- Demonstrating Polymorphism with Menu ----\n";
    Menu dish2("Pasta", 10.99, 300);
    HealthyMenu dish3("Salad", 7.99, 200, 150, 5.5);
    //Base class pointer
    Menu *menu = new Menu("Taco", 5,250);
    Menu *healthy_menu = new HealthyMenu("Soup",8.99,350,250,2.0);
    menu->display();
    healthy_menu->display();
    //Base class reference
    Menu &menu1 = dish2;
    Menu &menu2 = dish3;
    menu1.describeDish();
    menu2.describeDish();

    cout << "\n---- Demonstrating Delivery and Appetizers ----\n";
    Delivery order1(true, 50);
    Delivery availableDelivery(true, 50);
    order1 + availableDelivery;
    order1.display();

    Appetizers appetizer1("Tomato Bruschetta", "Parmesan Cheese", "Salmon Tartar");
    Appetizers appetizer2("Mushroom Bruschetta", "Gouda Cheese");
    cout << "Total number of appetizer orders: " << Appetizers::getNumberOfAppetizers() << endl;

    cout << "\n---- Demonstrating Bar and LuxuryBar ----\n";
    Bar *barPtr = new LuxuryBar("Luxury Drink", 10.99, "Special Cocktail", true, "Imported");
    barPtr->display();
    barPtr->confirmOrder();
    delete barPtr;

    delete menu;
    delete healthy_menu;

    return 0;
}

