//Part A:
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
template <typename T1, typename T2>
// T1 support ==
// T2 add
int count_exact(T1 a[], T2 size, T1 find){
int count =0;
for(T2 i = 0; i < size; i++)
{
  if(a[i]==find){
    count++;
  }
}
return count;
}

template <typename T1, typename T2>
// T1 <= && >=
//T2 sets equal to 0 and implement
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
  int count =0;
  for(T2 i = 0; i < size; i++)
  {
    if(a[i]>= low && a[i] <= high){
      count++;
    }
  }
  return count;
}


int main(){
    int arr[6] = {6,2,3,2,6,2};
    int test = count_exact(arr,6,2);
    cout<<test<<endl;
    string array[3] = {"hi","hello","hi"};
    string target = "hi";
    int test2 = count_exact(array,3,target);
    cout<<test2<<endl;

    int test3 = count_range(arr,6,2,3);
    cout<<test3<<endl;
    string low = "hello";
    int test4 = count_range(array,3,target,target);
    cout<<test4<<endl;

}

//Part B:
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>
class nPoint {
private:
  T arr[10];
  int dimension;
public:
  nPoint();
  nPoint(int d);
  nPoint(int d, T a[]);
  T ith(int i);
  int size(){return dimension;}
  void operator  =(nPoint<T> rhs);
};
  template <typename T>
   nPoint<T>::nPoint()
  {
    dimension = 0;

  }

  template <typename T>
  nPoint<T>::nPoint(int d)
  {
    dimension = d;
    for(int i = 0; i < dimension; i++)
    {
      arr[i]=T();
    }
  }
  template <typename T>
  nPoint<T>::nPoint(int d, T a[])
  {
    dimension = d;
    for(int i = 0; i < dimension; i++)
    {
      arr[i]=a[i];
    }
  }
  template <typename T>
T nPoint<T>::ith(int i){
  return arr[i];
}
  template <typename T>
void nPoint<T>::operator  =(nPoint<T> rhs)
{
  dimension = rhs.size();

  for(int i =0; i < size(); i++)
  {
    arr[i] = rhs.ith(i);

  }

}




int main (){
  int arr[2] = {3,4};
  nPoint<int> npoint(2,arr);
  cout<<npoint.ith(1) << npoint.size() << endl;
  nPoint<int> test;
  test  = npoint;

  cout<<test.ith(1) << test.size() << endl;

 return 0;
}
