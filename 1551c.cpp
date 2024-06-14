/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 21:07:03 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> s[i];
        }
        vector<vector<int>> freq(n, vector<int>(5, 0));
        vector<vector<int>> val(5, vector<int>(n, 0));
        for (int i = 0 ; i < n ; i ++ ) {
            for (int j = 0 ; j < s[i].length() ; j ++) {
                freq[i][s[i][j]-'a'] += 1;
            }
            int tot = 0;
            for (int j = 0 ; j < 5 ; j ++) {
                tot += freq[i][j];
            }
            for (int j = 0 ; j < 5 ; j ++ ) val[j][i] = 2*freq[i][j]-tot;
        }
        int ms = 0;
        for (int i = 0 ; i < 5 ; i ++) {
            sort(val[i].begin(), val[i].end());
            reverse(val[i].begin(), val[i].end());
            int sum = 0;
            int el = 0;
            for (int j = 0 ; j < n ; j ++) {
                sum += val[i][j];
                if (sum <= 0) break;
                el++;
            }
            ms = max(ms, el);
        }
        cout << ms << "\n";
    }
}
