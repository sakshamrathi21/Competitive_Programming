/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun  5 10:21:21 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<pair<int, int>, int> p(int a, int b, int c) {
    return make_pair(make_pair(a, b), c);
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
        map<pair<pair<int, int>, int>, int> mp;
        int tp = 0;
        for (int i = 0 ; i < n-2 ; i ++) {
            tp += mp[p(0, a[i+1], a[i+2])] - mp[p(a[i], a[i+1], a[i+2])];
            tp += mp[p(a[i], 0, a[i+2])] - mp[p(a[i], a[i+1], a[i+2])];
            tp += mp[p(a[i], a[i+1], 0)] - mp[p(a[i], a[i+1], a[i+2])];
            mp[p(a[i], a[i+1], 0)]++;
            mp[p(a[i], 0, a[i+2])]++;
            mp[p(0, a[i+1], a[i+2])]++;
            mp[p(a[i], a[i+1], a[i+2])]++;
        }
        cout << tp << "\n";
    }
}
