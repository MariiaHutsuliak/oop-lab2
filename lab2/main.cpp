#include <iostream>
using namespace std;
#include "Menu.h"
#include "Bar.h"
#include "Delivery.h"

int main() {
Menu dish1("Steak",100, 300);
Bar cocktail1("Pina Colada", 100, "1+1=3");
Delivery order1(true, 50);

dish1.display();
cocktail1.display();
order1.displayInfo();
    return 0;
}
