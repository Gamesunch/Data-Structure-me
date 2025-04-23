#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	stack<int> st;
	string inp;
	getline(cin,inp);
	int len = inp.length();
	
	for(int i = 0 ;i<len;i++){
		if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' ){
			int x2 = st.top();st.pop();
			int x1 = st.top();st.pop();
			int ans;
			if(inp[i] == '+'){
				ans = x1+x2;
			}
			else if(inp[i] == '-'){
				ans = x1-x2;
			}
			else if(inp[i] == '*'){
				ans = x1*x2;
			}
			else if(inp[i] == '/'){
				ans = x1/x2;
			}
			
			st.push(ans);
		}
		else{
			st.push(inp[i] - '0');
		}
	}
	
	cout<<st.top();
}
