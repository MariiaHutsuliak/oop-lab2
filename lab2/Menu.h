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

    void displayMenu(const vector<unique_ptr<Menu>>& menu);
    void addMenuItem(vector<unique_ptr<Menu>>& menu);
    static void changeMenuItem(vector<unique_ptr<Menu>>& menu);

    Menu();
    Menu(string new_name);
    Menu(string new_name, double new_price);
    Menu(string new_name, double new_price, double new_weight);

    friend ostream &operator <<(ostream &os, Menu &dish);
    friend istream &operator >>(istream &is, Menu &dish);

    Menu(Menu &&other) noexcept;
    virtual ~Menu();

};

#endif //LAB2_MENU_H
