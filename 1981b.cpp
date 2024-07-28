/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 11:18:12 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> binForm(int x) {
    vector<int> rs;
    while (x > 0) {
        rs.push_back(x%2);
        x /= 2;
    }
    // reverse(rs.begin(), rs.end());
    return rs;
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << n << "\n";
            continue;
        }
        vector<int> bf = binForm(n);
        vector<int> res(31);
        for (int i = 0 ; i < 31 ; i ++) {
            if ( i < bf.size() ) res[i] = bf[i];
            if (res[i]) continue;
            if ((1<<i) < n) {
                if (min(n-n/(1<<i)*(1<<i), (n/(1<<i)+1)*(1<<i)-n) <= m) res[i] = 1;
            }
            else if ((n/(1<<i)+1)*(1<<i)-n <= m) res[i] = 1;
        }
        int r = 0;
        for (int i = 0 ; i < 31 ; i ++) r += (1<<i)*res[i];
        cout << r << "\n";
    }
}
