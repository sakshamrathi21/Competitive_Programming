/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 16 23:36:58 IST 2025
**/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> rowSum(n, vector<int>(m+1, 0));
    vector<vector<int>> colSum(n+1, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rowSum[i][j+1] = rowSum[i][j] + (a[i][j] == '1');
            colSum[i+1][j] = colSum[i][j] + (a[i][j] == '1');
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0') continue;

            if (i == 0 || j == 0) continue;

            bool ok = false;
            if (rowSum[i][j+1] == j+1) ok = true;
            if (colSum[i+1][j] == i+1) ok = true;
            if (!ok) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
