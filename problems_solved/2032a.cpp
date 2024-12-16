/**
 *    Author: Saksham Rathi
 *    Created: Mon Dec 16 19:47:10 IST 2024
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
        int no = 0, nz = 0;
        for (int i = 0 ; i < 2*n ; i ++) {
            int x;
            cin >> x;
            if (x == 0) nz ++ ;
            else no ++;
        }
        cout << (no%2) << " " << min(no, nz) << "\n";
    }
}
