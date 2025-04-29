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
        int index = key % SIZE;

        // Check if the key already exists
        for (int j = 0; j < SIZE; j++) {
            if (table[j]->key == key) {
                cout << "Key already exists" << endl;
                return;
            }
            Node* s = table[j]->next;
            while (s != NULL) {
                if (s->key == key) {
                    cout << "Key already exists" << endl;
                    return;
                }
                s = s->next;
            }
        }

        // Add new node
        if (table[index]->key == -1) {
            table[index]->key = key;
            table[index]->data = data;
        } else {
            Node* n = table[index];
            while (n->next != NULL) {
                n = n->next;
            }
            n->next = new Node(key, data);
        }
    }

    string search(int key) {
        int index = key % SIZE;
        Node* n = table[index];
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

    while (true) {
        cin >> command;
        if (command == "e") {
            break;
        }

        if (command == "a") {
            cin >> key >> data;
            h.add(key, data);
        } else if (command == "s") {
            cin >> key;
            cout << h.search(key) << endl;
        } else if (command == "p") {
            h.print();
        }
    }

    return 0;
}
