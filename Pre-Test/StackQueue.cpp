#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Data {
public:
    int num;
    int arrival;
    int serval;
};

int main() {
    int round = 0;
    cin >> round;

    stack<Data> myStack;
    vector<Data> arr(round);
    int count = 0;

    for (int i = 0; i < round; i++) {
        cin >> arr[i].num;
        cin >> arr[i].arrival;
        cin >> arr[i].serval;
    }

    sort(arr.begin(), arr.end(), [](const Data &a, const Data &b)) {
        return a.arrival < b.arrival;
    };

    int nextnum = arr[0].num;
    int nextServal = arr[0].serval;
for (int i = 0; i < round; i++) {
        for (int j = 0; j < nextServal; j++) {
            count++;
            for (int k = i; k < arr.size(); k++) {
                if (count == arr[k].arrival) {
                    myStack.push(arr[k]);
                }
            }
            cout << nextnum << ":" << nextServal - j << endl;
        }
        if (!myStack.empty()) {
            nextnum = myStack.top().num;
            nextServal = myStack.top().serval;
            myStack.pop();
        }
    }

    return 0;
}
