#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

// Function to search a key in a BST
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    
    return root;
} 

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) { //if the tree is empty.
        cout<<"Empty Tree"<<endl;
        return root;
    } 

    // Recursive calls to find the node to delete
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        }
        // Case 2: Node has only one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

//Breadth First Traversal
void showBFS(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Marker for the end of a level

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == NULL) {
            if (!q.empty()) {
                cout << "|";
                q.push(NULL);  // Add marker for next level
            }
        } else {
            cout << current->key << ",";

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }
    
    cout << "|";
}


// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    
    inorder(root->left);
    cout << root->key << ",";
    inorder(root->right);
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;
    
    cout << root->key << ",";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(Node* root) {
    if (root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->key << ",";
}

// Driver Code
int main() {
    Node* root = NULL;
    char inp;
    int data;

    while (true) {
        cin >> inp;

        if (inp == 'a') {
            cin >> data;
            root = insert(root, data);
        } else if (inp == 'd') {
            cin >> data;
            root = deleteNode(root, data);
        } else if (inp == 'b') {
            showBFS(root);
            cout << endl;
        } else if (inp == 'i') {
            inorder(root);
            cout << endl;
        } else if (inp == 'p') {
            preorder(root);
            cout << endl;
        } else if (inp == 't') {
            postorder(root);
            cout << endl;
        } else if (inp == 'x') {
            break;
        }
    }

    return 0;
}


/*
a 10
a 7
a 13
a 2
a 9
a 20
a 11
b
i
p
t
d 10
b
d 9 
b
x
*/
