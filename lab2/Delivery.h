#ifndef LAB2_DELIVERY_H
#define LAB2_DELIVERY_H
#include "Orderable.h"

class Delivery : public Orderable{

private:
    bool isAvailable;
    double price;

public:
    Delivery();
    Delivery(bool available, double deliveryPrice); //перевантажений конструктор
    ~Delivery();

    void operator+(const Delivery &rhs); //бінарний оператор

    void setAvailability(bool available);
    virtual void display() override;
    virtual void confirmOrder() override;
};


#endif //LAB2_DELIVERY_H
