/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug  2 22:56:49 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    string s, b;
    cin >> s >> b;
    int k;
    cin >> k;
    int n = s.length();
    // cout << n << endl;
    
    set<pair<int, int>> hashes;

    const int p1 = 31, p2 = 53;
    const int m1 = 1e9 + 9, m2 = 1e9 + 7;

    vector<long long> p_pow1(n), p_pow2(n);
    p_pow1[0] = p_pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow1[i] = (p_pow1[i - 1] * p1) % m1;
        p_pow2[i] = (p_pow2[i - 1] * p2) % m2;
    }

    for (int i = 0; i < n; i++) {
        int chash1 = 0, chash2 = 0, cg = 0;
        for (int j = i; j < n; j++) {
            cg += b[s[j] - 'a'] == '0';
            if (cg > k) break;
            chash1 = (chash1 + (s[j] - 'a' + 1) * p_pow1[j - i]) % m1;
            chash2 = (chash2 + (s[j] - 'a' + 1) * p_pow2[j - i]) % m2;
            hashes.insert({chash1, chash2});
        }
    }

    cout << hashes.size() << "\n";
}


signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}
