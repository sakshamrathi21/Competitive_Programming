#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<int, int> x, pair<int, int> y) {
    return x.first < y.first;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> a[n], b[n], c[n];
        for (int i = 0 ; i < n ; i ++) {cin >> a[i].first; a[i].second = i;}
        for (int i = 0 ; i < n ; i ++) {cin >> b[i].first; b[i].second = i;}
        for (int i = 0 ; i < n ; i ++) {cin >> c[i].first; c[i].second = i;}
        sort(a, a+n, compare);
        sort(b, b+n, compare);
        sort(c, c+n, compare);
        int max_k = -1;
        for (int i = n - 1 ; i >= n-3 ; i --) {
            for (int j = n - 1 ; j >= n -3 ; j --) {
                for (int k = n - 1 ; k >= n - 3 ; k --) {
                    if (a[i].second == b[j].second || a[i].second == c[k].second || c[k].second == b[j].second) continue;
                    max_k = max(a[i].first+b[j].first+c[k].first, max_k);
                }
            }
        }
        cout << max_k << "\n";
    }
}
