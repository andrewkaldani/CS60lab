#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
struct Time{//military time, no am/pm
int hour;
int minute;
};
Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}
class Carpool{
public:
  int numPeople;
  string group[10];
  Time arrive;
  void combineCarpool(Carpool car1, Carpool car2)
  {
    if(car1.numPeople + car2.numPeople <= 5){
      int n = 0;
      arrive = earlier(car1.arrive, car2.arrive);
      numPeople = car1.numPeople + car2.numPeople;
      for(int i = 0; i <= car1.numPeople; i++){
        group[i]=car1.group[i];
      }
      for(int i = car1.numPeople; i <= 5; i++){
        group[i]=car2.group[n];
        n++;
      }
    }
    else if(car1.numPeople + car2.numPeople > 5){
      std::cout << "Carpool to big fam" << '\n';
    }


}
void printName(){
  for(int i = 0; i <= 5; i++){
    std::cout << group[i] << '\n';
  }
}

};
int main(){
  Carpool car1;
  Carpool car2;
  Carpool car3;
  car1.group[0]="Olaf";
  car1.group[1]="Sven";
  car2.group[0]="Will";
  car2.group[1]= "Steve";
  car2.group[2]="Jeff";
  car1.arrive.hour = 7;
  car1.arrive.minute = 20;
  car2.arrive.hour= 6;
  car2.arrive.minute = 35;
  car1.numPeople = 2;
  car2.numPeople = 3;
  car3.combineCarpool(car1, car2);
  std::cout << car3.numPeople << '\n';
  car3.printName();

}
