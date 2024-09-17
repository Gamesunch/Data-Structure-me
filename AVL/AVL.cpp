/*
  Insertion and delete code are from geeksforgeeks.
  for more information you can go to link below to understand more.
  
  https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
  https://www.geeksforgeeks.org/deletion-in-an-avl-tree/
  
*/

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height; 

    Node(int item) {
        key = item;
        left = right = NULL;
        height = 1;
    }
};

int height(Node* node) {
    if (node == NULL) {
    	return 0;	
	}
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) {
    	return 0;	
	}
    return height(node->left) - height(node->right);
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    
    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insert a node in AVL tree
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else  
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    // Left Left Case
    if (balance > 1 && key < node->left->key){
    	return rightRotate(node);
	}
    
    // Right Right Case
    if (balance < -1 && key > node->right->key){
    	return leftRotate(node);
	}

	// Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    
    return node;
}


Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node in AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: Node has only one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
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

    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0){
    	return rightRotate(root);
	}

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0){
    	return leftRotate(root);
	}

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

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
        } else if (inp == 'p') {
            preorder(root);
            cout << endl;
        } else if (inp == 'x') {
            break;
        }
    }

    return 0;
}
