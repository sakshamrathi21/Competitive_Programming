/**
 *    Author: Saksham Rathi
 *    Created: Mon Jun 17 09:29:26 IST 2024
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
        vector<int> a(n), b(m);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < m ; i ++) {
            cin >> b[i];
        }
        vector<int> c;
        sort(b.begin(), b.end(), greater<int>());
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] > b[j]) {c.push_back(a[i]); i++;}
            else {
                c.push_back(b[j]);
                j++;
            }
        }
        while (i < n) {
            c.push_back(a[i]); i++;
        }
        while (j < m) {
            c.push_back(b[j]);
            j++;
        }

        for (int i = 0 ; i < n+m ; i ++) {
            cout << c[i] << " ";
        }
        cout << "\n";

    }
}
