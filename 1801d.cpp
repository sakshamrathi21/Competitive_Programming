/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul  1 18:07:10 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool cmp (const pair<int, int>& p1, const pair<int, int>&p2) {
    if (p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ab(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> ab[i].first >> ab[i].second;
        }
        // for (int i = 0 ; i < n ; i ++) {
        //     cout << ab[i].first << " hello " << ab[i].second<< endl;}
        sort(ab.begin(), ab.end(), cmp);
        set<int> ps, ms;
        for (int i = 0 ; i < n ; i ++) {
            ps.insert(ab[i].first);
            ms.insert(-ab[i].first);
        }
        int md = LLONG_MAX;
        int m = -LLONG_MAX;
        for (int i = 0 ; i < n ; i ++) {
            // cout << ab[i].first << " hello " << ab[i].second<< endl;
            ps.erase(ab[i].first);
            ms.erase(-ab[i].first);
            auto it1 = lower_bound(ps.begin(), ps.end(), ab[i].second);
            auto it2 = lower_bound(ms.begin(), ms.end(), -ab[i].second);
            if (m != -LLONG_MAX) md = min(md, abs(ab[i].second-m));
            
            if (it1 != ps.end()) {
                // cout << ab[i].second << " hello " << *it1 << endl;
                if (abs(max(*it1, m)-ab[i].second) < abs(ab[i].second - m)) md = min(md, abs(max(*it1, m)-ab[i].second));
            }
            if (it2 != ms.end()) {
                // cout << ab[i].second << " iihello " << *it2 << endl;
                if (abs(max(-*it2, m)-ab[i].second) < abs(ab[i].second - m)) md = min(md, abs(max(-*it2, m)-ab[i].second));
            }
            m = max(m, ab[i].first);
            // if (na != -LLONG_MAX) md = min(md, abs(ab[i].second-na));
        }
        cout << md << "\n";
    }
}
