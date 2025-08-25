/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 25 11:40:25 IST 2025
**/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    map<int, vector<int>> layers;
    int n;
    cin >> n;
    int big = -1;
    vector<int> path;

    for (int i = 0; i < n; i++) {
        cout << "? " << i + 1 << " " << n << " ";
        for (int j = 1; j <= n; j++) {
            cout << j << (j == n ? '\n' : ' ');
        }
        cout.flush();

        int ans;
        cin >> ans;
        layers[ans].push_back(i + 1);

        if (ans > big) {
            big = ans;
            path = {i + 1};
        }
    }

    for (int d = big - 1; d > 0; d--) {
        for (int candidate : layers[d]) {
            cout << "? " << path.back() << " 2 " << path.back() << " " << candidate << "\n";
            cout.flush();

            int ans;
            cin >> ans;
            if (ans == 2) {
                path.push_back(candidate);
                break;
            }
        }
    }

    cout << "! " << path.size();
    for (int node : path) {
        cout << " " << node;
    }
    cout << "\n";
    cout.flush();
}

signed main() {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
