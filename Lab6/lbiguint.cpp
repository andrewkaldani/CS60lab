



#include "lbiguint.h"
#include "node.h"
lbiguint::lbiguint()
{
  head = tail =  new node(0,nullptr);

}
lbiguint::lbiguint(const std::string & s)
{
  node *temp = new node(s[0]-'0',nullptr);

  tail = temp;
  head = temp;
  for(int i =1; i<s.length(); i++){
    assert(isdigit(s[i]));
    head = new node(s[i] - '0', head);
}

}

lbiguint::~lbiguint()
{
  node* temp;
  while(head!=nullptr){
    head->set_data(0);
    temp = head->link();
    delete head;
    head = temp;

  }
  tail=nullptr;
}

std::size_t lbiguint::size() const
{

  size_t temp = 0;
  for(node*p = head; p != nullptr; p = p -> link()){
    temp++;
  }
  return temp;
}

int lbiguint::operator [](std::size_t pos) const
{

  assert(size() >= pos);
    for(node* p = head; p != nullptr; p = p->link()){
        if(pos == 0){
            return p->data();
        }
        --pos;
    }
    return 0;
}


std::ostream& operator << (std::ostream& os, const lbiguint & b)
{
   for (int i = b.size() - 1; i > 0; --i)
     {
         os << b[i];
     }
     os << b[0];
     return os;
}
