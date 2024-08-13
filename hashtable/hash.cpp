#include <iostream>
#include <string>
#define SIZE 17

using namespace std;

class Node {
  public:
    int key;
    string data;
    Node* next;

    Node() {
      key = -1;
      data = "-";
      next = NULL;
    }

    Node(int k, string d) {
      key = k;
      data = d;
      next = NULL;
    }
};

class HashTable {
  public:
    Node* table[SIZE];

    HashTable() {
      for (int i = 0; i < SIZE; i++) {
        table[i] = new Node();
      }
    }
  
    void add(int key, string data) {
      int i = key % SIZE;
      if (table[i]->key == -1) {
        table[i]->key = key;
        table[i]->data = data;
      } else {
        Node* n = table[i];
        while (n->next != NULL) {
          n = n->next;
        }
        n->next = new Node(key, data);
      }
    }

    string search(int key) {
      int i = key % SIZE;
      Node* n = table[i];
      while (n != NULL) {
        if (n->key == key) {
          return n->data;
        }
        n = n->next;
      }
      return "-";
    }

    void print() {
      for (int i = 0; i < SIZE; i++) {
        cout << "(" << table[i]->key << "," << table[i]->data << ")";
        Node* n = table[i]->next;
        while (n != NULL) {
          cout << " (" << n->key << "," << n->data << ")";
          n = n->next;
        }
        cout << endl;
      }
    }
};

int main() {
  HashTable h;
  
  string command;
  int key;
  string data;

  while(true){
    cin>>command;
    if(command == "e"){
      break;
    }
    
    if(command == "a"){
      cin>>key>>data;
      h.add(key, data);
    } else if(command == "s"){
      cin>>key;
      cout<<h.search(key)<<endl;
    } else if(command == "p"){
      h.print();
    }
  }
}
