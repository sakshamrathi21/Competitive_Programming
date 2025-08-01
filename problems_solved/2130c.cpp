/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  1 09:31:10 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> ab[i].first >> ab[i].second;
    }
    vector<int> fab;
    for (int i = 0 ; i < n ; i ++) {
        bool found = false;
        for (int j = 0 ; j < n ; j ++) {
            if (i != j && ab[i].first >= ab[j].first && ab[i].second <= ab[j].second) found = true;
        }
        if (!found) fab.push_back(i);
    }
    cout << fab.size() << "\n";
    for (int i = 0 ; i < fab.size() ; i ++) cout << fab[i] + 1 << " ";
    cout << "\n";
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
