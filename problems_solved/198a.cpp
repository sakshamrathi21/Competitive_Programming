/**
 *    Author: Saksham Rathi
 *    Created: Wed Dec  4 19:39:37 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int exp(int x, int y){
    int ans = 1;
    while (y > 0) {
        if (y&1)
            ans = ans*x;
        y = y>>1;
        x = x*x;
    }
    return ans;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, b, n, t, x;
    cin >> k >> b >> n >> t;
    if (k == 1) {
        if (t >= 1+b*n) x = 0;
        else if ((1+b*n-t) % b == 0) x = (1+b*n-t)/b;
        else x = (1+b*n-t)/b + 1;
        cout << x;
        return 0;
    }
    int val = (t*(k-1)+b)/(k-1+b);
    for (x = n ; x >= 0 ; x -- ) {
        if (val < exp(k, n-x)) break;
    }
    cout << x+1 << "\n";
}
