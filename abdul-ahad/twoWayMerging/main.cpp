#include "linkedList.h"

void merge(list l1, list l2, list& l3, int m, int n){
  int i = 0, j = 0;
  while(i < m && j < n){
    if(l1.get() < l2.get()){
      l3.addNode(l1.get());
      l1.Next();
      i++;
    }else{
      l3.addNode(l2.get());
      l2.Next();
      j++;
    }
  }
  for(;i < m;){
    l3.addNode(l1.get());
    l1.Next();
    i++;
  }
  for(;j < n;){
    l3.addNode(l2.get());
    l2.Next();
    j++;
  }

}

int main(){
  list obj1, obj2;

  obj1.addNode(1);
  obj1.addNode(3);
  obj1.addNode(5);
  obj1.addNode(7);
  obj1.addNode(9);
  obj1.addNode(11);
  obj1.addNode(13);

  obj2.addNode(2);
  obj2.addNode(4);
  obj2.addNode(6);
  obj2.addNode(8);
  obj2.addNode(10);
  obj2.addNode(12);

  obj1.start();
  obj1.Next();
  obj2.start();
  obj2.Next();

  list obj3;

  merge(obj1, obj2, obj3, obj1.Size(), obj2.Size());

  obj3.DisplayAll();
  //obj1.DisplayAll();
}
