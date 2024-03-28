#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include <vector>
#include <string>
using namespace std;
#include <memory>

class Menu {
public:
    string name;
    double price;
    double weight;

    void displayMenu(const vector<shared_ptr<Menu>>& menu);
    void addMenuItem(vector<shared_ptr<Menu>>& menu);
    void changeMenuItem(vector<shared_ptr<Menu>>& menu);

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
