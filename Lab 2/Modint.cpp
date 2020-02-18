#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Modint{
private:
  int mod_;
  int value_;
public:
  int mod(){return mod_;}
  int value(){return value_;}
  Modint();
  Modint(int m, int v);
  void operator +=(Modint lhs);
  void operator *=(Modint lhs);

};
Modint::Modint(){
  mod_ = 0;
  value_ =0;
}
Modint::Modint(int m, int v)
{
  mod_=m;
  value_=v;
}
bool operator ==(Modint lhs, Modint rhs)
{
  return lhs.value() == rhs.value() && lhs.mod() == rhs.mod();
}
void Modint::operator +=(Modint lhs)
{

  //int temp =0;
  if(mod_==lhs.mod()){

  value_ = value_ + lhs.value_;
  value_%=mod_;
  //value_ = temp;
}
else{
  mod_ = -1;
  value_ = -1;
}
}
void Modint::operator *=(Modint lhs)
{
  value_ *= lhs.value();
  value_%=mod_;
}
Modint operator *(Modint lhs, Modint rhs)
{
  Modint test(lhs);
  test*=rhs;
  return test;
}
ostream& operator <<(ostream& out, Modint b)
{
  out<<"MOD: "<<b.mod()<<" Value: "<<b.value()<<endl;
  return out;
}
Modint operator +(Modint lhs, Modint rhs)
{
  int m,v;
  if(lhs.mod() == rhs.mod())
  {
    v = lhs.value() + rhs.value();
    v%=rhs.mod();
    m = rhs.mod();

    Modint test(m,v);
    return test;
  }
  else
  {
    Modint test(-1,-1);
    return test;
  }
}

int main(){
  Modint one(5,5);
  Modint two(5,12);
  Modint three(5,28);
  Modint tw(5,12);

  cout<<(tw==two)<<endl;
  cout<<(one+two)<<endl;
  cout<<(two*three)<<endl;
  one+=two;
  two*=three;
  cout<<two<<endl;
  cout<<one<<endl;
}
