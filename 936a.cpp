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
        vector<int> q(n);
        for (int i = 0 ; i < n ; i ++) cin >> q[i];
        sort(q.begin(), q.end());
        int med;
        if (n%2 == 0) med = (n/2-1);
        else med = n/2;
        int cnt = 1;
        for (int i = med + 1 ; i < n ; i ++) {
            if (q[i] == q[i-1]) cnt++;
            else break;
        }
        cout << cnt << "\n";
    }
}
