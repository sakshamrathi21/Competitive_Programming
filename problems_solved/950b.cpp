#include<bits/stdc++.h>
using namespace std;
#define int long long

bool customComparator(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<pair<int, int> > a(n); 
        for (int i = 0 ; i < n ; i ++ ) {
            cin >> a[i].first;
            a[i].second = i+1;
        }
        int val = a[f-1].first;
        sort(a.begin(), a.end(), customComparator);
        // 
        bool maybe = false;
        if (k < n && a[k].first == a[k-1].first) {
            // cout << " HELLO " << val << endl;
            for (int i  = k ; i < n ; i ++ ) {
                if (a[i].first != a[k-1].first) break;
                if (a[i].second == f) {
                    maybe = true;
                    break;
                }
            }
            // cout << "HELLO " << a[1].second <<  endl;
            for (int i = k - 1 ; i >= 0 ; i--) {
                if (a[i].first != a[k-1].first) break;
                if (a[i].second == f) {
                    maybe = true;
                    break;
                }
            }
        }
        if (maybe) cout << "MAYBE" << "\n";
        else {
            if (val < a[k-1].first) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }
}
