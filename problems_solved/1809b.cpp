/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun  5 19:41:07 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int bin_search (int n, int low, int high) {
    if (high - low <= 1) {
        if ((low+1)*(low+1) >= n) return low;
        return high;
    }
    int mid = (high+low)/2;
    if ((mid+1)*(mid+1) < n) return bin_search(n, mid+1, high);
    return bin_search(n, low, mid);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << bin_search(n, 0, sqrt(n)+1) << "\n";
    }
}
