#include<bits/stdc++.h>
using namespace std;
#define int long long

int ts (int x, int y) {
    if (x < 0) return 0;
    if (y < 0) return 0;
    if (x == 0 && y == 0) return 0;
    if (x ==0) {
        if (y%2) return 1+y/2;
        else return y/2;
    }
    
    if (y == 0) {
        if (x%15 == 0) return x/15;
        // cout << " hello " << endl;
        else return 1+x/15;
    }
    if ( y == 1) {
        return  1+ts(x-11, y-1);
    }
    if (x >= 7 && y >= 2) return 1+ts(x-7, y-2);
    else return 1+ts(0, y-2);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << ts(x, y) << "\n";
    }
}
