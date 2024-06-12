/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun  8 12:54:17 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.second < y.second) return true;
    return false;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i].first >> a[i].second;
        }
        multiset<int> st;
        // set<int> st;
        int cnt = 0;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0 ; i < n ; i ++) {
            auto it = st.upper_bound(a[i].first);
            if (it != st.end()) {
                cnt += st.size()-distance(st.begin(), it);
            }
            st.insert(a[i].first);
        }
        cout << cnt << "\n";

    }
}
