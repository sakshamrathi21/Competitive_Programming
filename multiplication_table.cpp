#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int low = 1, high = n*n, mid, leq;

    while (low < high ) {
        mid = (low + high)/2;
        leq = 0;
        for (int i = 1 ; i <= n ; i ++ ) {
            leq += min(n, mid/i);
        }
        if (leq >= (n*n+1)/2) high = mid;
        else low = mid + 1;
    }
    cout << high;
    return 0;
    
}
