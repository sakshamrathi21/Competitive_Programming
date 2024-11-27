/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 18 22:39:01 IST 2024
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
        int n;
        cin >> n;
        map<string, int> d;
        bool poss = false;
        for (int i = 0 ; i < n ; i ++) {
            string s;
            cin >> s;
            if (poss) continue;
            if (s.length() == 1){
                poss = true;
                continue;
            }
            string t = s;
            reverse(t.begin(), t.end());
            if (s.length() == 2) {
                if (s[0] == s[1]) {
                    poss = true;
                    continue;
                }
                if (d[t] != 0) {
                    poss = true;
                    continue;
                }
                string r = t + "*";
                if (d[r] != 0) {
                    poss = true;
                    continue;
                }
            }
            else {
                if (s[0] == s[2]) {
                    poss = true;
                    continue;
                }
                if (d[t] != 0) {
                    poss = true;
                    continue;
                }
                string r = "";
                r.push_back(s[2]);
                r.push_back(s[1]);
                if (d[r] != 0) {
                    poss = true;
                    continue; 
                }
                // r.push_back('*');
                // if (d[r] != 0) {
                //     poss = true;
                //     continue;
                // }
            }
            if (s.length() == 2) {
                d[s] ++;
            }
            else {
                d[s]++;
                s[2] = '*';
                d[s]++;
            }
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";

    }
}
