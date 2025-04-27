#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int v){
      value = v;
      next = NULL;
      prev = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList(){
    	head = NULL;
	}
    //Destructor
    ~LinkedList() {  
        clear();
    }

    void clear() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
    }
    
    void insertFirst(int value) {
    	
	    // Check if value already exist
	    Node* p = head;
	    while (p != NULL) {
	        if (p->value == value) {
	            return;
	        }
	        p = p->next;
	    }
	
	    Node* node = new Node(value);
	    node->next = head;
	    if (head != NULL) {
	        head->prev = node;
	    }
	    head = node;
	    print();
	}


    void insertLast(int value) {
        Node* node = new Node(value);
        //if it first node;
        if (head == NULL) {
            head = node;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = node;
        node->prev = last;
    }

    void insertAfter(int value, int target) {
        // check if value already in node
        Node* p = head;
        while (p != NULL) {
            if (p->value == value) {
                return;
            }
            p = p->next;
        }

        // reset P;
        p = head;

        // Find the node with the 'target' value
        while (p != NULL && p->value != target) {
            p = p->next;
        }

        // target not found
        if (p == NULL) {
            insertLast(value);
            print();
            return;
        }

        Node* node = new Node(value);
        node->next = p->next;
        node->prev = p;
        p->next = node;

        if (node->next != NULL) {
            node->next->prev = node;
        }

        print();
    }

    void insertBefore(int value, int target) {
        Node* p = head;

        while (p != NULL) {
            if (p->value == value) {
                return;
            }
            p = p->next;
        }

        p = head;

        while (p != NULL && p->value != target) {
            p = p->next;
        }

        // target not found
        if (p == NULL) {
            insertLast(value);
            print();
            return;
        }

        Node* node = new Node(value);
        node->next = p;
        node->prev = p->prev;

        if (p->prev != NULL) {
            p->prev->next = node;
        } else {
            head = node;
        }
        p->prev = node;

        print();
    }

    void deleteNode(int targetValue) {
        Node* current = head;

        while (current != NULL && current->value != targetValue) {
            current = current->next;
        }

        //if no node
        if (current == NULL) {
            return;
        }

        if (current == head) {
            head = current->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
        }

        delete current; // Free memory
        print();
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    string input;
    int value, id;
    while (true) {
        cin >> input;

        if (input == "E") {
            break;
        }

        if (input == "I") {
            cin >> value >> id;
            l.insertBefore(value, id);
        } else if (input == "A") {
            cin >> value >> id;
            l.insertAfter(value, id);
        } else if (input == "D") {
            cin >> value;
            l.deleteNode(value);
        }
    }

    return 0;
}
/*
testcase   
I 1 0
I 2 1
I 3 0
I 4 2
I 5 2
I 4 2
I 5 3
I 6 3
I 10 5
I 11 100
I 12 200
D 11
D 4
D 12
D 2
A 13 10
A 14 5
A 15 200
*/

/*
output
1
2 1
2 1 3
4 2 1 3
4 5 2 1 3
4 5 2 1 6 3
4 10 5 2 1 6 3
4 10 5 2 1 6 3 11
4 10 5 2 1 6 3 11 12
4 10 5 2 1 6 3 12
10 5 2 1 6 3 12
10 5 2 1 6 3
10 5 1 6 3
10 13 5 1 6 3
10 13 5 14 1 6 3
10 13 5 14 1 6 3 15
*/
