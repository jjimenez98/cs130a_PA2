#include "HashTable.h"

HashTable::HashTable(){
  tablesize = 43;
  hash_table = new Node*[tablesize];
  for(int i = 0; i < tablesize; i++){
    hash_table[i] = NULL;
  }
}

HashTable::~HashTable(){
  delete [] hash_table;
}

HashTable::Node **HashTable::get_table(){
  return hash_table;
}


bool HashTable::insert(int a){
  bool repition = false;
  int key;
  string result;
  if(a>0){
  key = a%tablesize;
  }else if(a<0){
  key = (a%tablesize) + tablesize;
  }
  Node *h = hash_table[key];
  if(h == NULL){
    hash_table[key] = new Node;
    hash_table[key]->value = a;
    hash_table[key]->next = NULL;
    hash_table[key]->count = 1;
    result = "item successfully inserted, count = 1";
    cout<<result<<endl;
  }else{
    Node *prevnode;
    while(h!=NULL){
      if(h->value == a){
        repition = true;
         h->count = h->count + 1;
         result = "item successfully inserted, count = " + to_string(h->count);
         cout<<result<<endl;
      }


      prevnode = h;
      h = h->next;
    }
    if(repition == false){
      h = new Node;
      h->value = a;
      h->count = 1;
      h->next = NULL;
      result = "item successfully inserted, count = " + to_string(h->count);
      cout<<result<<endl;
    }
  }
  return repition;
}


void HashTable::lookup(int a){
  string message;
  bool f = false;
  int key;
  if(a>0){
  key = a%tablesize;
  }else if(a<0){
  key = (a%tablesize) + tablesize;
  }
  Node *h = hash_table[key];
  while(h!=NULL){
    if(h->value==a){
      f = true;
      break;
    }
    h = h->next;
  }if(f){

    message = "item found, count = " + to_string(h->count);
    cout<<message<<endl;
  }else{
    message = "item not found";
    cout<<message<<endl;
  }
}
int HashTable::delete_i(int a){
  int key;
  if(a>0){
  key = a%tablesize;
  }else if(a<0){
  key = (a%tablesize) + tablesize;
  }
  Node *h = hash_table[key];
  Node *prev;
  prev = NULL;
  bool f = false;
  int indexh = -1;
  int delay = 0;
  while(h!=NULL){
    if(h->value == a){
      if(h->next!=NULL){
      prev->next = h->next;
      }
      f = true;
      indexh = h->heapi;
      delete h;
      h = NULL;

      break;
    }
    prev = h;
    h = h->next;
  }
  if(!f){
    cout<<"item not present in the table"<<endl;
  }

  return indexh;
}

void HashTable::changeHI(int a, int b){
  int key;
  if(a>0){
  key = a%tablesize;
  }else if(a<0){
  key = (a%tablesize) + tablesize;
  }
  Node *h = hash_table[key];
  while(h!=NULL){
    if(h->value == a){
      break;
    }
    h= h->next;
  }
  if(h!=NULL){
    h->heapi = b;
  }
}
