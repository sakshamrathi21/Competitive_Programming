/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 13:59:47 IST 2024
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
        vector<int> ind;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            if (a[i] != -1) ind.push_back(i);
        }
        bool poss = true;
        for (int i = 1 ; i < ind.size() ; i ++ ){
            int prev = ind[i-1], preva = a[prev];
            int next = ind[i], nexta = a[next];
            vector<int> l, r;
            while (preva > 0) {
                l.push_back(preva);
                preva /= 2;
            }
            while (nexta > 1) {
                r.push_back(nexta);
                nexta/=2;
            }
            if (l.size() + r.size() > )
        }

    }
}
