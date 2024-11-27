#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >>n;
        int a[n];
        for (int i = 0 ; i < n ; i++) cin >> a[i];
        set<int> all_el;
        for (int i = 0 ; i <= n ; i ++) all_el.insert(i);
        int pref[n];
        for (int i = 0 ; i < n ; i ++) {
            all_el.erase(a[i]);
            pref[i] = *(all_el.begin());
        }
        for (int i = 0 ; i <= n ; i ++) all_el.insert(i);
        int suf[n];
        for (int i = n - 1 ; i >= 0 ; i --) {
            all_el.erase(a[i]);
            suf[i] = *(all_el.begin());
        }
        bool possible = false;
        int ind = -1;
        for (int i = 0 ; i < n-1 && !possible ; i ++) {
            if (pref[i] == suf[i+1]) {
                possible = true;
                ind = i;
            }
        }
        if (possible) {
            cout << 2 << "\n";
            cout << 1 << " " << ind+1 << "\n";
            cout << ind+2 << " " << n << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}
