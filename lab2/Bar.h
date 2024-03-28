#ifndef LAB2_BAR_H
#define LAB2_BAR_H

#include <string>
#include <memory>
#include <vector>
#include <fstream>
using namespace std;

class Bar {
public:
    string name;
    double price;
    string special;

    void displayBar(const vector<shared_ptr<Bar>>& barMenu);
    void addBarItem(vector<shared_ptr<Bar>>& barMenu);

    Bar(string newName = "None", double newPrice = 0, string newSpecial = "None"); // конструктор з параметрами

    friend ostream &operator <<(ostream &os, Bar &cocktail);
    friend istream &operator >>(istream &is, Bar &cocktail);

    Bar(const Bar &other);
    ~Bar();

};


#endif //LAB2_BAR_H
