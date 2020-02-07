#ifndef VAN_H
#define VAN_H
#include <string>
#include "automobile.h"

class Van : public Automobile{
    private: 
    int seats_;
    public: 
    Van();
    Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int iseats);
    int getSeats(){return seats_;}
    bool park(bool lot[], int size);
}
;
#endif

