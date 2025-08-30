/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 30 16:40:00 IST 2025
**/

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<char> l_op(n + 1), r_op(n + 1);
    vector<int> l_val(n + 1), r_val(n + 1);

    for (int i = 1; i <= n; i++) {
        char c1, c2;
        int v1, v2;
        cin >> c1 >> v1 >> c2 >> v2;
        l_op[i] = c1;
        l_val[i] = v1;
        r_op[i] = c2;
        r_val[i] = v2;
    }

    vector<int> latest_mul(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        if (l_op[i] == '+' && r_op[i] == '+') {
            latest_mul[i] = latest_mul[i + 1];
        } else if (l_op[i] == 'x' && r_op[i] == '+') {
            latest_mul[i] = 0;
        } else if (l_op[i] == '+' && r_op[i] == 'x') {
            latest_mul[i] = 1;
        } else if (l_val[i] > r_val[i]) {
            latest_mul[i] = 0;
        } else if (l_val[i] < r_val[i]) {
            latest_mul[i] = 1;
        } else {
            latest_mul[i] = latest_mul[i + 1];
        }
    }

    vector<int> a(2, 1); // a[0] = left, a[1] = right
    for (int i = 1; i <= n; i++) {
        int gained = 0;
        gained += (l_op[i] == '+') ? l_val[i] : (l_val[i] - 1) * a[0];
        gained += (r_op[i] == '+') ? r_val[i] : (r_val[i] - 1) * a[1];
        a[latest_mul[i + 1]] += gained;
    }

    cout << a[0] + a[1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
