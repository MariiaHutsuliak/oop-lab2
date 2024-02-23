#ifndef LAB2_BAR_H
#define LAB2_BAR_H

#include <string>
using namespace std;

class Bar {
private:
    string name;
    double price;
    string special;

public:
    void display();
    void updateBar(string newName, double newPrice, string newSpecial);

    Bar(string newName = "None", double newPrice = 0, string newSpecial = "None");
    ~Bar();
};


#endif //LAB2_BAR_H
