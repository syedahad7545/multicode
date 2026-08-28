#include "List.h"


auto main(int argc, char *argv[]) -> int {

  ListArr obj1;

  obj1.insert(0, 10);
  obj1.insert(1, 9);
  obj1.insert(2, 8);
  obj1.insert(3, 7);
  obj1.insert(4, 6);
  obj1.insert(5, 5);
  obj1.insert(6, 4);
  obj1.insert(7, 3);
  obj1.insert(8, 2);
  obj1.insert(9, 1);

  obj1.remove(9);
  //std::cout << obj1.LENGTH() <<std::endl;
  obj1.print();
}
