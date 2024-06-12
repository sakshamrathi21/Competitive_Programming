#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<int, int>> b = a;
    sort(a.begin(), a.end());
    int prev = a[0].second;
    int cnt = 1;
    for (int i = 1 ; i < n ; i ++) {
        if (a[i].second < prev) {
           cnt++; 
        }
        prev = a[i].second;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        
    }
}
