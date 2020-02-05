#include "biguint.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  biguint one("123");
  cout<<one<<endl;
  biguint two("456");
  cout<<two<<endl;
  one+=two;
  cout<<one<<endl;
  int i = two[1];
  std::cout << i << '\n';

}
