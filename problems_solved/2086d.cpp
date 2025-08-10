/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 18:17:58 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 5e5 + 10;
vector<int>fact(N, 1);
vector<int> inv(N);



int powmod(int b, int e) {
    int p = 1; while (e) {
        if (e&1) p = p * b % MOD;
        e >>= 1, b = b * b % MOD;
    } return p;
}

int modinv(int const x) {
    return powmod(x, MOD-2);
}

void precomp() {
    for (int i = 1 ; i < fact.size() ; i ++) fact[i] = (fact[i-1]*i)%MOD;
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
}

void solve() {
    vector<int> c(26);
    int sum = 0;
    int fact_prod = 1;
    for (int i = 0 ; i < 26 ; i ++) {
        cin >> c[i];
        sum += c[i];
        fact_prod *= modinv(fact[c[i]]);
        fact_prod %= MOD;
    }
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 26; i++){
		if (c[i] == 0){
			continue;
		}
		for (int j = sum; j >= 0; j--){
			if (j + c[i] <= sum){
				dp[j + c[i]] += dp[j];
			}
		}
	}
    int odd = sum - sum/2;
    // cout << dp[odd] << " hello " << endl;
    cout << (dp[odd] * (fact[odd]*fact[sum-odd] % MOD) % MOD)*fact_prod%MOD << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    precomp();
    while (t--) {
        solve();
    }
}
