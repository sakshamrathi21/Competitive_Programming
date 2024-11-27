/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul 30 20:51:54 IST 2024
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
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;
        for (int i = 1 ; i < n-1 ; i ++ ) {
            if (s1[i-1] == 'x' && s1[i+1] == 'x' && s1[i] == '.' && s2[i-1] == '.' && s2[i+1] == '.' && s2[i] == '.') cnt++;
            if (s2[i-1] == 'x' && s2[i+1] == 'x' && s2[i] == '.' && s1[i-1] == '.' && s1[i+1] == '.' && s1[i] == '.') cnt++;
        }
        cout << cnt << "\n";
    }
}
