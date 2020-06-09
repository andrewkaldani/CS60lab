#include "automobile.h"
#include "pickup.h"
#include "van.h"
#include <iostream>

using namespace std;

int main() {
    Automobile car1;
    Automobile car2("toyota","camry",2020,10000,1);
    bool usedLot[] = {true, false, true, false};
    cout << car2.park(usedLot,4)<<endl;;
    Pickup pickup1;
    Pickup pickup2 ("toyota","camry",2020,10000,1,1000,true);
    bool usedLot2[] = {true, true, false};
    cout << pickup2.park(usedLot2,3)<<endl;
    Van van1;
    Van van2 ("toyota","camry",2020,10000,1,6);
    Van van3 ("toyota","camry",2020,10000,1,8);
    cout << van2.park(usedLot2,3)<<endl;
    cout << van3.park(usedLot2,3)<<endl;

    return 0;
};


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

#include "pickup.h"

    Pickup::Pickup():Automobile(){
    capacity_ = 0;
    extendCab_ = false; 
}
    Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int icapacity, bool iextended):Automobile(imake,imodel,iyear,iprice,istall){ 
    capacity_ = icapacity;
    extendCab_ = iextended;
    }

    bool Pickup::park(bool lot[], int size){
    int spot=size;
    for(int i=0; i<size; i++){
        if(!lot[i] && !lot[i-1])
            spot = i - 1;
    }
    if(spot>=size)
       return false;
    else{
        lot[spot] = true;
        lot[spot + 1] = true;
        set_stall(spot);
        return true;
    }
}


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


#include "van.h"

    Van::Van():Automobile(){
        seats_ = 0;
    }
    Van::Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int iseats):Automobile(imake,imodel,iyear,iprice,istall){
        seats_ = iseats;
    }
    bool Van::park(bool lot[], int size){
        if (seats_ <= 7){
            return Automobile::park(lot, size);
        }
        else {
            int spot=size;
            for(int i=0; i<size; i++){
                if(!lot[i] && !lot[i-1])
                    spot = i - 1;
            }
            if(spot>=size)
            return false;
            else{
                lot[spot] = true;
                lot[spot + 1] = true;
                set_stall(spot);
                return true;
            }
        }
    }
