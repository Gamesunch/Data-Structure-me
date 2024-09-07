#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool ismatch(char open, char close){
	return 	(open == '(' && close == ')')||
			(open == '[' && close == ']')||
			(open == '<' && close == '>')||
			(open == '{' && close == '}');
}

int main(){
	stack<char> st;
	string inp;
	getline(cin,inp);
	int len = inp.length();
	int match = 0;
	bool ans = true;
	
	for(int i = 0;i<len;i++){
		if(inp[i] == '(' || inp[i] == '{' || inp[i] == '<' || inp[i] == '['){
			st.push(inp[i]);
		}
		else if(inp[i] == ')' || inp[i] == '}' || inp[i] == '>' || inp[i] == ']'){
			if(st.empty() || !ismatch(st.top(),inp[i])){
				ans = false;
				break;
			}
			else if(inp[i] == '>'){
				if(i+1 < len && inp[i+1] == '>'){
					st.pop();
					i++;
				}
			}
			match++;
			st.pop();
		}
	}
	
	if(ans && st.empty()){
		cout<<match<<" matched"<<endl;
	}
	else{
		cout<<"Not matched"<<endl<<match<<" matched"<<endl;
	}
}
