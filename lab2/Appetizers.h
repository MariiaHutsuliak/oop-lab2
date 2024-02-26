
#ifndef LAB2_APPETIZERS_H
#define LAB2_APPETIZERS_H
#include <string>
using namespace std;

class Appetizers {

private:
    const string bruschetta;
    const string cheese;
    const string tartar;


public:
    Appetizers(const string newBruschetta = "None",
               const string newCheese = "None",
               const string newTartar = "None");
    ~Appetizers();



};


#endif //LAB2_APPETIZERS_H
