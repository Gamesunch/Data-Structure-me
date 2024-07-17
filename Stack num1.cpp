#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<char> st;
	
	string inp;
	char ch;
	
	cin>>inp;
	
	int s = inp.length();
	int ans = 0;
	
	for(int i = 0;i<s;i++){
		ch = inp[i];
		if(ch == '('){
			st.push(ch);
		}
		else if(ch == ')'){
			if(st.empty()){
				ans = 0;
				break;
			}
			else{
				ans++;
				st.pop();
			}
		}
	}
	
	int valid = ans && st.empty();
	
	if(valid){
		cout<<"Pass"<<endl;
	}
	else{
		cout<<"Error"<<endl;
	}
	
}
