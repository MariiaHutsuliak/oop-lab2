#ifndef LAB2_LUXURYBAR_H
#define LAB2_LUXURYBAR_H
#include "Bar.h"

class LuxuryBar: public Bar {
public:
    bool premiumQuality;
    string origin;

    LuxuryBar (string newName = "None", double newPrice = 0, string newSpecial = "None",
               bool newPremiumQuality = false, string newOrigin = "None");

    LuxuryBar(const LuxuryBar &other);

    LuxuryBar& operator=(const LuxuryBar& other);

    ~LuxuryBar();

    void display();

};


#endif //LAB2_LUXURYBAR_H
