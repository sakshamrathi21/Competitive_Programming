/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 21 19:05:14 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int M = 1000000007;

int powmod(int b, int e) {
    int p = 1; while (e) {
        if (e&1) p = p * b % M;
        e >>= 1, b = b * b % M;
    } return p;
}

int modinv(int const x) {
    return powmod(x, M-2);
}
 
int constexpr N = 400005;
int fact[N], inv_fact[N];
 
void precomp() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i-1] * i % M;
    }
    inv_fact[N-1] = modinv(fact[N-1]);
    for (int i = N-2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % M;
    }
}
 
int choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % M * inv_fact[n-k] % M;
}
 
signed main() {
    int n; 
    cin >> n;
    int ans = 0; 
    precomp();
    for (int i = 0; i <= n; ++i) {
        int ai; 
        cin >> ai;
        ans += choose(i+ai, i+1);
    }
    cout << ans%M << '\n';
}