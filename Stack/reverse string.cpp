#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	stack<char> st;
	string inp;
	getline(cin,inp);
	
	int len = inp.length();
	
	for(int i = 0 ;i<len;i++){
		st.push(inp[i]);
	}
	
	for(int i = 0 ;i<len;i++){
		inp[i] = st.top();
		st.pop();
	}
	
	cout<<inp;
}
