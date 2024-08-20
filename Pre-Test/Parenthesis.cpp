#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Stack {
public:
    int topIndex = 0;
    char st[SIZE];

    bool empty() {
        return topIndex == 0;
    }

    bool full() {
        return topIndex == SIZE;
    }

    void push(char ch) {
        if (!full()) {
            st[topIndex] = ch;
            topIndex++;
        }
    }

    void pop() {
        if (!empty()) {
            topIndex--;
        }
    }

    char top() {
        return st[topIndex - 1];
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

int main() {
    Stack st;

    string inp;
    getline(cin, inp);
    int len = inp.length();
    int match = 0;
    bool ans = true;

    for (int i = 0; i < len; i++) {
        if (inp[i] == '(' || inp[i] == '[' || inp[i] == '{' || inp[i] == '<') {
            st.push(inp[i]);
        } else if (inp[i] == ')' || inp[i] == ']' || inp[i] == '}' || inp[i] == '>') {
            if (st.empty() || !isMatchingPair(st.top(), inp[i])) {
                ans = false;
                break;
            } else {
                if (inp[i] == '>') {
                    if (i + 1 < len && inp[i + 1] == '>') {
                        i++;
                        st.pop();
                    }
                }
                st.pop();
                match++;
            }
        }
    }

    if (ans && st.empty()) {
        cout << match << " matched";
    } else {
        cout << "Not matched" << endl << match << " matched";
    }
}
