#ifndef LAB2_HEALTHYMENU_H
#define LAB2_HEALTHYMENU_H
#include "Menu.h"
using namespace std;

class HealthyMenu final: public Menu {
public:
    double calories;
    double fatContent;

    HealthyMenu();
    HealthyMenu(string new_name);
    HealthyMenu(string new_name, double new_price);
    HealthyMenu(string new_name, double new_price, double new_weight);
    HealthyMenu(string new_name, double new_price, double new_weight, double new_calories);
    HealthyMenu(string new_name, double new_price, double new_weight, double new_calories, double new_fatContent);

    HealthyMenu(HealthyMenu &&other) noexcept;

    virtual ~HealthyMenu();


    virtual void display() const override;
    virtual void describeDish() override final;

    friend ostream &operator <<(ostream &os, HealthyMenu &dish);
    friend istream &operator >>(istream &is, HealthyMenu &dish);
};


#endif //LAB2_HEALTHYMENU_H
