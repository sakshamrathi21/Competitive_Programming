#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

ll exponent (ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        b = b/2;
    }
    return result;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll result = 0;
    if (n%2 == 0) {
        result = (exponent(2, n*n) + 2*exponent(2, n*n/4) + exponent(2, n*n/2))%mod;
        result = mul(result, exponent(4, mod-2));
    }
    else {
        result = (exponent(2, n*n) + 2*exponent(2, (n*n+3)/4) + exponent(2, (n*n+1)/2))%mod;
        result = mul(result, exponent(4, mod-2));
    }

    cout << result << endl;
    
}
