#include "Quash.h"


Quash::Quash(){
  heap = new Heap();
  htable = new HashTable();
}

void Quash::lookup(int a){
  htable->lookup(a);
}

void Quash::insert(int a){
  HashTable *h = htable;
  bool dup = htable->insert(a);
  if(!dup){
    heap->insert(a,h);
  }
}

void Quash::deleteMin(){
  if(heap->get_size()!=0){

  int key2;
  if(heap->get_vector()[0]>0){
  key2 = heap->get_vector()[0]%43;
  }else if(heap->get_vector()[0]<0){
  key2 = (heap->get_vector()[0]%43) + 43;
  }
  HashTable *h = htable;
HashTable::Node *l = htable->get_table()[key2];
int count = 0;
while(l!=NULL){
  if(l->value==heap->get_vector()[0]){
    count = l->count;
    if(count>1){
      l->count = l->count - 1;
      cout<<"min item = "<<heap->get_vector()[0]<<", count decremented, new count = "<< l->count <<endl;
    }

    break;
  }
  l = l->next;
}
if(count == 1 || count == 0){
  if(heap->get_size()!=0){
    HashTable *h = htable;
    int a = heap->delMin(h);
  }
}
}else{
    cout<<"min item not present since table is empty"<<endl;
}
}

void Quash::deletee(int a){
  int key2;
  if(a>0){
  key2 = a%43;
  }else if(a<0){
  key2 = (a%43) + 43;
  }
  HashTable *h = htable;
  bool f = false;
  int key;
  for(int i =0; i<heap->get_size();i++){
    if(heap->get_vector()[i]==a){
      key = i;
      f =true;
    }
  }
  if(!f){
    cout<<"item not present in the table"<<endl;
  }
  else{



  HashTable::Node *l = htable->get_table()[key2];
  int count = 0;
  while(l!=NULL){
    if(l->value==a){
      count = l->count;

      if(count>1){
        l->count = l->count - 1;
        cout<<"item count decremented, new count = "<< l->count <<endl;
      }

      f = true;
      break;
    }
    l = l->next;
  }
  if(count == 1){
  h->delete_i(a);
  heap->deletee(key,h,1);
}
}
}

void Quash::print(){
  HashTable * h = htable;
  string result;
  for(int i = 0 ; i<heap->get_size();i++){
    result = result+ to_string(heap->get_vector()[i]) + " ";
  }
  cout<<result<<endl;
}
int main(int argc, char *argv[]){
  Quash quash_ex;
  string m;
  int input;
  string temp = "";
  int index;
  string value = "";
  string op = "";
  int space_recorder = 0;
  vector<string> operations;
  if(argc>1){
  m = argv[1];
}
  for(int i= 0; i<m.length();i++){
    if(m[i]==','){
      operations.push_back(temp);
      temp = "";
    }
    else{
      if(m[i-1]!=','){
    temp = temp + m[i];}
    }
  }
  operations.push_back(temp);
  for(int j=0; j<operations.size();j++){
    for(int x =0; x<operations[j].length();x++){
      if(operations[j][x] == ' ' || space_recorder == 1){
        space_recorder = 1;
        if(operations[j][x]!=' '){
        value = value + operations[j][x];

        }
      }
      else{
        if(operations[j][x] != ' '){
        op = op + operations[j][x];
      }
      }
    }
    space_recorder=0;
    if(value != ""){
    input = stoi(value);
  }

    if(op=="insert"){
      quash_ex.insert(input);
    }
    else if(op=="lookup"){
      quash_ex.lookup(input);
    }
    else if(op=="delete"){
      quash_ex.deletee(input);
    }
    else if(op == "deleteMin"){
      quash_ex.deleteMin();
    }
    else if(op == "print"){
      quash_ex.print();
    }
    value = "";
    op = "";

  }
  return 0;

}
