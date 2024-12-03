/**
 *    Author: Saksham Rathi
 *    Created: Tue Dec  3 07:10:34 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0 ; t < T ; t ++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> diff;
        int current_diff = 0;
        for (int i = s.length()-1 ; i >= 1 ; i --) {
            if (s[i] == '0') current_diff--;
            else current_diff ++;
            diff.push_back(current_diff);
        }
        // diff[0] = INT32_MIN;
        sort(diff.begin(), diff.end());
        reverse(diff.begin(), diff.end());
        int ans = 0;
        while (ans < n) {
            // cout << " hello " << diff[ans] << endl;
            k -= diff[ans];
            ans ++;
            if (k <= 0) break;
        }
        if (ans == n) cout << "-1\n";
        else cout << ans+1 << "\n";
    }
}
