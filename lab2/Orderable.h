#ifndef LAB2_ORDERABLE_H
#define LAB2_ORDERABLE_H
class Orderable {
public:
    virtual void display() = 0;
    virtual void confirmOrder() = 0;
    virtual ~Orderable(){}
};


#endif //LAB2_ORDERABLE_H
