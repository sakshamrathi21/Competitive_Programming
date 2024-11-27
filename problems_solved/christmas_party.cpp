#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    // int n;
    cin >> n;
    ll D[n+1];
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n == 2) {
        cout << 1;
        return 0;
    }
    D[1] = 0;
    D[2] = 1;
    for (int i = 3 ; i<= n ; i ++ ) {
        D[i] = (i-1)*(D[i-1] + D[i-2])%mod;
    }
    cout << D[n];
}
