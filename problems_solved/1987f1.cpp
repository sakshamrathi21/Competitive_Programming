/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 21:17:37 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

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
        int cnt = 0;
        while (true) {
            // cout << "hello " << endl;
            if (a.size() <= 1) break;
            bool poss = false;
            for (int i = a.size()-2 ; i>= 0 ; i--) {
                // cout << i << " hello " << a[i] << endl;
                if (a[i] == i+1) {
                    poss = true;
                    cnt++;
                    // cout << " hello " << i << endl;
                    a.erase(a.begin()+i+1);
                    a.erase(a.begin()+i);
                    break;
                }
            }
            if (!poss) break;
        }
        cout << cnt << "\n";
    }
}
