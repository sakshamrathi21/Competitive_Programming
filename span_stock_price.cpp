#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    int prices[n];
    for (int i = 0; i<n; i++) {
        cin>>prices[i];
    }
    stack<int> spans;
    int series = 1;
    spans.push(series);
    for (int i = 1; i<n; i++) {
        if (prices[i]>=prices[i-1]) {
            series+=1;
            spans.push(series);
        }
        else {
            series = 1;
            spans.push(series);
        }
    }
    for (int i = 0; i<n; i++) {
        prices[n-1-i] = spans.top();
        spans.pop();
    }
    for (int i = 0; i<n; i++) {
        cout<<prices[i]<<" ";
    }
}