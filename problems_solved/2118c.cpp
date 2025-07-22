/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul 22 10:14:10 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

multiset<int> all_rem;

int num_binary(int x) {
    vector<int> rep(60, 0);
    int i = 0;
    while (x > 0) {
        rep[i] = x%2;
        i++;
        x/=2;
    }
    int one = 0;
    for (int i = 0 ; i < rep.size() ; i ++) {
        // cout << i << " " << (1<<i) << "hello\n";
        if (rep[i] == 0) all_rem.insert(pow(2, i));
        else one++;
    }
    return one;
}

void solve()
{
    all_rem.clear();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int count = 0;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        count += num_binary(a[i]);
    }
    // cout << count << " \n " ;
    // for (auto x : all_rem) cout << " hello " << x << "\n";
    for (auto x : all_rem) {
        if (k >= x) {
            k -= x;
            count ++;
        }
        else break;
    }
    cout << count << "\n";
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
