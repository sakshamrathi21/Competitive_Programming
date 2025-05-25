/**
 *    Author: Saksham Rathi
 *    Created: Sun May 25 20:25:26 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool check(vector<vector<pair<int, int>>> &out_edges, int mid, vector<int> &b, int m)
{
    int n = out_edges.size();
    vector<int> dp(n, -1e16);
    dp[0] = 0;
    for (int i = 0 ; i < n ; i ++)
    {   
        dp[i] += b[i];
        dp[i] = min(dp[i], mid);
        for (int j = 0 ; j < out_edges[i].size() ; j ++)
        {
            if (dp[i] < out_edges[i][j].second) continue;
            dp[out_edges[i][j].first] = max(dp[out_edges[i][j].first], dp[i]);
        }
    }
    return (dp[n - 1] > 0); 
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> b[i];
    }
    int s, t, w;
    vector<vector<pair<int, int>>> out_edges(n);
    for (int i = 0 ; i < m ; i ++) {
        cin >> s >> t >> w;
        out_edges[s - 1].push_back(make_pair(t - 1, w));
    }
    int left = 0, right = 1e17;
    while (left < right)
    {
        // cout << " helo " << left << right << endl;
        if (right - left <= 2)
        {
            if (check(out_edges, left, b, m)) break;
            if (check(out_edges, left + 1, b, m)) 
            {
                left++;
                break;
            }
            if (check(out_edges, right, b, m)) 
            {
                left = right;
                break;
            }
        }
        int mid = (left + right)/2;
        if (check(out_edges, mid, b, m)) 
        {
            right = mid + 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    if (left == 1e17) cout << -1 << "\n";
    else cout << left << "\n";
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
