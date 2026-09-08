#include "linkedList.h"


int main(){
  list obj;
  obj.addNode(1);
  obj.addNode(2);
  obj.addNode(3);
  obj.addNode(4);
  obj.addNode(5);
  obj.addNode(6);

  obj.start();

  while(obj.Next())  {
    std::cout << obj.get() << std::endl;
  }

}
