/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul  2 10:34:31 IST 2024
**/

#include<iostream>
#include<vector>
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
        int w, m;
        cin >> w >> m;
        vector<int> prefix_sums(s.length()+1);
        int n = s.length();
        prefix_sums[0] = 0;
        for (int i = 0 ; i < n ; i ++) {
            prefix_sums[i+1] = (prefix_sums[i]+s[i]-'0'+9)%9;
        }
        vector<int> wdiff(n-w+1);
        for (int i = 0 ; i < n-w+1 ; i ++) {
            wdiff[i] = (prefix_sums[i+w]-prefix_sums[i]+9)%9;
        }
        vector<vector<int> > h(9, vector<int>(2, -1));
        for (int i = 0 ; i < n-w+1 ; i ++) {
            if (h[wdiff[i]][0]  == -1) h[wdiff[i]][0] = i;
            else if (h[wdiff[i]][1]  == -1) h[wdiff[i]][1] = i;
        }
        while (m--) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            int v = (prefix_sums[r+1]-prefix_sums[l]+9)%9;
            int l1 = LLONG_MAX, l2 = LLONG_MAX;
            for (int a = 0 ; a < 9 ; a ++) {
                int b = (k-v*a+81)%9;
                if (a == b) {
                    if (h[a][0] != -1 && h[a][1] != -1) {
                        if (l1 > h[a][0]) {
                            l1 = h[a][0];
                            l2 = h[a][1];
                        }
                        else if (l1 == h[a][0]) l2 = min(l2, h[a][1]);
                    }
                }
                else {
                    if (h[a][0] != -1 && h[b][0] != -1) {
                        if (l1 > h[a][0]) {
                            l1 = h[a][0];
                            l2 = h[b][0];
                        }
                        else if (l1 == h[a][0]) l2 = min(l2, h[b][0]);
                    }
                }
            }
            if (l1 == LLONG_MAX || l2 == LLONG_MAX) cout << "-1 -1\n";
            else cout << l1+1 << " " << l2+1 << "\n";
        }

    }
}
