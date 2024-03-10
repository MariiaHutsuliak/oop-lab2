#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include <vector>
#include <string>
using namespace std;

class Menu {
public:
    string name;
    double price;
    double weight;

    virtual void display() const;
    virtual void describeDish();

    Menu(); // конструктор за замовчуванням
    Menu(string new_name); // перевантажений конструктор
    Menu(string new_name, double new_price);
    Menu(string new_name, double new_price, double new_weight);

    friend ostream &operator <<(ostream &os, Menu &dish);
    friend istream &operator >>(istream &is, Menu &dish);

    Menu(Menu &&other) noexcept;

    virtual ~Menu();

};

#endif //LAB2_MENU_H
