/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 27 11:17:11 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1000000007;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> p(n+1, 0);
        for (int i = 0 ; i < n ; i ++) {
            if (s[i] == '0') {
                p[i+1] = p[i]-1;
            }
            else p[i+1] = p[i]+1;
        }
        map<int, vector<int>> ind;
        vector<int> a;
        for (int i = 0 ; i <= n;  i ++) {
            if (ind.find(p[i]) == ind.end()) {
                ind[p[i]] = a;
                ind[p[i]].push_back(i);
            }
            else ind[p[i]].push_back(i);
        }
        int res = 0;
        for (auto e : ind) {
            if (e.second.size() == 1) continue;
            int sum = 0;
            for (int i = 1 ; i < e.second.size() ; i ++) {
                sum += (n-e.second[i]+1);
                sum %= MOD;
            }
            for (int i = 0 ; i < e.second.size()-1 ; i ++) {
                res += ((e.second[i]+1)*sum%MOD);
                res %= MOD;
                sum -= (n-e.second[i+1]+1);
                while (sum < 0) sum += MOD;
                sum %= MOD;
            }
        }
        cout << res%MOD << "\n";
    }
}
