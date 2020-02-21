#include <iostream>
#include <vector>
#include "HashTable.h"
#include <stdio.h>
using namespace std;

class Heap{
  public:
    void percolateup(int a, HashTable*);
    void percolatedown(int a, HashTable*);
    Heap();
    void insert(int a, HashTable*);
    int delMin(HashTable*);
    int deletee(int a, HashTable* , int b);
    int get_size();
    vector<int> get_vector(){
      return heap;
    }




  private:
    vector<int> heap;
    int size;

};
