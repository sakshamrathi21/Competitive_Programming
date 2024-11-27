/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 17:04:40 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string s1, s2;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (i%2) s1.push_back(s[i]);
            else s2.push_back(s[i]);
        }
        if (s1.empty()) {
            
            cout << stoi(s2) - 1 << "\n";
        }
        else {
            // cout << " hello " << s1 << endl;
            cout << (stoi(s1) + 1 )*(stoi(s2) + 1 )-2 << "\n";
        }
    }
}
