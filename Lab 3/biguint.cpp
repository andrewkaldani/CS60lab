

#include "biguint.h"
#include <string>
biguint::biguint()
{
  for(size_t i = 0; i < CAPACITY; i++){
    data_[i]=0;
  }
}

biguint::biguint(const std::string &s){
  int templeng = s.length();
  for(size_t i = 0; i < templeng; i++){
    data_[i] = s[templeng -i - 1] -'0';
  }
  for(size_t i = templeng; i < CAPACITY; i++){
    data_[i]=0;
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  unsigned short i = 0;
  if(pos >= 0 && pos < CAPACITY){
    i = data_[pos];
  }
  return i;
}
std::ostream& operator <<(std::ostream& out, const biguint& b)
{
  for (int i = biguint::CAPACITY; i > 0; i--) {
    out<<b[i-1];
  }
  return out;
}
void biguint::operator += (const biguint & b){
  int k = 0;
  int temp = 0;
  for (size_t i = 0; i < CAPACITY; i++) {
    temp = data_[i]+b.data_[i];
    if(temp >= 10){
      data_[i] = temp-10;
      data_[i+1]+=1;
    }
    else{
      data_[i]=temp;
    }
  }
}
