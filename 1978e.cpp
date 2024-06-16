/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 15:57:43 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p2.second < p1.second;
}

int binSearch(vector<int> &ld, int low, int high, int val) {
    if (high - low <= 1) {
        if (ld[low] == val) return low;
        if (high < ld.size() && ld[high] <= val) return high;
        return  low;
    }
    int mid = (low+high)/2;
    if (ld[mid] < val)

}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        vector<int> cnt(n+1);
        // cnt[0] = (s[0]-'0');
        cnt[0] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            cnt[i] = cnt[i-1]+(s[i-1]-'0');
        }
        map<int, int> depen;
        vector<bool> alread(n, false);
        for (int i = 0 ; i < n-2 ; i ++) {
            if (s[i] == '0' && s[i+2] == '0' && t[i+1] == '0') {
                t[i+1] = '1';
                alread[i+1] = true;
            }
        }
        vector<int> l, r;
        for (int i = 0 ; i < n -2 ; i ++) {
            if (t[i] == '1' && t[i+2] == '1' && s[i+1] != '1') {
                s[i+1] = '1';
                int m1 = i, m2 = i+2;
                if (alread[i]) m1 = i-1;
                if (alread[i+2]) m2 = i+3;
                l.push_back(m1);
                r.push_back(m2);
            }
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << cnt[r]-cnt[l-1] << "\n";
        }

    }
}
