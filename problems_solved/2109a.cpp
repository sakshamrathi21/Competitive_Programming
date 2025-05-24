/**
 *    Author: Saksham Rathi
 *    Created: Sat May 17 16:12:41 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == n && n%2 == 0)
        {
            cout << "YES\n";
            continue;
        }
        bool ok = true;
        for (int i = 0 ; i < n - 1 ; i ++)
        {
            if (a[i] == 0 && a[i+1] == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}
