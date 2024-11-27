/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 23:29:59 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool possible (vector<int>&a, int d, int k, int c) {
    if (k == 0) {
        if (a[0]*d < c) return false;
        return true;
    }
    int e = 0;
    for (int i = 0 ; i < d ; i ++) {
        if (i%k < a.size()) e += a[i%k];
    }
    if (e >= c) return true;
    return false;
}

int binSearch(vector<int>&a, int d, int c, int low, int high) {
    if (high - low <= 1) {
        if (possible(a, d, low, c)) return low;
        return high;
    }
    int mid = (low+high)/2;
    if (possible(a, d, mid, c)) return binSearch(a, d, c, mid, high);
    return binSearch(a, d, c, low, mid);
}

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
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int b = binSearch(a, d, c, 0, d+2); 
        if (b == 1) {
            if (possible(a, d, b, c)) cout << b-1 << "\n";
            else cout << "Impossible" << "\n";
        }
        else if (b == d+1) {
            cout << "Infinity\n";
        }
        else cout << b-1 << "\n";
    }
}
