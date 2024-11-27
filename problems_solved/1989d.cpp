/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 27 21:21:44 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int binSearch(vector<pair<int, int>> &d, int val, int low, int high) {
    if ((high-low) <= 1) {
        if (high < d.size() && d[high].first <= val) return high;
        if (d[low].first <= val) return low;
        return -1;
    }
    int mid = (low+high)/2;
    if (d[mid].first <= val) return binSearch(d, val, mid, high);
    return binSearch(d, val, low, mid);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    int mx = -1;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        mx = max(m, a[i]);
    }
    for (int i = 0 ; i < n ; i ++) {
        cin >> b[i];
    }
    vector<int> best(mx+1, LLONG_MAX);
    for (int i = 0 ; i < n ; i ++) {
        best[a[i]] = min(best[a[i]], a[i]-b[i]);
    }
    for (int i = 1 ; i <= mx ; i ++) {
        best[i] = min(best[i], best[i-1]);
    }
    int cnt = 0;
    for (int i = 0 ; i < m ; i ++) {
        int c;
        cin >> c;
        
    }
}
