/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun  5 17:57:38 IST 2024
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
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<int> am;
        sort(a.begin(), a.end());
        am.push_back(a[0]);
        for (int i = 1 ; i < n ; i ++) {
            if (a[i] == a[i-1]) continue;
            else am.push_back(a[i]);
        }
        int tc = 0;
        tc += (a.size()-am.size())*c;
        // cout << "hello" << tc << endl;
        int min_c = LLONG_MAX;
        // cout << min_c << endl;
        for (int i = am.size()-1 ; i >=0 ; i --) {
            int cs = (am.size()-i-1)*c+(am[i]-i-1)*d;
            min_c = min(min_c, cs);
            // cout << "hello  " << cs << "\n";
        }
        int cs = am.size()*c+d;
        min_c = min(min_c, cs);
        cout << tc+min_c << "\n";
    }
}
