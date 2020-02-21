#include "Heap.h"

Heap::Heap(){
  heap = vector<int>();
  size = 0;
}

void Heap::percolateup(int a, HashTable* h){
  if(a!=0 && heap[(a-1)/2] > heap[a]){
    int t = heap[a];
    heap[a] = heap[(a-1)/2];
    heap[(a-1)/2] = t;
    h ->changeHI(heap[(a-1)/2], (a-1)/2);
    h ->changeHI(heap[a],a);

    percolateup((a-1)/2,h);
  }
}
void Heap::percolatedown(int a, HashTable* h){
  if(a * 2 + 1 <= (int)heap.size() -1){
    int ch1;
    int ch2;
    int smallch;
    int smallchi;
    ch1 = heap[a*2+1];
    if(a*2+2  <= (int)heap.size()-1){
      ch2 = heap[a*2+2];
      if(ch1 < ch2){
        smallch = ch1;
        smallchi = a * 2 + 1;
      }
      else{
        smallch = ch2;
        smallchi = a * 2 + 2;
      }
    }
    else{
      smallch = ch1;
      smallchi = a * 2 + 1;
    }
    if(heap[a] > smallch){
      int z = heap[a];
      heap[a] = heap[smallchi];
      heap[smallchi] = z;

      h-> changeHI(heap[a],a);
      h-> changeHI(heap[smallchi], smallchi);
      percolatedown(smallchi,h);
    }
  }
}

void Heap::insert(int a, HashTable* h){
  heap.push_back(a);
  int key = heap.size() - 1;
  h -> changeHI(heap[key],key);
  percolateup(key,h);
}


int Heap::deletee(int a, HashTable* h, int b){
  int delv = 0;
  int deleted;
  if(h==NULL){
    cout<<"min item not present since table is empty"<<endl;
  }

    delv = heap[a];
    int t = heap[heap.size()-1];
    heap[a] = t;
    heap.pop_back();
    if(b==0){
    cout<< "min item "<<delv<<" successfully deleted"<<endl;
   }
   else if(b==1){
     cout<< "item successfully deleted"<<endl;
   }
    if(heap.size()>0){
      if(a < (int)heap.size()){
        h->changeHI(heap[a],a);
        percolateup(a,h);
        percolatedown(a,h);
      }
    }

  return delv;
}

int Heap::delMin(HashTable* h){

  return deletee(0,h,0);
}



int Heap::get_size(){
  return heap.size();
}
