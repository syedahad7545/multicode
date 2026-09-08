#ifndef LIST_H
#define LIST_H


class ListArr{
  private:
    inline static int length = 100;
    int arr[100];
    int curr = 0;
    int size = 0;

  public:
    bool isFull();
    void copy(ListArr& obj);
    void clear();
    void insert(int pos, int x);
    void remove(int pos);
    int get(int pos);
    void update(int x, int pos);
    bool find(int x);
    int LENGTH();
    void print();
};

#endif // !LIST_H
