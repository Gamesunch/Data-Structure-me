#include <iostream>
#include <string>

#define SIZE 10
#define R 5
using namespace std;

class HashTable{
  public:
    int Hashkey[SIZE];
    string Hashdata[SIZE];

  HashTable(){
    for(int i = 0; i<SIZE;i++){
      Hashkey[i] = -1;
      Hashdata[i] = "NULL";
    }
  }

  void addEasy(int key,string data){ //no collision handle
    //hash function
    int i = key%SIZE;
    Hashkey[i] = key;
    Hashdata[i] = data;

  }

  string searchEasy(int key){
    int i = key%SIZE;
    if(Hashkey[i] == key){
      return Hashdata[i];
    }
    else{
      return "None";
    }
  }

  void add_linear(int key,string data){ //collision handle
    for(int i = 0 ;i<SIZE;i++){ //check collision;
      int hash = (key + i) % SIZE;
      if(Hashkey[hash] == -1){
        Hashkey[hash] = key;
        Hashdata[hash] = data;
        break;
      }
    }
  }

  string search_linear(int key){
    for(int i = 0;i<SIZE;i++){
      int hash = (key + i) % SIZE;
      if(Hashkey[hash] == key){
        return Hashdata[hash];
      }
      if(Hashkey[hash] == -1){
        return "NONE";
      }
    }
  }

  void add_Quadratic(int key,string data){ //collision handle
    for(int i = 0 ;i<SIZE;i++){ //check collision;
      int hash = (key + (i*i)) % SIZE;
      if(Hashkey[hash] == -1){
        Hashkey[hash] = key;
        Hashdata[hash] = data;
        break;
      }
    }
  }

  string search_Quadratic(int key){
    for(int i = 0;i<SIZE;i++){
      int hash = (key + (i*i)) % SIZE;
      if(Hashkey[hash] == key){
        return Hashdata[hash];
      }
      if(Hashkey[hash] == -1){
        return "NONE";
      }
    }
  }

  void add_double_hash(int key,string data){
    int fx = R - (key % R);
    for(int i = 0;i<SIZE;i++){
      int hash = (key + (i*fx))%SIZE;
      if(Hashkey[hash] == -1){
        Hashkey[hash] = key;
        Hashdata[hash] = data;
        break;
      }
    }
  }

  string search_double_hash(int key){
    int fx = R - (key % R);
    for(int i = 0;i<SIZE;i++){
      int hash = (key + (i*fx))%SIZE;
      if(Hashkey[hash] == key){
        return Hashdata[hash];
      }
      if(Hashkey[hash] == -1){
        return "NONE";
      }
    }
  }

  void printEasy(){
    for(int i = 0;i<SIZE;i++){
      cout<<"("<<Hashkey[i]<<","<<Hashdata[i]<<")"<<endl;
    }
  }

};

int main(){
  HashTable h;

  h.add_linear(2341,"Hello");
  h.add_linear(2321,"test");
  h.add_linear(1234,"Holle");
  h.add_double_hash(124,"test2");

  cout<<h.search_linear(2341)<<endl;
  cout<<h.search_linear(124)<<endl;

  h.printEasy();
}
