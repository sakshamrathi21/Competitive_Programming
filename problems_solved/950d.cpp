#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

int global_ps = -1;

bool inc(vector<int> a) {
    int n = a.size();
    vector<int> b(n-1);
    for (int i = 0 ; i < n - 1 ; i ++) b[i] = gcd(a[i], a[i+1]);
    for (int i = 0 ; i < b.size()-1 ; i ++) {
        if (b[i] > b[i+1]) {global_ps = i; return false;}
    }
    return true;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++ ) cin >> a[i];
        bool possible = false;
        
        if (inc(a)) possible = true;
        else {
            
            vector<int> a1 = a, a2 = a, a3 = a;
            // cout << possible << " hello "  << global_ps << endl;
            a1.erase(a1.begin()+global_ps);
            
            a2.erase(a2.begin()+global_ps+1);
            a3.erase(a3.begin()+global_ps+2);
            
            if (inc(a1) || inc(a2) || inc(a3)) possible = true;
        }
        if (possible) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
