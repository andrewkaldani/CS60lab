#include <iostream>
using namespace std;

bool issorted(int a[], int n){
  if(n==1 || n==0){
    return true;
  }if(a[n-2]>a[n-1]){
    return false;
  }
  else{
    return issorted(a, n-1);
  }

}

int main(){
  int array[3]={0,1,2};
  cout<<issorted(array, 3)<<endl;
}
