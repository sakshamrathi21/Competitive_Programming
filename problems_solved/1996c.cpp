/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 27 10:05:45 IST 2024
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
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<int> f(26, 0);
        vector<vector<int>> freqA, freqB;
        freqA.push_back(f);
        for (int i = 0 ; i < n ; i ++) {
            f[a[i]-'a']++;
            freqA.push_back(f);
        }

        f.assign(26, 0);
        freqB.push_back(f);
        for (int i = 0 ; i < n ; i ++) {
            f[b[i]-'a']++;
            freqB.push_back(f);
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            int diff = 0;
            for (int i = 0 ; i < 26 ; i ++) {
                diff += abs(freqB[r][i]-freqB[l][i]-freqA[r][i]+freqA[l][i]);
            }
            cout << diff/2 << "\n";
        }
    }
}
