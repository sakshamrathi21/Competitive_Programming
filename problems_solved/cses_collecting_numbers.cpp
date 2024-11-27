#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int prev = a[0].second;
    int cnt = 1;
    for (int i = 1 ; i < n ; i ++) {
        if (a[i].second < prev) {
           cnt++; 
        }
        prev = a[i].second;
    }
    cout << cnt;

}
