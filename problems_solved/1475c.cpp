/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 23 15:44:03 IST 2024
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
        // cout << " hello " << t<< endl;
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> ae(k);
        vector<int> be(k);
        vector<int> ca(a+1, 0);
        vector<int> cb(b+1, 0);
        for (int i = 0 ; i < k ; i ++) {cin >> ae[i]; ca[ae[i]]++;}
        for (int i = 0 ; i < k ; i ++) {cin >> be[i]; cb[be[i]]++;}
        // cout << "hello " << cb[4] << endl;
        int cnt = 0;
        for (int i = 0 ; i < k ; i ++) {
            cnt += (k-ca[ae[i]]-cb[be[i]]+1);
        }
        cout << cnt/2 << endl;
        
    }
    
}
