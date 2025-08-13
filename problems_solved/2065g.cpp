/**
 *    Author: Saksham Rathi
 *    Created: Wed Aug 13 16:15:45 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
const int MAXN = 2e5 + 10;
vector<bool> whether_prime(MAXN, true);
set<int> all_primes;

void pre() {
    whether_prime[1] = false;
    whether_prime[0] = false;
    for (int i = 2 ; i < MAXN ; i ++) {
        if (!whether_prime[i]) continue;
        all_primes.insert(i);
        for (int j = 2*i ; j < MAXN ; j += i) whether_prime[j] = false;
    }
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    vector<int> f(n + 10, 0);
    for (int i = 0 ; i < n ; i ++) f[a[i]]++;
    // cout << f[4] << " " << endl;
    int count = 0;
    for (auto x : all_primes) {
        for (auto y : all_primes) {
            if (x > n || y > n || y >= x) break;
            count += f[x]*f[y];
        }
    }
    // cout << "hello" <<
    for (int i = 2 ; i <= n ; i ++) {
        // cout << i << " " << f[i] << " " << count << endl;
        if (!f[i]) continue;
        if (whether_prime[i]) continue;
        int found = -1;
        for (auto x: all_primes) {
            if (i % x == 0) {
                if (!whether_prime[i/x]) break;
                found = x;
                break;    
            }
        }
        if (found != -1) {
            count += f[i]*(f[i] + 1)/2;
            count += f[i]*f[found];
            if (i/found != found) count += f[i]*f[i/found];
        }
    }
    cout << count << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
}
