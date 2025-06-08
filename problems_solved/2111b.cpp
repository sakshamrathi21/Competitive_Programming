/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  8 15:53:07 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

vector<int> fib;

void solve()
{
    int n, m;
    cin >> n>> m;
    while (m--){
        int w, l, h;
        cin >> w >> l >> h;
        if (max(w, max(l, h)) >= fib[n] && min(w, min(l, h)) >= fib[n-1]) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    fib.push_back(1);
    fib.push_back(2);
    for (int i = 1 ; i < 10 ; i ++) {
        fib.push_back(fib[i]+fib[i-1]);
    }
    while (t--) {
        solve();
    }
}
