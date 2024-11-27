#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool parenMatch(string text) {
    stack<char> s;
    for (char c: text) {
        if (c == '{' or c == '[') s.push(c);
        if (c == '}' or c == ']') {
            if(s.empty()) return false;
            if (c-s.top() != 2) return false;
            s.pop();
        }
    }
    if (s.empty()) return true;
    return false;
}

int main() {
    string text;
    getline(cin, text);
    cout<<parenMatch(text);
}