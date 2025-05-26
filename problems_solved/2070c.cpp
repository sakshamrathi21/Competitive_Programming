/**
 *    Author: Saksham Rathi
 *    Created: Mon May 26 10:41:25 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool check(string &s, int max_p, vector<int>&a, int k)
{  
    // cout << max_p << " " << k << endl;
    string m;
    int n = a.size();
    for (int i = 0 ; i < n ; i ++)
    {
        if (a[i] > max_p) m.push_back(s[i]);
    }
    if (m.size() == 0) return true;
    int num_c = 0;
    for (int i = 0 ; i < m.size() - 1 ; i ++)
    {
        if (m[i] == 'B' && m[i+1] == 'R') num_c++;
    }
    if (m[m.size() - 1] == 'B') num_c++;
    return num_c <= k; 
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    int left = 0, right = 1e16;
    while (right - left > 2)
    {
        int mid = (left + right)/2;
        if (check(s, mid, a, k)) right = mid + 1;
        else left = mid;
    }
    if (check(s, left, a, k)) cout << left << "\n";
    else if (check(s, left + 1, a, k)) cout << left + 1 << "\n";
    else cout << right << "\n";
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
