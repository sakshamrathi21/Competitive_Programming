/**
 *    Author: Saksham Rathi
 *    Created: Fri Jul 26 15:58:26 IST 2024
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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<int> x(q);
        for (int i = 0 ; i < q ; i ++) {
            cin >> x[i];
        }
        vector<int> mn;
        mn.push_back(x[0]);
        for (int i = 1 ; i < q ; i ++) {
            if (x[i] < mn[mn.size()-1]) mn.push_back(x[i]);
        }
        
        for (int i = 0 ; i < n ; i++){
            int j = 0;
            for (; j < mn.size() ; j ++) {
                // cout << a[i] << " " << (1<<mn[j]) << " hello " << j << endl;
                if (a[i]%(1<<mn[j]) == 0) break;
            }
            
            for ( ; j < mn.size() ; j ++) {
                a[i] += (1<<(mn[j]-1));
            }
        }
        for (int i = 0 ; i < n ; i++) cout << a[i] << " ";
        cout << "\n";
    }
}
