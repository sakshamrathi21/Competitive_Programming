/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 20:48:50 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool poss(vector<int>&a, vector<int>&c, int turns, int h) {
    for (int i = 0 ; i < a.size() ; i ++) {
        if (turns%c[i] == 0) h-= (turns/c[i])*a[i];
        else h-= (turns/c[i]+1)*a[i];
        if (h <= 0) return true;
    }
    return false;
}

int binSearch(vector<int>&a, vector<int>&c, int low, int high, int h) {
    // cout << low << " hello " << high << endl;
    if (high-low<=2) {
        if (poss(a, c, low, h)) return low;
        if (poss(a, c, low+1, h)) return (low+1);
        return high;
    }
    int mid = (low+high)/2;
    if (poss(a, c, mid, h)) {
        return binSearch(a, c, low, mid+1, h);
    }
    return binSearch(a, c, mid+1, high, h);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int h, n;
        cin >> h >> n;
        vector<int> a(n), c(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> c[i];
        }
        cout << binSearch(a, c, 0, (h/a[0]+1)*c[0], h) << "\n";
    }
}
