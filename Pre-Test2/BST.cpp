#include <iostream>
#include <queue>

using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
	
	Node(int n){
		key = n;
		left = right = NULL;
	}
};

Node* findMin(Node* root){
	while(root && root->left != NULL){
		root = root->left;
	}
	return root;
}

Node* insert(Node* root,int key){
	if(root == NULL){
		return new Node(key);
	}
	
	if(key < root->key){
		root->left = insert(root->left,key);
	}
	else if(key > root->key){
		root->right = insert(root->right,key);
	}
	
	return root;
}

Node* deleteNode(Node* root,int key){
	if(root == NULL){
		cout<<"empty"<<endl;
		return root;
	}
	
	if(key<root->key){
		root->left = deleteNode(root->left,key);
	}
	else if(key > root->key){
		root->right = deleteNode(root->right,key);
	}
	else{
		//0 child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
			return root;
		}
		//1 child
		else if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		// 2 child
		else{
			Node* temp = findMin(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
		}
	}
	
	return root;
}

void Preorder(Node* root){
	if(root == NULL){
		return;
	}
	
	cout<<root->key<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root){
	if(root == NULL){
		return;
	}
	
	Inorder(root->left);
	cout<<root->key<<" ";
	Inorder(root->right);
}

void Postorder(Node* root){
	if(root == NULL){
		return;
	}
	
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->key<<" ";
}

void BFS(Node* root){
	if(root == NULL){
		return;
	}
	
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Node* current = q.front();
		q.pop();
		
		if(current == NULL){
			if(!q.empty()){
				cout<<"|";
				q.push(NULL);
			}
		}
		else{
			cout<<current->key<<",";
			
			if(current->left != NULL){
				q.push(current->left);
			}
			
			if(current->right != NULL){
				q.push(current->right);
			}
		}
	}
	
	cout<<"|";
}

int main(){
	Node* root = NULL;
	
	char c;
	int inp;
	
	while(true){
		cin >> c;
		if(c == 'a'){
			cin>>inp;
			root = insert(root,inp);
		}
		else if(c == 'd'){
			cin>>inp;
			root = deleteNode(root,inp);
		}
		else if(c == 'b'){
			BFS(root);
			cout<<endl;
		}
		else if(c == 'i'){
			Inorder(root);
			cout<<endl;
		}
		else if(c == 'p'){
			Preorder(root);
			cout<<endl;
		}
		else if(c == 't'){
			Postorder(root);
			cout<<endl;
		}
		else if(c == 'x'){
			return 0;
		}
	}
}
