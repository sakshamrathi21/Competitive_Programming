/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 09:23:32 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string m;
        for (int i = 0 ; i < k ; i ++ ) m.push_back('z');
        for (int i = 1 ; i <= n ; i ++ ) {
            string curr;
            for (int j = 0 ; j < i ; j ++) curr.push_back(s[j]);
            while (curr.length() < k) curr += curr;
            while (curr.length() > k) curr.pop_back();
            m = min(m, curr);
        }
        cout << m << "\n";
    }
}
