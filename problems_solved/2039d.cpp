/**
 *    Author: Saksham Rathi
 *    Created: Tue Dec  3 11:06:50 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> visited(100010, false);
    visited[1] = true;
    for (int k = 2 ; k < 100010 ; k ++) {
        if (visited[k]) continue;
        for (int i = 2*k  ; i < 100010 ; i+=k) {
            visited[i] = true;
        }
    }
    vector<int> primes;
    for (int p = 2 ; p < 100010 ; p ++) if (!visited[p]) primes.push_back(p);
    // cout << "hello" << endl;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0 ; i < m ; i ++) {
            cin >> a[i];
        }
        // cout << " check " << endl;
        reverse(a.begin(), a.end());
        vector<int> res;
        bool ok = true;
        for (int l = 1 ; l <= n ; l ++) {
            int p = 0, j = 0;
            int i = l;
            while (primes[j]*primes[j] <= i) {
                if (i%primes[j] != 0) {
                    j++;
                    continue;
                }
                while (i%primes[j] == 0) {
                    p++;
                    i /= primes[j];
                }
            }
            if (i > 1) p++;
            if (p >= m) {
                ok = false;
                break;
            } 
            res.push_back(a[p]);
        }
        if (!ok) cout << "-1\n";
        else {
            for (auto r: res) cout << r << " ";
            cout << "\n";
        }
    }
}
