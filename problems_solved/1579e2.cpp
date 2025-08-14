/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 14 22:23:01 IST 2025
**/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long
const int MOD = 1000000007;
using namespace __gnu_pbds;

typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ordered_set s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int less = s.order_of_key(node(a, 0)),
                greater = i - s.order_of_key(node(a, n));
        cnt += min(less, greater);
        s.insert(node(a, i));
    }
    cout << cnt << '\n';
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
