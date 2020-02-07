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
