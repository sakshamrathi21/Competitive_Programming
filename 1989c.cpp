/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 27 20:40:34 IST 2024
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
        vector<int> a(n), b(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> b[i];
        }
        vector<int> temp;
        int s1 = 0, s2 = 0;
        for (int i = 0 ; i < n ; i ++ ){
            if (a[i] > b[i]) {
                s1 += a[i];
            }
            else if (b[i] > a[i]) {
                s2 += b[i];
            }
            else {
                if (a[i] != 0) temp.push_back(a[i]);
            }
        }
        for (int i = 0 ; i < temp.size() ; i ++) {
            if (temp[i] == 1) {
                if (s1 >= s2) s2 += 1;
                else s1 += 1;
            }
            else {
                if (s1 >= s2) s1 -= 1;
                else s2 -= 1;
            }
        }
        cout << min(s1, s2) << "\n";
    }
}
