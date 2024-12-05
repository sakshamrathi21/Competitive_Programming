/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec  5 09:10:05 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool possible(vector<int> a, int mid, int mx) {
    int o1 = ( mid + 1 )/2;
    int o2 = mid - o1;
    int n = a.size();
    for (int i = 0 ; i < n ; i ++ ) {
        if (mx == a[i]) continue;
        int req = (mx - a[i])/2;
        if (o2 >= req)
        {   o2 -= req;
            a[i] += (req*2);
        }
        else {
            a[i] += o2*2;
            o2 = 0;
        }
        req = (mx - a[i]);

        if (o1 >= req) {
            o1 -= req;
            a[i] += req;
        }
        else {
            a[i] += o1;
            o1 = 0;
        }
        if (mx != a[i]) return false;
    }
    return true;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int ng = 1 ; ng <= t ; ng++ ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = 1e18;
        while (abs(r-l) > 2) {
            int mid = (l + r)/2;
            if(possible(a, mid, a[a.size()-1]) || possible(a, mid, a[a.size()-1]+1)) r = mid + 1;
            else l = mid + 1; 
        }
        if (possible(a, l, a[a.size()-1]) || possible(a, l, a[a.size()-1]+1)) cout << l << "\n";
        else if (possible(a, l+1, a[a.size()-1]) || possible(a, l+1, a[a.size()-1]+1)) cout << l+1 << "\n";
        else if (possible(a, l+2, a[a.size()-1]) || possible(a, l+2, a[a.size()-1]+1)) cout << l+2 << "\n";
    }
}
