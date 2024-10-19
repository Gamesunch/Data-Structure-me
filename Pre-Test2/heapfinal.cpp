#include <iostream>

using namespace std;

class Maxheap{
	private:
		int heap[100];
		int size = 0;
		
		int parent(int i){
			return (i-1)/2;
		}
		
		int leftChild(int i){
			return (2*i) + 1;
		}
		
		int rightChild(int i){
			return (2*i) + 2;
		}
		
		void heapifyUp(int i){
			while(i > 0 && heap[i] > heap[parent(i)]){
				swap(heap[i],heap[parent(i)]);
				i = parent(i);
			}
		}
		
		void heapifyDown(int i){
			int largest = i;
			int left = leftChild(i);
			int right = rightChild(i);
			
			if(left < size && heap[left] > heap[largest]){
				largest = left;
			}
			
			if(right < size && heap[right] > heap[largest]){
				largest = right;
			}
			
			if(largest != i){
				swap(heap[i],heap[largest]);
				heapifyDown(largest);
			}
		}
		
	public:
		
		void insert(int value){
			heap[size] = value;
			size++;
			heapifyUp(size - 1);
		}
		
		int deleteMax(){
			
			if(size == 0){
				return 0;
			}
			
			int temp = heap[0];
			heap[0] = heap[size - 1];
			size--;
			heapifyDown(0);
			return temp;
		}
		
		void print(){
			for(int i = 0;i<size;i++){
				cout<<heap[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	Maxheap heap;
	char c;
	int val;
	
	while(true){
		cin>>c;
		if(c == 'a'){
			cin>>val;
			heap.insert(val);
		}
		else if(c == 'd'){
			cout<<heap.deleteMax()<<endl;
		}
		
		else if(c == 'p'){
			heap.print();
		}
		
		else if(c == 'e'){
			return 0;
		}
	}
}
