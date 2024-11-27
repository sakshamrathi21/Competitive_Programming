/**
 *    Author: Saksham Rathi
 *    Created: Fri Jul  5 18:44:30 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> faca, facb;
    for (int i = 1 ; i < 100001 ; i ++) {
        if (a%i == 0) {faca.push_back(i); faca.push_back(a/i);}
        if (b%i == 0) {facb.push_back(i); facb.push_back(b/i);}
    }
    for (int i = 0 ; i < faca.size() ; i ++) {
        for (int j = 0 ; j < facb.size() ; j ++) {
            int val1 = faca[i]*facb[j];
            int val2 = (a*b)/val1;
            int x = a+1, y = b+1;
            if (x%val1) x = (x/val1)*val1+val1;
            if (y%val2) y = (y/val2)*val2+val2;
            if (x <= c && y <= d) {
                cout << x << " " << y << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
    return;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
