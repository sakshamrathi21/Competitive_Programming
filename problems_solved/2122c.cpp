/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 20 11:48:29 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool find_p_in_set(multiset<int>&px, multiset<int>&py, pair<int, int> p) {
    int x = p.first;
    int y = p.second;
    if (px.find(x) != px.end() && py.find(y) != py.end()) {
        px.erase(px.find(x));
        py.erase(py.find(y));
        return true;
    }
    return false;
}

void print_multiset(multiset<int>&ps) {
    for (auto p : ps) cout << p << " ";
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    vector<int> x, y;
    for (int i = 0 ; i < n ; i ++) {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    multiset<int> xl, xr, yl, yr;
    for (int i = 0 ; i < n/2 ; i ++ ) {
        xl.insert(x[i]);
        yl.insert(y[i]);
    }
    for (int i = n/2; i < n ; i ++) {
        xr.insert(x[i]);
        yr.insert(y[i]);
    }
    vector<int> g1, g2, g3, g4;
    for (int i = 0 ; i < n ; i ++) {
        // print_multiset(xl);
        // print_multiset(xr);
        // print_multiset(yl);
        // print_multiset(yr);
        // cout << p[i].first << " " << p[i].second << "\n";
        if (find_p_in_set(xl, yl, p[i])) g1.push_back(i+1);
        else if (find_p_in_set(xl, yr, p[i])) g2.push_back(i+1);
        else if (find_p_in_set(xr, yl, p[i])) g3.push_back(i+1);
        else if (find_p_in_set(xr, yr, p[i])) g4.push_back(i+1);
    }
    // cout << g1.size() << " " << g2.size() <<" " << g3.size() << " " << g4.size() << endl;
    for (int i = 0 ; i < g1.size() ; i ++ ) cout << g1[i] << " " << g4[i] << "\n";
    for (int i = 0 ; i < g2.size() ; i ++ ) cout << g2[i] << " " << g3[i] << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
