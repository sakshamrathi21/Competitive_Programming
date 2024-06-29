/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 29 19:04:16 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 998244353;

vector<int> get_primes(int n)
{
    int d = 2;
    vector<int> ans;
    while (d * d <= n)
    {
        bool este = false;
        while (n % d == 0)
        {
            n /= d;
            este = true;
        }
        if (este) ans.push_back(d);
        d++;
    }
    if (n != 1) ans.push_back(n);
    return ans;
}

int ie(vector<int>&p, int m) {
    int res = 0;
    for (int i = 0 ; i < (1 << p.size()) ; i ++) {
        int c = 1;
        int bc = 0;
        for (int j = 0 ; j < p.size() ; j ++) {
            if (i&(1<<j)) {
                c*=p[j];
                bc++;
            }
        }
        res += pow(-1, bc)*(m/c);
    }
    // cout << p.size() << " check " << res << endl;
    return res;
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<int> primes = get_primes(a[0]);
        // for (int i = 0 ; i < primes.size() ; i ++) cout << primes[i] << " ";
        // cout << "\n";
        bool poss = true;
        int cnt = 1;
        for (int i = 1 ; i < n ; i ++) {
            if (a[i-1]%a[i] != 0) {
                poss = false;
                break;
            }
            int l = a[i-1]/a[i];
            vector<int> p;
            for (int i = 0 ; i < primes.size() ; i ++) {
                if (l%primes[i] == 0) p.push_back(primes[i]);
            }
            cnt *= ie(p, m/a[i]);
            // cout << " hello " << cnt << endl;
            cnt %= MOD;
        }
        if (!poss) cout << "0\n";
        else {
            cout << cnt << "\n";
        }
    }
}
