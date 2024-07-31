#include <iostream>
#include <string>
using namespace std;

class Queue{
	public:
		int Array[100];
		int size = 99;
		int front = 0;
		int back = -1;
		
		bool empty()
		{
			if(front > back)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		bool full()
		{
			if(back == size)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		void enqueue(int data)
		{
			if(!full())
			{
				back++;
				Array[back] = data;
			}
		}
		
		int dequeue()
		{
			if(!empty())
			{
				int temp = Array[front];
				front++;
				return temp;
			}
		}
		
		void print()
		{
			for(int i = front;i <= back;i++)
			{
				cout<<Array[i]<<" ";
			}
			cout<<endl;
		}
		
		int s()
		{
			int n = 0;
			for(int i = front;i <= back;i++)
			{
				n++;
			}
			return n;
		}
		
		void showData()
		{
			cout<<Array[front]<< " " << Array[back] << endl;
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
  		if(!q.full())
		{
  			q.enqueue(num);
		}
		else
		{
			cout<<"Full Queue"<<endl;
		}
	  }
	  
	if(input == "d")
	{
		if(q.s() != 0){
			cout<<q.dequeue()<<endl;
		}
		else
		{
			cout<<"Empty Queue"<<endl;
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
