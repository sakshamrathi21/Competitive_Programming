/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug  2 16:41:27 IST 2025
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
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2 ; i <= 2*n ; i*=2) {
        count += (n/i)*i/2;
        int rem = n - (n/i)*i;
        count += rem >= i/2 ? rem - i/2 + 1 : 0;
        // cout << i << " " << count << "\n";
    }
    cout << count << "\n";
}
