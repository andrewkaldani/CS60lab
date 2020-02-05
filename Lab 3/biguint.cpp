Enable desktop notifications for Santa Clara University Mail.
   OK  No thanks

4 of 10
Fwd: Lab 3 Graham Kaldani
Inbox
x

Adam Graham
Attachments
Mon, Jan 27, 9:17 AM (8 days ago)
to me



---------- Forwarded message ---------
From: Adam Graham <ajgraham@scu.edu>
Date: Thu, Jan 23, 2020, 7:27 PM
Subject: Lab 3 Graham Kaldani
To: <cs60labthurs@gmail.com>


Fixed for last one, #7.
3 Attachments

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
