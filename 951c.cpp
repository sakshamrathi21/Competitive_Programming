/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun  6 20:35:14 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    // cout << x << y << endl;
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

int lm(int x, int y) {
    return (x*y/gcd(x, y));
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int m_lcm = a[0];
        for (int i =1 ; i < n ; i ++ ) {
            m_lcm = lm(m_lcm, a[i]);
        }

        vector<int> coins(n);
        int t_sum = 0;
        for (int i = 0 ; i < n ; i ++) {
            coins[i] = m_lcm/a[i];
            t_sum += coins[i];
        }
        bool poss = true;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i]*coins[i] <= t_sum) {
                poss = false;
                break;
            }
        }
        if (poss) {
            for (int i = 0 ; i < n ; i ++) cout << coins[i] << " ";
            cout << "\n"; 
        }
        else {
            cout << -1 << "\n";
        }
        

    }
}
