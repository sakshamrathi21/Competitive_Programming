/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug 22 10:34:10 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < m ; i ++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> prefa(n + 1, 0), prefb(m + 1, 0);
    for (int i = 1 ; i <= n ; i ++) prefa[i] += prefa[i-1] + a[i - 1];
    for (int i = 1 ; i <= m ; i ++) prefb[i] += prefb[i-1] + b[i - 1];
    int ai = 0, bi = 0;
    vector<int> zv(m + n + 1, 0);
    while (true) {
        zv[ai + bi] = ai;
        if (ai < n && bi < m) {
            if (a[ai] > b[bi]) ai++;
            else bi++;
        }
        else if (ai < n) ai++;
        else if (bi < m) bi++;
        else break;
    }
    zv[m + n] = n;
    while(q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int sum = 0;
        // cout << x << " " << zv[z] << " hello " <<endl;
        if (zv[z] >= x) {
            sum += prefa[x];
            sum += prefb[z - x];
        }
        else {
            int count = 0;
            sum += prefa[zv[z]];
            count += zv[z];
            sum += prefb[min(z - zv[z], y)];
            count += min(z - zv[z], y);
            if (count < z) {
                // cout << count << " " << z << " check " << endl;
                sum -= prefa[zv[z]];
                sum += prefa[z - y];
            }
        }
        cout << sum << "\n";
    }
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
