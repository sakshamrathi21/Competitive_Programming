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
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < n ; i ++) {
        cin >> b[i];
    }
    for (int i = 0 ; i < m ; i ++) {
        cin >> c[i];
    }
    vector<pair<int, int>> d(n);
    for (int i = 0 ; i < n ; i ++){
        d[i].first = a[i];
        d[i].second = a[i] - b[i];
    }
    sort(d.begin(), d.end());
    vector<int> diff(n);
    int min_diff = LLONG_MAX, min_in = -1;
    for (int i = 0 ; i < n ; i ++) {
        if (d[i].second < min_diff) {
            min_diff = d[i].second;
            min_in = i;
        }
        diff[i] = min_in;
    }
    int cnt = 0;
    for (int i = 0 ; i < m ; i ++) {
        int val = c[i];
        while (true) {
            int ind = binSearch(d, val, 0, n);
            if (ind == -1) break;
            int mo = (val - d[diff[ind]].first)/d[diff[ind]].second+1;
            val -= mo*d[diff[ind]].second;
            cnt += mo;
        }
    }
    cout << cnt*2 << "\n";
}
