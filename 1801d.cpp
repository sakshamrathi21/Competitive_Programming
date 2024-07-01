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
        multiset<int> ps, ms;
        for (int i = 0 ; i < n ; i ++) {
            ps.insert(ab[i].first);
            ms.insert(-ab[i].first);
        }
        // cout << ms.size() << endl;
        int md = LLONG_MAX;
        int m = -LLONG_MAX;
        for (int i = 0 ; i < n ; i ++) {
            // cout << ps.size() << " hello " << ms.size() << endl;
            auto rt1 = ps.find(ab[i].first);
            if (rt1 != ps.end()) ps.erase(rt1);
            rt1 = ms.find(-ab[i].first);
            if (rt1 != ms.end()) ms.erase(rt1);
            // ms.erase(ms.find(ab[i].first));
            // cout << ps.size() << " hello " << ms.size() << endl;
            // cout << ab[i].first << " hello " << ab[i].second << " " <<  ms.size()<< endl;
            // ps.lower_bound()
            auto it1 = ps.lower_bound(ab[i].second);
            auto it2 = ms.lower_bound(-ab[i].second);
            if (m != -LLONG_MAX) md = min(md, abs(ab[i].second-m));
            
            if (it1 != ps.end()) {
                // cout << ab[i].second << " hello " << *it1 << " " << m  << endl;
                if (*it1 > m) md = min(md, abs(max(*it1, m)-ab[i].second));
            }
            // cout << " check " << md << endl;
            if (it2 != ms.end()) {
                // cout << ab[i].second << " iihello " << *it2 << " " << m << endl;
                if (-*it2 > m) md = min(md, abs(max(-*it2, m)-ab[i].second));
            }
            m = max(m, ab[i].first);
            // if (na != -LLONG_MAX) md = min(md, abs(ab[i].second-na));
        }
        cout << md << "\n";
    }
}
