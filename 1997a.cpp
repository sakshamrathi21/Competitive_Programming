/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul 30 20:41:54 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int, string> s_m(string s, int pos, char c) {
    s.insert(s.begin()+pos, c);
    int cost = 2;
    for (int i = 1 ; i < s.length() ; i ++) {
        if (s[i] == s[i-1]) cost +=1;
        else cost += 2;
    } 
    return make_pair(cost, s);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int m = -1;
        string ms;
        for (int i = 0 ; i < 26 ; i ++) {
            for (int j = 0 ; j <= n ; j ++) {
                pair<int, string> ch = s_m(s, j, 'a'+i);
                if (ch.first > m) {
                    m = ch.first;
                    ms = ch.second;
                }
            }
        }
        cout << ms << "\n";
    }
}
