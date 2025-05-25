/**
 *    Author: Saksham Rathi
 *    Created: Sun May 25 08:55:55 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n), l(n), r(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> d[i];
    }
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> l[i] >> r[i];
    }
    int left = 0;
    vector<int> unknowns;
    for (int i = 0 ; i < n ; i ++)
    {
        if (d[i] == -1)
        {
            unknowns.push_back(i);
        }
        else
        {
            left += d[i];
        }
        while (left < l[i])
        {
            if (unknowns.size() == 0)
            {
                cout << "-1\n";
                return;
            }
            d[unknowns[unknowns.size() - 1]] = 1;
            left++;
            unknowns.pop_back();
        }
        while (left + unknowns.size() > r[i])
        {
            if (unknowns.size() == 0)
            {
                cout << "-1\n";
                return;
            }
            d[unknowns[unknowns.size() - 1]] = 0;
            unknowns.pop_back();
        }
    }
    for (int i = 0 ; i < n ; i ++)
    {
        cout << max(d[i], 0LL) << " ";
    }
    cout << "\n";
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
