#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            cin >> dp[i][j];

    vector<int> x(n);
    for (int i = 0 ; i < n ; i++) cin >> x[i];

    vector<int> result;
    vector<bool> added(n, false);

    reverse(x.begin(), x.end());

    for (int idx = 0; idx < n; ++idx) {
        int k = x[idx] - 1;
        added[k] = true;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            if (!added[i]) continue;
            for (int j = 0 ; j < n ; j++) {
                if (!added[j]) continue;
                sum += dp[i][j];
            }
        }
        result.push_back(sum);
    }

    reverse(result.begin(), result.end());
    for (int val : result) cout << val << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
