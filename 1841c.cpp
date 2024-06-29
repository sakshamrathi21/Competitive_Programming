/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 29 15:59:45 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

using TupleKey = std::tuple<int, int, int>;

map<TupleKey, int> dp;

int getOrDefault(const std::map<TupleKey, int>& m, const TupleKey& key) {
    auto it = m.find(key);
    if (it != m.end()) {
        return it->second;
    } 
    return -1;
}

int d (string&s, int i, int j, int k) {
    if (i >= s.length()) return 0;
    // j = max(j, (int)(s[i]-'A'));
    TupleKey t = make_tuple(i, j, k);
    int ans = getOrDefault(dp, t);
    if (ans != -1) return ans;
    // cout << " hello " << i << " " << j << " " << k << endl;
    int m = -1;
    if (k == 1) {
        if (j > s[i]-'A') {
            m = -pow(10, s[i]-'A')+ d(s, i+1, j, k);
        }
        else m = pow(10, s[i]-'A') + d(s, i+1, max(j, (int)(s[i]-'A')), k);
    }
    else {
        if (j > s[i]-'A') {
            m = -pow(10, s[i]-'A')+ d(s, i+1, j, k);
        }
        else m = pow(10, s[i]-'A') + d(s, i+1, max(j, (int)(s[i]-'A')), k);
        if (j > 0) m = max(m, -(int)pow(10, 0) + d(s, i+1, max(j, 0LL), 1));
        else m = max(m, (int)pow(10, 0) + d(s, i+1, max(j, 0LL), 1));
        if (j > 1) m = max(m, -(int)pow(10, 1) + d(s, i+1, max(j, 1LL), 1));
        else m = max(m, (int)pow(10, 1) + d(s, i+1, max(j, 1LL), 1));
        if (j > 2) m = max(m, -(int)pow(10,2) + d(s, i+1, max(j, 2LL), 1));
        else m = max(m, (int)pow(10, 2) + d(s, i+1, max(j, 2LL), 1));
        if (j > 3) m = max(m, -(int)pow(10, 3) + d(s, i+1, max(j, 3LL), 1));
        else m = max(m, (int)pow(10, 3) + d(s, i+1, max(j, 3LL), 1));
        m = max(m, (int)pow(10, 4) + d(s, i+1, max(j, 4LL), 1));
    }
    return dp[t] = m;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        dp.clear();
        reverse(s.begin(), s.end());
        cout << d(s, 0, 0, 0) << "\n";
    }
}
