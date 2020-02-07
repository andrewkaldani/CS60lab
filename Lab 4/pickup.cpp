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
