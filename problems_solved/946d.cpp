#include<bits/stdc++.h>
using namespace std;
#define int long long





signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int nn = 0, ns = 0, ne = 0, nw = 0;
        if (s.length()< 2) {
            cout << "NO" << "\n";
            continue;
        }
        if (s.length() == 2 && s[0] != s[1]) {
            cout << "NO" << "\n";
            continue;
        }
        if (s.length() == 2 && s[0] == s[1]) {
            cout << "RH" << "\n";
            continue;
        }
        for (int i = 0 ; i < s.length() ; i ++ ) {
            if (s[i] == 'N') nn++;
            if (s[i] == 'S') ns++;
            if (s[i] == 'E') ne++;
            if (s[i] == 'W') nw++;
        }
        if (abs(nn-ns)%2 == 1 || abs(ne-nw)%2 == 1) {
            cout << "NO" << "\n";
            continue;
        }
        if (ns == nn && ne == nw) {
            if ((nn+ne)%2) {
                cout << "NO" << "\n";
                continue;
            }
            else {
                for (int i = 0 ; i < s.length() ; i ++ ) {
                    if (s[i] == 'N' || s[i] == 'S') cout << "R";
                    else cout << "H";
                }
                cout << '\n';
                continue;
            }
        }
        if (ns == nn) {

        } 
    }
}
