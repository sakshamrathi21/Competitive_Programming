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
        set<char> ocs;
        for (int i = 0 ; i < s.length() ; i ++ ) {
            ocs.insert(s[i]);
        }
        vector<char> vc;
        for (auto c : ocs) vc.push_back(c);
        map<char, char> mcs;
        for (int i = 0 ; i < vc.size() ; i ++) {
            mcs[vc[i]] = vc[vc.size()-1-i];
        }

        for (int i = 0 ; i < s.length() ; i ++) {
            cout << mcs[s[i]];
        }
        cout << "\n";
    }
}
