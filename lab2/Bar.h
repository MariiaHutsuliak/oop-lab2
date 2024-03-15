#ifndef LAB2_BAR_H
#define LAB2_BAR_H
#include "Orderable.h"
#include <string>
using namespace std;

class Bar: public Orderable {
public:
    string name;
    double price;
    string special;

    void display() override;
    void confirmOrder() override;

    Bar(string newName = "None", double newPrice = 0, string newSpecial = "None"); // конструктор з параметрами

    Bar(const Bar &other);
    ~Bar();

};


#endif //LAB2_BAR_H
