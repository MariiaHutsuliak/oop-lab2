#include "Appetizers.h"

int Appetizers::numberOfAppetizers = 0;
int Appetizers::getNumberOfAppetizers(){
    return numberOfAppetizers;
}
Appetizers::Appetizers(const string newBruschetta, const string newCheese, const string newTartar)
            :bruschetta{newBruschetta}, cheese{newCheese}, tartar{newTartar}
            {numberOfAppetizers++;}
Appetizers::~Appetizers(){numberOfAppetizers--;}
