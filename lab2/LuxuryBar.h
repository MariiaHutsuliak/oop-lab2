#ifndef LAB2_LUXURYBAR_H
#define LAB2_LUXURYBAR_H
#include "Bar.h"
#include <fstream>

class LuxuryBar: public Bar {
public:
    bool premiumQuality;
    string origin;

    LuxuryBar (string newName = "None", double newPrice = 0, string newSpecial = "None",
               bool newPremiumQuality = false, string newOrigin = "None");

    LuxuryBar(const LuxuryBar &other);

    LuxuryBar& operator=(const LuxuryBar& other);

    friend ostream &operator <<(ostream &os, LuxuryBar &cocktail);
    friend istream &operator >>(istream &is, LuxuryBar &cocktail);

    ~LuxuryBar();

    void displayLuxuryBar(const vector<unique_ptr<LuxuryBar>>& luxuryBarMenu);
    void addLuxuryBarItem(vector<unique_ptr<LuxuryBar>>& luxuryBarMenu);
    static void changeLuxuryBarItem(vector<unique_ptr<LuxuryBar>>& luxuryBarMenu);

};



#endif //LAB2_LUXURYBAR_H
