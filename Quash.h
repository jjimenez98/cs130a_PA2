#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#ifndef _QUASH_H
#define _QUASH_H
#include "Heap.h"


using namespace std;

class Quash{
private:
  HashTable *htable;
  Heap *heap;
  vector<string> result;
public:
  Quash();
  void lookup(int a);
  void insert(int a);
  void deletee(int a);
  void deleteMin();
  void print();
};
#endif
