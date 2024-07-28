/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 11:18:12 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> binForm(int x) {
    vector<int> rs;
    while (x > 0) {
        rs.push_back(x%2);
        x /= 2;
    }
    // reverse(rs.begin(), rs.end());
    return rs;
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> bf = binForm(n);
    }
}
