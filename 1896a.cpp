/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun  5 10:35:10 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int ind(vector<int>&a) {
    for (int i = 1 ; i < a.size() - 1 ; i ++) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) return i;
    }
    return -1;
}

bool inc(vector<int>&a) {
    for (int i = 0 ; i < a.size()-1 ; i ++) if (a[i]>a[i+1]) return false;
    return true;
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
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int i = ind(a);
        while (i!=-1) {
            swap(a[i], a[i+1]);
            i = ind(a);
        }
        if (inc(a)) cout << "YES" <<"\n";
        else cout << "NO" << "\n";
    }
}
