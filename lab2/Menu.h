#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include <vector>
#include <string>
using namespace std;

class Menu {
private:
    string name;
    double price;
    double weight;

public:
    void display();
    void updateItem(string &newName, double newPrice, double newWeight);

    Menu(); // конструктор за замовчуванням
    Menu(string new_name); // перевантажений конструктор
    Menu(string new_name, double new_price);
    Menu(string new_name, double new_price, double new_weight);
    ~Menu();
};

#endif //LAB2_MENU_H
