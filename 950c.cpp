#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        for (int i = 0 ; i < n ; i ++) cin >> b[i];
        int m;
        cin >> m;
        vector<int> d(m);
        for (int i = 0 ; i < m ; i ++) cin >> d[i];
        // cout << " hello " << d[m-2] << endl;
        vector<int> f;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] != b[i]) f.push_back(b[i]);
        }
        bool possible = true;
        if (f.size() > d.size()) possible = false;
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        vector<bool> c(d.size(), false);
        int l = 0, r = 0;
        
        while (l < d.size() && r < f.size()) {
            // cout << " HELLO " <<d[l] << f[r] << endl;
            if (d[l] == f[r]) {
                c[l] = true;
                l++;
                r++;
            }
            else if (d[l] < f[r]) {
                l++;
            }
            else {
                possible = false;
                break;
            }
        }
        if (r < f.size()) possible = false;
        multiset<int> bs(b.begin(), b.end());
        
        bool matched = true;
        // multiset<int> ds(d.begin(), d.)
        // mul
        if (possible) {
            for (int i = 0 ; i < d.size() ; i ++) {
                if (!c[i]) {
                    if (bs.count(d[i]) == 0){
                        matched = false;
                        // if (i > 0 && d[i] > d[i-1]) c[i] = true;
                        break;
                    }
                    else if (i > 0 && d[i] > d[i-1]) c[i] = true;
                }
            }
        }
        // 
        multiset<int> ds;
        
        for (int i = 0 ; i < m ; i ++) if (!c[i]) {
            ds.insert(d[i]);
            // cout << d[i] << " ";
        }
        // cout << "HELLO " << ds.size() << endl;
        bool found = false;
        if (possible) {
            for (int i = 0 ; i < n ; i ++) {
                if (ds.count(b[i]) >= 1) {
                    found = true;
                    break;
                }
            }
        }
        // cout << matched << found << endl;
        if (possible) {
            if (!matched && !found) possible = false;
        }
        if (possible) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
