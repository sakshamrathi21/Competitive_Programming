#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;

void exponent (ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        b = b/2;
    }
    cout << result << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a, b;
    while (n--) {
        cin >> a >> b;
        //cout << ll(pow(a, b)) % mod << '\n';
        exponent(a, b);
    }

}
