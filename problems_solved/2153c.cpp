/**
 *    Author: Saksham Rathi
 *    Created: Fri Oct 10 22:59:00 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 3 && a[2] >= a[1] + a[0]) {
        cout << "0\n";
        return;
    }
    map<int, int> vals;
    for (auto x : a) vals[x]++;
    int perim = 0;
    set<int> dis;
    for (auto e : vals) {
        perim += (e.second / 2) * 2 * e.first;
        if (e.second & 1) dis.insert(e.first);
    }
    if (perim == 0) {
        cout << "0\n";
        return;
    }
    if (dis.size()) {
        perim += *dis.rbegin();
        dis.erase(prev(dis.end()));
    }
    if (dis.size()) {
        perim += *dis.rbegin();
        dis.erase(prev(dis.end()));
    }
    cout << perim << "\n";
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
