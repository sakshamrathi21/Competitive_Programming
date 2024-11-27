/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 20:54:39 IST 2024
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
        string s;
        cin >> s;
        int curr = 0;
        vector<int> lens;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (s[i] == 'A') curr++;
            else {
                lens.push_back(curr);
                curr = 0;
            }
        }
        
        if (curr != 0) lens.push_back(curr);
        sort(lens.begin(), lens.end());
        int tot = 0;
        
        for (int i = 0 ; i < s.length() ; i ++) if (s[i] == 'A') tot++;
        // cout << " hello " << endl;
        if (s[0] == 'B' || s[s.length()-1] == 'B') cout << tot << "\n";
        else cout << tot-lens[0] << "\n";

    }
}
