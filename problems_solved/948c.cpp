#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    // cout << x << y << endl;
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

int lm(int x, int y) {
    return (x*y/gcd(x, y));
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
        set<int> l;
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
            l.insert(a[i]);
        }
        vector<int> dp(n, 0);
        vector<int> lcm(n, 0);
        sort(a.begin(), a.end());
        for (int i = 0 ; i < n ; i ++) {
            lcm[i] = a[i];
        }

        for (int i = 0 ; i < n ; i ++) {
            l.insert(a[i]);
            for (int j = 0 ; j < i ; j ++) {
                int x = lm(lcm[j], a[i]);
                if (l.find(x) == l.end()) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        lcm[i] = x;
                    }
                }
            }
        }
        int max_n = -1;
        int max_l = -1;
        int max_a = -1;
        // vector<int> val;
        for (int i = 0 ; i < n ; i ++) {
            if (dp[i] >= max_n) {
                max_n = dp[i];
                max_l = lcm[i];
                int cnt = 0;
                if (lcm[i] == 0) {
                    // cout << "hello";
                    continue;}
                for (int j = 0 ; j < n ; j ++) {
                    if (lcm[i]%a[j] == 0)  cnt++;
                }
                max_a = max(max_a, cnt);
            }
        }
        cout << max_a << "\n";
    }
}
