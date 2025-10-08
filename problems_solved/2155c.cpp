/**
 *    Author: Saksham Rathi
 *    Created: Wed Oct  8 13:28:00 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool check(vector<int>&a, vector<int>&b) {
    int n = a.size();
    if (n == 1) return true;
    vector<int> p(n, 0), s(n, 0);
    p[0] = b[0];
    s[n - 1] = b[n - 1];
    for (int i = 1 ; i < n ; i ++) p[i] = p[i - 1] + b[i];
    for (int i = n - 2 ; i >= 0 ; i --) s[i] = s[i + 1] + b[i];
    // for (int i = 0 ; i < n ; i ++) cout << p[i] << " ";
    // for (int i = 0 ; i < n ; i ++) cout << s[i] << " ";
    if (a[0] != s[1] + 1) return false;
    if (a[n - 1] != (n - 1 - p[n - 2]) + 1) return false;
    for (int i = 1 ; i < n - 1 ; i ++) if (a[i] != (i - p[i - 1]) + s[i + 1] + 1) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    bool poss1 = true, poss2 = true;
    vector<int> b(n, 0), c(n, 0);
    b[0] = 0;
    for (int i = 1 ; i < n ; i ++) {
        if (abs(a[i] - a[i - 1]) >= 2) poss1 = false;
        if (b[i - 1] == 0) {
            if (a[i] == a[i - 1]) b[i] = 1;
            else if (a[i] == a[i - 1] + 1) b[i] = 0;
            else poss1 = false;
        }
        else {
            if (a[i] == a[i - 1]) b[i] = 0;
            else if (a[i] == a[i - 1] - 1) b[i] = 1;
            else poss1 = false;
        }
    }
    if (poss1) poss1 = check(a, b);
    b[0] = 1;
    for (int i = 1 ; i < n ; i ++) {
        if (abs(a[i] - a[i - 1]) >= 2) poss2 = false;
        if (b[i - 1] == 0) {
            if (a[i] == a[i - 1]) b[i] = 1;
            else if (a[i] == a[i - 1] + 1) b[i] = 0;
            else poss2 = false;
        }
        else {
            if (a[i] == a[i - 1]) b[i] = 0;
            else if (a[i] == a[i - 1] - 1) b[i] = 1;
            else poss2 = false;
        }
    }
    if (poss2) poss2 = check(a, b);
    // for (int i = 0 ; i < n ; i ++) cout << b[i] << " ";
    // cout << endl;
    cout << poss1 + poss2 << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
