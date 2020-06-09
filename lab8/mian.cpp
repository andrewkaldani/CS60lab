Enable desktop notifications for Santa Clara University Mail.
   OK  No thanks
Meet
Chat

2 of 2
Lab 8 Robert Truog

Andrew Kaldani <akaldani@scu.edu>
Attachments
Thu, Feb 27, 6:55 PM
to cs60labthurs, Robert


5 Attachments

#include <iostream>
#include "node.h"
using namespace std;
std::size_t list_index(node * head_ptr, int target){
  std::size_t count = 0;
  for(node *p = head_ptr;  p!= nullptr; p=p->link()){
    if(p->data()==target){
      return count;
    }

  }
  return -1;
}
node* list_at(node * head_ptr, std::size_t n){
  int index=0;
  for(node *p = head_ptr; p != nullptr; p=p->link()){
    if(n==index){
      return p;
    }
    index++;
  }
  return head_ptr;
}
int main()
{
 node *head = new node(4, nullptr);
node *tail(head);
 node *temp;
 temp = new node(1, nullptr);
 tail->set_link(temp);
 tail = temp;
 head = new node(1, head);
  head = new node(3, head);
  temp = new node(5, nullptr);
  tail->set_link(temp);
  tail = temp;
  for (const node *p = head; p != nullptr; p = p->link())
  cout << p->data() << " ";
  cout << endl;
  cout<<list_index(tail,5)<<endl;
  cout<<list_at(head,2)->data()<<endl;

  return 0;
 }
