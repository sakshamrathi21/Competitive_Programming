#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int maxN = 2e5+1;
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int n;
    // cin >> n;
    // char c;
    // int i = 0;
    bitset<maxN> string_input;
    string s;
    cin >> s;
    for (int i = 0 ; i < s.length() ; i ++ ){
        if (s[i] == '1') string_input.set(i);
    } 
    // while (cin >> c) {
    //     cout << " hello world" << endl;
    //     if (c == '1') string_input.set(i);
    //     i ++;
    // }
    
    int n = s.length();
    
    // for (int i = 0 ; i < n ; i ++ ) {
    //     char c;
    //     cin >> c;
    //     if (c == '1') string_input.set(i);
    // }

    for (int k = 1 ; k <= n-1 ; k ++ ) {
        cout << (string_input & (string_input << k)).count() << " ";
    }
}
