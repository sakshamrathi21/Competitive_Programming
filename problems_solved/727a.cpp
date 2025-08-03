/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug  3 10:18:55 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

map<int, int> parent;

int num_steps(int current_num, int target_num) {
    if (current_num > target_num) return -1;
    if (current_num == target_num) return 0;
    if (num_steps(2*current_num, target_num) != -1) {parent[current_num] = 2*current_num; return 1;}
    else if (num_steps(10*current_num + 1, target_num) != -1) {parent[current_num] = 10*current_num+1; return 1;}
    else return -1;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (num_steps(a, b) == -1) {cout << "NO\n"; return;}
    cout << "YES\n";
    vector<int> s;
    s.push_back(a);
    for (int i = parent[a] ; i != b ; i = parent[i]) s.push_back(i);
    s.push_back(b);
    cout << s.size() << "\n";
    for (auto i : s) cout << i << " ";
    cout << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
