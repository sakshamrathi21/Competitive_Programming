/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 17 08:40:52 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
vector<pair<int, pair<int, int>>> posd, posi;

void pre() {
    for (int z = 0 ; z < 400 ; z ++ ) {
        for (int x = 0 ; x <= z ; x ++) {
            int y = z - x;
            int d = 3*x + 3*y;
            posd.push_back(make_pair(d + 2, make_pair(3*x + 1, 3*y + 1)));
            posi.push_back(make_pair(d + 2, make_pair(3*x + 1, 3*y + 1)));
            posd.push_back(make_pair(d + 3, make_pair(3*x + 1, 3*y + 2)));
            posd.push_back(make_pair(d + 3, make_pair(3*x + 2, 3*y + 1)));
            posd.push_back(make_pair(d + 6, make_pair(3*x + 2, 3*y + 2)));
        }
    }
    sort(posd.begin(), posd.end());
    sort(posi.begin(), posi.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    set<pair<int, int>> rem;
    int idx1 = 0, idx2 = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (a[i]) {
            while (rem.find(posd[idx1].second) != rem.end()) idx1++;
            auto pos = posd[idx1++];
            cout << pos.second.first << " " << pos.second.second << "\n";
            if (pos.first % 3 == 2) idx2 ++;
        }
        else {
            auto pos = posi[idx2++];
            rem.insert(pos.second);
            cout << pos.second.first << " " << pos.second.second << "\n";
        }
    }
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
}
