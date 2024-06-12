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
        string s;
        cin >> s;
        // int len = s.length();
        if (n ==0) {
            cout << s<<"\n";
            continue;
        }
        string t = s;
        reverse(s.begin(), s.end());
        
        
        if (s<t) {
                cout << s+t << "\n";
        }
        else {
            cout << t << "\n"; 
        }
    }
}
