/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug  2 08:49:59 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

void pop_two_stack(stack<pair<int, int>> &s1, stack<pair<int, int>> &s2) {
    if (!s2.empty()) {
        s2.pop();
        return;
    }
    while (!s1.empty()) {
        int tp = s1.top().first;
        s1.pop();
        int nmin = s2.empty() ? tp : min(tp, s2.top().second);
        s2.push(make_pair(tp, nmin));
    }
    if (!s2.empty()) s2.pop();
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<int> v;
    v.push_back(x);
    for (int i = 1 ; i < n ; i ++ ) {
        v.push_back((a * v[i - 1] + b) % c);
    }
    stack<pair<int, int>> s1, s2;
    vector<int> mins;
    for (int i = 0 ; i < k && i < n ; i ++ ) {
        int nmin = s1.empty() ? v[i] : min(v[i], s1.top().second);
        s1.push(make_pair(v[i], nmin));
    }
    mins.push_back(s1.top().second);
    for (int i = k ; i < n ; i ++) {
        pop_two_stack(s1, s2);
        int nmin = s1.empty() ? v[i] : min(v[i], s1.top().second);
        s1.push(make_pair(v[i], nmin));
        nmin = 1e11;
        if (!s1.empty()) nmin = min(nmin, s1.top().second);
        if (!s2.empty()) nmin = min(nmin, s2.top().second);
        mins.push_back(nmin);
    }
    int fmin = mins[0];
    for (int i = 1 ; i < mins.size() ; i ++) fmin ^= mins[i];
    cout << fmin << "\n";
}
