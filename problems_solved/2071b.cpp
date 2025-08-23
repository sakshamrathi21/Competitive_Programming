/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 23 21:27:47 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

set<int> fn;
vector<int> seq(5e5 + 1, 0);

void pre() {
    for (int i = 1 ; i <= 5e5 ; i ++) {
        int num = i*(i+1)/2;
        int root = (int)(sqrt(num));
        seq[i] = i;
        if (root*root == num) fn.insert(i);
    }
    for (auto c : fn) swap(seq[c], seq[c+1]);
}

void solve() {
    int n;
    cin >> n;
    if (fn.find(n) != fn.end()) {
        cout << "-1\n";
        return;
    }
    for (int i = 1 ; i <= n ; i ++ ) cout << seq[i] << " ";
    cout << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
}
