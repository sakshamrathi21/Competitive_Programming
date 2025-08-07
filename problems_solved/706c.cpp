/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug  7 09:43:26 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

vector<string> a;
int n;
vector<int> c;
map<pair<int, pair<int, int>>, int> dp;

int calc_dp(int last_pos, int whether_reverse, int whether_last_reversed, string last_string) {
    pair<int, pair<int, int>> pf = make_pair(last_pos, make_pair(whether_reverse, whether_last_reversed));
    // cout << " hello " << last_pos << " " << whether_reverse << endl;
    if (last_pos == -1) return 0;
    if (dp.find(pf) != dp.end()) return dp[pf];
    
    string reversed_string = a[last_pos];
    if (whether_reverse) reverse(reversed_string.begin(), reversed_string.end());
    int cost = -1;
    bool condition = last_string == "" ? true : reversed_string <= last_string;
    if (condition) {
        int cost1 = calc_dp(last_pos - 1, 0, whether_reverse, reversed_string);
        int cost2 = calc_dp(last_pos - 1, 1, whether_reverse, reversed_string);
        if (cost1 != -1 && cost2 != -1) cost = min(cost1, cost2);
        else if (cost1 != -1) cost = cost1;
        else if (cost2 != -1) cost = cost2;
    }
    if (whether_reverse && cost != -1) cost += c[last_pos];
    // cout << last_pos << " " << whether_reverse << " " << reversed_string << " " << last_string << " " << condition << " " << cost << endl;
    return dp[pf] = cost;
}


void solve() {
    cin >> n;
    a.resize(n);
    c.resize(n);
    for (int i = 0 ; i < n ; i ++) cin >> c[i];
    for (int i = 0 ; i < n ; i ++) cin >> a[i];
    int cost = -1;
    int cost1 = calc_dp(n - 1, 0, -1, "");
    int cost2 = calc_dp(n - 1, 1, -1, "");
    if (cost1 != -1 && cost2 != -1) cost = min(cost1, cost2);
    else if (cost1 != -1) cost = cost1;
    else if (cost2 != -1) cost = cost2;
    cout << cost << "\n";
    
}
signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
