#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main(){
  stack<char> st;

  string inp;
  char ch;
  getline(cin,inp);
  int len = inp.length();
  int ans = 1;
  int match = 0;

  for(int i = 0 ;i<len;i++){

    if(inp[i] == '(' || inp[i] == '[' || inp[i] == '{' || inp[i] == '<'){
      st.push(inp[i]);
    }

    if(inp[i] == ')'){
      if(st.empty()){
        ans = 0;
        break;
      }
      else{
        if(st.top() == '('){
          st.pop();
          match++;
        }
      }
    }

    if(inp[i] == ']'){
      if(st.empty()){
        ans = 0;
        break;
      }
      else{
        if(st.top() == '['){
          st.pop();
          match++;
        }
      }
    }

    if(inp[i] == '}'){
      if(st.empty()){
        ans = 0;
        break;
      }
      else{
        if(st.top() == '{'){
          st.pop();
          match++;
        }
      }
    }

    if(inp[i] == '>'){
      if(st.empty()){
        ans = 0;
        break;
      }
      else if(inp[i + 1] == '>'){
        for(int j = 0;j<2;j++){
          if(st.top() == '<'){
            st.pop();
          }
        }
        i++;
        match++;
      }
      else{
        if(st.top() == '<'){
          st.pop();
          match++;
        }
      }
    }
  }

  int valid = ans && st.empty();
	
	  if(valid){
		  cout<<match<<" matched";
	  }
	  else{
		  cout<<"Not matched"<<endl<<match<<" matched";
	}
}

/*
input
(((20+5)+61
(20+[30 - 40<int> + 50] - a[40]{})
>20(30{40[20]})<
<<a+<int>b+c[40-{50+60(20)}]-<int>+b>>
a+b-<<c+d<<-f({d[30]})>>
*/

/*
Output

Not matched
1 matched

5 matched

Not matched
0 matched

6 matched

Not matched
4 matched
*/
