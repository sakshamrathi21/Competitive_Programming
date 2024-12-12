/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec 12 19:19:12 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

bool valid(string & s) {
    int n = s.length();
    for (int i = 0 ; i < n - 1 ; i ++ ) {
        if (s[i + 1] >= s[i] + 2) return true;
    }
    return false;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        while (valid(s)) {
            for (int i = 0 ; i < n - 1 ; i ++ ) {
                if (s[i + 1] >= s[i] + 2) {swap(s[i], s[i+1]); s[i]--;}
            }
        }
        cout << s << "\n";
    }
}
