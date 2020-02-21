#include <iostream>
using namespace std;
class HashTable{

  public:
  struct Node{
    int value;
    int count;
    int heapi;
    Node *next;
  };
    HashTable();
    ~HashTable();
    int getsize();
    bool insert(int a);
    void lookup(int a);
    int delete_i(int a);
    Node **get_table();
    void changeHI(int a, int b);

  private:
    Node **hash_table;
    int tablesize;
};
