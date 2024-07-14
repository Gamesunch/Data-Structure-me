#include <iostream>
#include <stack>
#include <string>

using namespace std;


class stack1
{
	public:
		int s = 0;
		int arr[100];
		
		void push(int x){
			if(s >= 99){
				cout<<"Can't Push"<<endl;
				return;
			}
			
			arr[s] = x;
			s++;
		}
		
		int top()
		{
			return arr[s - 1];
		}
		
		int size()
		{
			return s;
		}
		
		void pop()
		{
			if(s > 0){
				s--;	
			}
			else{
				cout<<"Empty Stack"<<endl;
			}
		}
};

int main(){
	
	string input;
	stack1 st1;
	
	while(true)
	{
		cin >> input;
		
		if(input == "U"){
			int num;
			cin >> num;
			st1.push(num);
		}
		
		if(input == "O"){
			cout << st1.top() << endl;
			st1.pop();
		}
		
		if(input == "T"){
			cout <<st1.top() << endl;
		}
		
		if(input == "P"){
			int si = st1.size();
			if(si <= 0){
				cout<<"Empty Stack";
				}
			else{
				for(int i = 0 ;i < si;i++){
					cout << st1.arr[i] << " ";
					}
			}
			cout<<endl;
			}
		
		if(input == "N"){
			cout<<st1.size()<<endl;
		}
		
		if(input == "X"){
			break;
		}
	}
	
	return 0;
}
