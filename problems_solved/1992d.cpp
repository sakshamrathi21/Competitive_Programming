/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 11 20:34:12 IST 2024
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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        s = "L"+s;
        int cur_pos = 0;
        int ws = 0;
        while (cur_pos <= n) {
            // cout << ws << " hello " << cur_pos << endl;
            if (ws > k) break;
            if (s[cur_pos] == 'C') break;
            if (s[cur_pos] == 'W') {
                ws ++;
                cur_pos++;
            }
            else {
                int lf = -1, wf = -1;
                if (m+cur_pos >= n+1) {
                    cur_pos += m;
                    break;
                }
                for (int i = m ; i >= 1 ; i --) {
                    if (lf == -1 && s[cur_pos+i] == 'L') lf = cur_pos+i;
                    else if (wf == -1 && s[cur_pos + i] == 'W') wf = cur_pos+i;
                }
                // cout << wf << " check " << lf << endl;
                if (lf != -1) cur_pos = lf;
                else if (wf != -1) cur_pos = wf;
                else break;
            }
        }
        if (ws > k || cur_pos <= n) {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
}
