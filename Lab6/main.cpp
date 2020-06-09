 #include "lbiguint.h"
 #include "node.h"
 #include<iostream>
 using namespace std;

 int main()
 {
   string one = "123";
   lbiguint two(one);
   lbiguint four("123456789");
   lbiguint three("4567");

   cout<<one<<endl;
   cout<<"size: "<<one.size()<<endl;

   cout<<"size: of "<<four<<" is "<<four.size()<<endl;
   cout<<"size of "<<three<<" is "<<three.size()<<endl;


 }
