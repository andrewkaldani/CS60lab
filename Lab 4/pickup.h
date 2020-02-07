#ifndef PICKUP_H
#define PICKUP_H
#include <string>
#include "automobile.h"

class Pickup : public Automobile
{
    private:
    int capacity_;
    bool extendCab_;

    public:
    int capacity(){return capacity_;}
    bool extendedCab(){return extendCab_;}
    Pickup();
    Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int icapacity, bool iextended);
    bool park(bool lot[], int size);
};
#endif
