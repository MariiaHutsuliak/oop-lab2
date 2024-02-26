#ifndef LAB2_DELIVERY_H
#define LAB2_DELIVERY_H


class Delivery {

private:
    bool isAvailable;
    double price;

public:
    Delivery();
    Delivery(bool available, double deliveryPrice); //перевантажений конструктор
    Delivery(Delivery&& other) noexcept;

    ~Delivery();

    void setAvailability(bool available);
    void displayInfo();

};


#endif //LAB2_DELIVERY_H
