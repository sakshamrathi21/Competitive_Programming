#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod1 = 1000000007;
ll mod2 = 1000000006;

ll exponent (ll a, ll b, ll mod) {
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
    int n;
    cin >> n;
    ll a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        //cout << ll(pow(a, b)) % mod << '\n';
        // int intermediate = exponent(b, c, mod2);
        cout << exponent(a, exponent(b, c, mod2), mod1) << '\n';
    }

}
