/**
 *    Author: Saksham Rathi
 *    Created: Sat May 17 16:30:12 BST 2025
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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int nt = 0;
        while (true)
        {
            cout << n << " " << m << " " << a << " " << b << "\n";
            if (n > m)
            {
                n = min(a, n - a + 1);
            }
            else 
            {
                m = min(b, m - b + 1);
            }
            a = (n+1)/2;
            b = (m+1)/2;
            nt++;
            if (n == 1 && m == 1)
            {
                break;
            }
        }
        cout << nt << "\n";
    }
}
