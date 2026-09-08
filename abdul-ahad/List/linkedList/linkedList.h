#ifndef LINKEDLIST_H
#include <iostream>

class Node{
  private:
    int data;
    Node* next;
  public:
    Node(){}
    Node(int val){
      data = val;
    }
    void setData(int val){
      data = val;
    }
    void setNext(Node* next){
      this->next = next;
    }
    int getData(){
      return data;
    }
    Node* getNext(){
      return next;
    }
};
class list{
  private:
    Node* head;
    Node* curr;
    Node* prevNode;
    int size;
  public:
    list(){
      head = new Node;
      head->setNext(nullptr);
      curr = nullptr;
      prevNode = nullptr;
      size = 0;
    }

    void addNode(int val){
      Node* node = new Node(val);
      //Two cases:
      //1- there is no element in the list
      //2- there are/is element in the list
      if(size == 0){ //checking for the there is no element in the list
        head->setNext(node);
        node->setNext(nullptr); //These two lines establishing the link

        curr = node;
        prevNode = head;
      }else{ //checking for the case when there are elements
        node->setNext(curr->getNext());
        curr->setNext(node); //These two lines establishing the link 

        prevNode = curr;
        curr = node;
      }
      size++;
    }
    bool findNode(int val){ // find the element and if found then points the curr ptr to that element
      if(size == 0){ // This will prevent the null pointer access problem with the next line
        return false;
      }
      Node* foundNode = head->getNext();
      Node* foundPrevNode = head; //The two dummy variables for curr and prevNode
      bool found = false;

      for(int i = 0; i < size; ++i){
        if(foundNode->getData() == val){
          found = true;
          break;
        }else{
          foundPrevNode = foundNode;
          foundNode = foundNode->getNext();
        }
      }

      if(found){
        curr = foundNode;
        prevNode = foundPrevNode;
        return true;
      }else{
        return false;
      }

    }

    bool Next(){
      if(curr->getNext()){ // if the result is not nullptr
        prevNode = curr;
        curr = curr->getNext();
        return true;
      }else{ // if the result if nullptr
        std::cout << "The pointer is already on the last element" << std::endl;
        return false;
      }
    }
    void start(){
      curr = head; //pointing at the first element
      prevNode = head; 
    }
    void Back(){ //Back traversal is not possible cuz it is a singly linked list not a doubly linked list

    }
    void DeleteNode(int val){
      //This is the function where the prevNode field will be used
      if(findNode(val)){ //result is not the nullptr
        prevNode->setNext(curr->getNext());
        delete curr;
        //handling the case where what if the element we are deleting is the last element
        if(prevNode->getNext()) 
          curr = prevNode->getNext(); 
        else
          curr = prevNode;

      }else{ //result is nullptr
        std::cout << "The Node doesn't exist at all" << std::endl;
      }
      size--;
    }

    void DisplayAll(){
      if(size == 0){
        std::cout << "No elements in the list" << std::endl;
        return;
      }
      Node* ptr = head->getNext();
      for(int i = 0; i < size; ++i){
        std::cout << ptr->getData() << " ";
        ptr = ptr->getNext();
      }
      std::cout << std::endl;
    }

    void Size(){
      std::cout << "The size of the list is: "<< size << std::endl;
    }
    int get(){
      return curr->getData();
    }
};
#endif // !LINKEDLIST_H

