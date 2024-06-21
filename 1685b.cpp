/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 21 21:13:24 IST 2024
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int n = s.length();
        bool path1 = false, path2 = false;
        {
            vector<bool> visited(n, false);
            int ca = 0, cb = 0;
            for (int i = 0 ; i < n-1 ; i ++) {
                if (visited[i] || visited[i+1]) continue;
                if (ca == c) break;
                if (s[i] == 'A' && s[i+1] == 'B') {
                    visited[i] = true;
                    visited[i+1] = true;
                    i++;
                    ca++;
                } 
            }
            for (int i = 0 ; i < n-1 ; i ++) {
                if (visited[i] || visited[i+1]) continue;
                if (cb == d) break;
                if (s[i] == 'B' && s[i+1] == 'A') {
                    visited[i] = true;
                    visited[i+1] = true;
                    i++;
                    cb++;
                } 
            }
            if (ca == c && cb == d) {
                int acnt = 0, bcnt = 0;
                for (int i = 0 ; i < n ; i ++) {
                    if (visited[i]) continue;
                    if (s[i] == 'A') acnt++;
                    else bcnt++;
                }
                if (acnt == a && bcnt == b) path1 = true;
            }
        }
        if (!path1) {
            vector<bool> visited(n, false);
            int ca = 0, cb = 0;
            for (int i = 0 ; i < n-1 ; i ++) {
                if (visited[i] || visited[i+1]) continue;
                if (cb == d) break;
                if (s[i] == 'B' && s[i+1] == 'A') {
                    visited[i] = true;
                    visited[i+1] = true;
                    i++;
                    cb++;
                } 
            }
            for (int i = 0 ; i < n-1 ; i ++) {
                if (visited[i] || visited[i+1]) continue;
                if (ca == c) break;
                if (s[i] == 'A' && s[i+1] == 'B') {
                    visited[i] = true;
                    visited[i+1] = true;
                    i++;
                    ca++;
                } 
            }
            if (ca == c && cb == d) {
                int acnt = 0, bcnt = 0;
                for (int i = 0 ; i < n ; i ++) {
                    if (visited[i]) continue;
                    if (s[i] == 'A') acnt++;
                    else bcnt++;
                }
                if (acnt == a && bcnt == b) path2 = true;
            }
        }
        if (path1 || path2) cout <<"YES\n";
        else cout << "NO\n";
    }
}