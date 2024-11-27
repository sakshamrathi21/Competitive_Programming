/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 13:23:40 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int sqS(int num, int low, int high) {
    if (num < 0) return -1;
    if (high-low <= 1) {
        if (low*low == num) return low;
        if (high*high == num) return high;
        return -1;
    }
    int mid = (low+high)/2;
    if (mid*mid == num) return mid;
    if (mid*mid < num ) return sqS(num, mid + 1, high);
    return sqS(num, low, mid);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            int b = (x*x-4LL*y);
            int sq = sqS(b, 0, b+1);
            if (sq*sq == b) {
                int l = (x-sq)/2, r = (x+sq)/2;
                if ((l+r) == x && (l*r) == y) {
                    if (l == r) {
                        int f = freq[l];
                        cout << (f*(f-1))/2ll << " ";
                    }
                    else cout << (freq[l]*freq[r]) << " ";
                }
                else cout << 0 << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}
