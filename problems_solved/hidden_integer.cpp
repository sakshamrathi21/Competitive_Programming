/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 11 16:22:40 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

map<int, bool> queries;

bool out_in(int num) {
    if (queries.find(num) != queries.end()) return queries[num];
    cout << "? " << num << endl;
    string s;
    cin >> s;
    if (s == "YES") return queries[num] = true;
    return queries[num] = false;
}

int find_x(int left, int right) {
    if (right == 2 || right == 3) {
        cout << "! 1" << endl;
        return 1;
    }
    if (right - left <= 2) {
        if (out_in(left)) {
            cout << "! " << left + 1 << endl; 
        }
        else cout << "! " << left << endl;
        return 0;
    }
    int mid = (left + right) / 2;
    bool res = out_in(mid);
    if (res) {
        return find_x(mid + 1, right);
    }
    return find_x(left, mid + 1);
}

void solve() {
    find_x(1, 1e9 + 1);
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
