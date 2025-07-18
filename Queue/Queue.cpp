#include <iostream>
#include <string>
using namespace std;

class Queue{
	public:
		int Array[4];
		int size = 4;
		int head = 0;
		int tail = -1;
		
		bool full(){
			// can use (head % size) + (tail % size) + 1 == size
			// instead of function for loop that increase performance from O(n) to O(1)
			return s() == size;
		}
		
		bool empty(){
			return s() == 0;
		}
		
		void enqueue(int data)
		{
			if(!full()){
				tail++;
				Array[tail%size] = data;
			}
			else{
				cout<<"FULL!!!"<<endl;
			}
			
		}
		
		int dequeue()
		{
			if(!empty()){
				int temp = head;
				head++;
				return Array[temp%size];
			}
			else{
				cout<<"EMPTY!!!"<<endl;
			}
			
			
		}
		
		void print()
		{
			int n = 0;
			for(int i = head;i <= tail;i++)
			{
				cout<<Array[i%size]<<" ";
			}
			cout<<endl;
		}
		
		int s()
		{
			int n = 0;
			for(int i = head;i <= tail;i++)
			{
				n++;
			}
			return n;
		}
		
		void showData()
		{
			cout<<Array[head%size]<< " " << Array[tail%size] << endl;
		}
};

int main(){
  string input;
  Queue q;
  
  while(true)
  {
  	cin >> input;
  	if(input == "e")
	  {
  		int num;
  		cin >> num;
  		q.enqueue(num);
		
	  }
	  
	if(input == "d")
	{
		if(q.s() != 0){
			cout<<q.dequeue()<<endl;
		}
		else{
			cout<<"EMPTY!!!"<<endl;
		}
	}
	
	if(input == "p")
	{
		q.print();
	}
	
	if(input == "n")
	{
		cout<<q.s()<<endl;
	}
	
	if(input == "s")
	{
		q.showData();
	}
	
	if(input == "x")
	{
		break;
	}
  }
  
  return 0;
}
