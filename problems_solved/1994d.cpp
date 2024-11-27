/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 18 21:06:26 IST 2024
**/


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
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        set<int> cn;
        set<set<int>> ss;
        // set<int> s;
        // ss.insert(s);
        cout << "YES\n";
        vector<pair<int, int>> pr(n, make_pair(-1, -1));
        vector<bool> visited(n, false);
        for (int i = n-1 ; i> 0 ; i--) {
            // cout << "check " << ss.size() << endl;
            set<int> se;
            bool found = false;
            for (auto s1 : ss) {
                for (auto s2 : ss) {
                    if (s1 == s2) continue;
                    for (auto j : s1) {
                        for (auto k : s2) {
                            if (found) break;
                            if (a[j]%i == a[k]%i) {
                                found = true;
                                pr[i].first = j;
                                pr[i].second = k;
                                se = s2;
                                s1.insert(s2.begin(), s2.end());
                            }
                        }
                    }
                }
            }
            // cout << " check " << i << endl;
            if (found) {
                ss.erase(se);
                continue;
            }
            for (auto s: ss) {
                for (auto j : s) {
                    for (int k = 0 ; k < n ; k ++) {
                        if (found) break;
                        if (visited[k]) continue;
                        if (a[j]%i == a[k]%i) {
                            visited[k] = true;
                            s.insert(k);
                            found = true;
                            pr[i].first = j;
                            pr[i].second = k;  
                        }
                    }
                }
            }
            if (found) continue;
            for (int j = 0 ; j < n ; j ++) {
                for (int k = 0 ; k < n ; k ++) {
                    if (found) break;
                    if (visited[j] || visited[k] || j == k || a[j]%i != a[k]%i) continue;
                    set<int> s;
                    s.insert(j);
                    s.insert(k);
                    // cout << j << " ram " << k << endl; 
                    ss.insert(s);
                    pr[i].first = j;
                    pr[i].second = k;
                    visited[k] = true;
                    visited[j] = true;  
                    found = true;
                }
            }
        }
        for (int i = 1 ; i < n ; i ++) {
            cout << pr[i].first+1 << " " << pr[i].second+1 << "\n";
        }
    }
}
