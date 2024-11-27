/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 20 17:32:15 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    vector<int> visited(10000001, 0);
    visited[1] = true;
    for (int k = 2 ; k < 10000001 ; k ++) {
        if (visited[k]) continue;
        // cout << k << endl;
        for (int i = 2*k  ; i < 10000001 ; i+=k) {
            // if (i == 4) cout << " hello" << i << k << endl;
            visited[i] = k;
            // if (i == 4) cout << " hello" << i << k<< visited[i]<< endl;
        }
    }
    // cout << visited[9] << " hello " << endl;
    vector<int> primes;
    for (int p = 2 ; p < 10000001 ; p ++) if (!visited[p]) primes.push_back(p);
    // cout << primes[4] << " hello" << endl;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> l1(n), r1(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            int d1 = -1, d2 = -1;
            d1 = visited[a[i]];
            // cout << " hello " << d1 << endl;
            if (d1 == 0 || d1 == 1) d1 = -1;
            if (d1 != -1) {
                while (a[i]%d1 ==0) a[i]/=d1;
                if (a[i] == 1) {
                    d1 = -1;
                } 
                else {
                    d2 = a[i];
                }
            }
            if (d2 == -1) {
                d1 = -1;
            }
            l1[i] = d1;
            r1[i] = d2;
        }
        for (int i = 0 ; i < n ; i ++) cout << l1[i] << " ";
        cout << "\n";
        for (int i = 0 ; i < n ; i ++) cout << r1[i] << " ";
    }
}
