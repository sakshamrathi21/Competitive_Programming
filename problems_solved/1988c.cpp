/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul 16 08:24:55 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int x(vector<int> bin) {
    int res = 0;
    for (int i = bin.size()-1 ; i>= 0 ; i--) {
        res = (res*2+bin[i]);
    }
    return res;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bin;
        if (__builtin_popcount(n) == 1) {
            cout << "1\n" << n << "\n";
            continue;
        }
        cout << __builtin_popcountll(n)+1 << "\n";
        while (n > 0) {
            bin.push_back(n%2);
            n /= 2;
        }
        for (int i = bin.size()-1 ; i>= 0 ; i--) {
            if (bin[i] == 0) continue;
            bin[i] = 0;
            cout << x(bin) << " ";
            bin[i] = 1;
        }
        cout << x(bin) << "\n";
    }
}
