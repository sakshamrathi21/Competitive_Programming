/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 18 07:51:58 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int ms(string s, vector<int> &pos) {
    
    int l = 0, t = 0, i = 0;
    int n = s.length();
    for (int j = 0 ; j < n ; j ++) {
        if (s[j] == 'L') l++;
        else if (s[j] == 'T') t++;
        else if (s[j] == 'I') i++;
    }
    if (l == t && t == i) return pos.size();
    // cout << " hello " << s << " " << t << " " << i << " " << l << endl;
    for (int j = 0 ; j < n - 1 ; j ++) {
        if (l < max(max(l, t), i) && ((s[j] == 'T' && s[j+1] == 'I') || (s[j] == 'I' && s[j+1] == 'T'))) {
            string t = s;
            t.insert(t.begin() + j + 1, 'L');
            pos.push_back(j);
            int m = ms(t, pos);
            if (m != -1) return m;
        }
        if (t < max(max(l, t), i) && ((s[j] == 'L' && s[j+1] == 'I') || (s[j] == 'I' && s[j+1] == 'L'))) {
            string t = s;
            t.insert(t.begin() + j + 1, 'T');
            pos.push_back(j);
            int m = ms(t, pos);
            if (m != -1) return m;
        }
        if (i < max(max(l, t), i) && ((s[j] == 'T' && s[j+1] == 'L') || (s[j] == 'L' && s[j+1] == 'T'))) {
            string t = s;
            t.insert(t.begin() + j + 1, 'I');
            pos.push_back(j);
            int m = ms(t, pos);
            if (m != -1) return m;
        }
    }
    for (int j = 0 ; j < n - 1 ; j ++) {
        if (l == max(max(l, t), i) && ((s[j] == 'T' && s[j+1] == 'I') || (s[j] == 'I' && s[j+1] == 'T'))) {
            string t = s;
            t.insert(t.begin() + j + 1, 'L');
            pos.push_back(j);
            int m = ms(t, pos);
            if (m != -1) return m;
        }
        if (t == max(max(l, t), i) && ((s[j] == 'L' && s[j+1] == 'I') || (s[j] == 'I' && s[j+1] == 'L'))) {
            string t = s;
            t.insert(t.begin() + j + 1, 'T');
            pos.push_back(j);
            int m = ms(t, pos);
            if (m != -1) return m;
        }
        if (i == max(max(l, t), i) && ((s[j] == 'T' && s[j+1] == 'L') || (s[j] == 'L' && s[j+1] == 'T'))) {
            string t = s;
            t.insert(t.begin() + j + 1, 'I');
            pos.push_back(j);
            int m = ms(t, pos);
            if (m != -1) return m;
        }
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    int m = ms(s, pos);
    cout << m << endl;
    for (auto p : pos) cout << p + 1 << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
