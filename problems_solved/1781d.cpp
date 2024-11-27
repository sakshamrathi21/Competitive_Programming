/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul  1 17:23:41 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool whether_sqrt(int r) {
    int sq = sqrt(r);
    if (sq*sq == r || (sq-1)*(sq-1) == r || (sq+1)*(sq+1) == r) return true;
    return false;
} 

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int ans = 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = i+1 ; j < n ; j ++ ) {
                int diff = a[j] - a[i];
                for (int k = 1 ; k <= sqrt(diff)+1 ; k ++) {
                    if (diff%k) continue;
                    int p = (diff/k-k)/2;
                    int q = (diff/k+k)/2;
                    if (p*p-a[i] != q*q-a[j]) continue;
                    int cnt = 0;
                    int x = p*p-a[i];
                    if (x < 0) continue;
                    for (int l = 0 ; l < n ; l ++) {
                        if (whether_sqrt(a[l]+x)) cnt++;
                    }
                    // cout << x << " hello " << cnt << endl;
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << "\n";
    }
}
