#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ni = s.length();
        for (int i = 0 ; i < s.length() ; i ++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ni = i;
                break;
            }
        }
        // cout << ni << endl;
        bool possible = true;
        if (ni != 0 && (s[0]< '0' || s[0] > '9')) possible = false;
        for (int i = 1 ; i < ni ; i ++) {
            // cout << "hello " << possible << i <<  endl;
            if (s[i] < '0' || s[i] > '9') {
                possible = false;
                break;
            }
            
            if (s[i-1] > s[i]) {
                possible = false;
                break;
            }
        }
        
        if (ni < s.length()) {
            if (s[ni]< 'a' || s[ni] > 'z') possible = false;
            for (int i = ni+1 ; i < s.length() ; i ++) {
                if (s[i] < 'a' || s[i] > 'z') {
                    possible = false;
                    break;
                }
                if (s[i-1] > s[i]) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}
