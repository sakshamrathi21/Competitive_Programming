#include<bits/stdc++.h>
using namespace std;

int main () {
    int array_size;
    cin >> array_size;
    if (array_size == 0) return 0;
    vector<int> array_integers(array_size);
    for (int i = 0 ; i < array_size ; i ++ ) {
        cin >> array_integers[i];
    }

    vector<int> answer(array_size);
    stack<int> sorted_stack;
    sorted_stack.push(0);
    answer[0] = 0;

    for (int i = 1 ; i < array_size ; i ++ ) {
        if (array_integers[sorted_stack.top()] < array_integers[i]) {
            answer[i] = sorted_stack.top() + 1;
            sorted_stack.push(i);
            continue;
        }
        while (!sorted_stack.empty() && array_integers[sorted_stack.top()] >= array_integers[i]) {
            sorted_stack.pop();
        }
        if (sorted_stack.empty()) {
            answer[i] = 0;
        }
        else {
            answer[i] = sorted_stack.top() + 1;
        }
        sorted_stack.push(i);
    }
    for (int i = 0 ; i < array_size ; i ++ ) {
        cout << answer[i] << " ";
    }

}