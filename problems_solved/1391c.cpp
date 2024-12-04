/**
 *    Author: Saksham Rathi
 *    Created: Wed Dec  4 12:51:37 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
const int md = 1e9+7;
 
int exp(int x, int y, int md){
    int ans = 1;
    x = x%md;
    while (y > 0) {
        if (y&1)
            ans = ans*x%md;
        y = y>>1;
        x = x*x%md;
    }
    return ans;
}

int fact(int n) {
    // if (n == 0) return 1;
    int prod = 1;
    for (int i = 1 ; i <= n ; i ++ ) {
        prod*=i;
        prod %=md;
    }
    return prod;
} 

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (fact(n)+md-exp(2, n-1, md))%md;
}
