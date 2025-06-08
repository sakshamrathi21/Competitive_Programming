/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  1 09:27:54 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int power(int s, int k){
    if (k == 0) return 1;
    if (k == 1) return s;
    int ps = power(s, k/2);
    if (k%2 == 0) {
        return ((ps%MOD)*(ps%MOD)%MOD);
    }
    return (((ps%MOD)*(ps%MOD)%MOD)*s%MOD);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> p[i];
    }
    for (int i = 0 ; i < n ; i ++) {
        cin >> q[i];
    }
    int maxp = 0, maxq = 0;
    vector<int> r(n);
    r[0] = (power(2, p[0]) + power(2, q[0]))%MOD;
    for (int i = 1 ; i < n ; i ++)
    {
        if (p[i] > p[maxp]) maxp = i;
        if (q[i] > q[maxq]) maxq = i;
        if (make_pair(p[maxp], q[i-maxp]) > make_pair(q[maxq], p[i-maxq])) {
            r[i] = (power(2, p[maxp]) + power(2, q[i-maxp]))%MOD;
        }
        else {
            r[i] = (power(2, q[maxq]) + power(2, p[i-maxq]))%MOD;
        }
    }
    for (int i = 0 ; i < n ; i ++){
        cout << r[i] << " "; 
    }
    cout << "\n";
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
