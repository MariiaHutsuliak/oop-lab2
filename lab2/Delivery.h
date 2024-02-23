#ifndef LAB2_DELIVERY_H
#define LAB2_DELIVERY_H


class Delivery {

private:
    bool isAvailable;
    double price;

private:
    Delivery();
    Delivery(bool available, double deliveryPrice);
    ~Delivery();

    void setAvailability(bool available);
    void displayInfo();

};


#endif //LAB2_DELIVERY_H
