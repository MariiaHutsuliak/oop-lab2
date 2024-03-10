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
    const Menu dish1("Steak", 100, 300);
    dish1.display();

    cout << "\n---- Demonstrating Polymorphism with Menu ----\n";
    Menu *menu = new Menu();
    Menu *healthy_menu = new HealthyMenu();
    menu->display();
    healthy_menu->display();

    Menu *info1 = new Menu();
    Menu *info2 = new HealthyMenu();
    info1->describeDish();
    info2->describeDish();

    cout << "\n---- Demonstrating Delivery and Appetizers ----\n";
    Delivery order1(true, 50);
    Delivery availableDelivery(true, 50);
    order1 + availableDelivery;
    order1.displayInfo();

    Appetizers appetizer1("Tomato Bruschetta", "Parmesan Cheese", "Salmon Tartar");
    Appetizers appetizer2("Mushroom Bruschetta", "Gouda Cheese");
    cout << "Total number of appetizer orders: " << Appetizers::getNumberOfAppetizers() << endl;

    cout << "\n---- Demonstrating Bar and LuxuryBar ----\n";
    Bar cocktail1("Pina Colada", 100, "1+1=3");
    cocktail1.display();

    Bar *barPtr = new LuxuryBar("Luxury Drink", 10.99, "Special Cocktail", true, "Imported");
    barPtr->display();
    delete barPtr;

    delete menu;
    delete healthy_menu;
    delete info1;
    delete info2;

    return 0;
}

