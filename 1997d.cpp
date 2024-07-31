/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul 31 08:09:33 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int inf = 2e15;

bool dfs(vector<vector<int>>&adj, vector<int>&a, int node, int val) {
    if (adj[node].size() == 0) {
        if (a[node] < val) return false;
        return true;
    }
    if (node == 0) val = max(0LL, val-a[node]);
    else if (a[node] < val) val = min(inf, val+val-a[node]);
    for (int u : adj[node]) if (!dfs(adj, a, u, val)) return false;
    return true;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 1 ; i < n ; i ++) {
            int x;
            cin >>x;
            x--;
            adj[x].push_back(i);
        }
        int low = 0, high = 1e15;
        while (high-low > 1) {
            int mid = (low+high)/2;
            if (dfs(adj, a, 0, mid)) low = mid;
            else high = mid;
        }
        cout << low << "\n";
    }
}
