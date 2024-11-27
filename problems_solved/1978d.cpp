/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 14:25:35 IST 2024
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
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        multiset<int> s;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int max_in = 0;
        int max_val = a[0]+c;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] > max_val) {
                max_in = i; 
                max_val = a[i];
            }
        }
        int currS = 0;
        for (int i = 0 ; i < max_in ; i ++) {
            if (i == 0) {
                cout << "1 ";
            }
            else {
                if (currS + a[i]+c < max_val) {
                    cout << i+1 << " ";
                }
                else cout << i << " ";
            }
            currS += a[i];
        }
        cout << "0 ";
        currS += a[max_in];
        for (int i = 0 ; i <= max_in ; i ++) {
            s.erase(a[i]);
        }
        for (int i = max_in+1 ; i < n ; i ++) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
