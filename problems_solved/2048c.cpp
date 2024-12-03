/**
 *    Author: Saksham Rathi
 *    Created: Mon Dec  2 16:42:03 IST 2024
**/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string t;
    cin >> s >> t;
    vector<int> f1(26, INT32_MAX), f2(26, -1);
    for (int i = 1 ; i < s.length() ; i ++){
        f1[s[i]-'a'] = min(i, f1[s[i]-'a']);
    }
    for (int i = 0 ; i < t.length()-1 ; i ++){
        f2[t[i]-'a'] = max(i, f2[t[i]-'a']);
    }
    int index = -1;
    for (int i = 0 ; i < 26 ; i ++) {
        if (f1[i] == INT32_MAX || f2[i] == -1) continue;
        if (index == -1) index = i;
        else {
            if (-f1[i]+f2[i]>-f1[index]+f2[index]) index = i;
        }
    }
    if (index == -1) {
        cout << "-1";
        exit(0);
    }
    for (int i = 0 ; i <= f1[index] ; i ++) {
        cout << s[i] ;
    }
    for (int i = f2[index]+1 ; i < t.length() ; i ++ ) {
        cout << t[i];
    }
}
