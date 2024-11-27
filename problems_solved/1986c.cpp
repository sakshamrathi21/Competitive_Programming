/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 23 19:43:38 IST 2024
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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ind(m);
        for (int i = 0 ; i < m ; i ++) cin >> ind[i];
        vector<char> c(m);
        for (int i = 0 ; i < m ; i ++) cin >> c[i];
        sort(ind.begin(), ind.end());
        vector<int> uniq;
        uniq.push_back(ind[0]);
        for (int i = 1 ; i < m ; i ++) {
            if (ind[i] == ind[i-1]) continue;
            uniq.push_back(ind[i]);
        }
        sort(c.begin(), c.end());
        // s[ind[0]] = c[0];
        // for (int i = 0 ; i < m ; i++) cout << c[i];
        // cout << endl << uniq.size() << endl;
        for (int i = 0 ; i < uniq.size() ; i ++) {
            s[uniq[i]-1] = c[i];
        }
        // cout << "hello " << uniq[0] << c[0] << endl;
        cout << s << "\n";
    }
}
