#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> freq(7, 0);
        for (int i = 0 ; i < n ; i ++) {
            char c;
            cin >> c;
            freq[c-'A']++;
        }
        int cnt = 0;
        for (int i = 0 ; i < 7 ; i ++) {
            if (freq[i] < m) {
                cnt += (m-freq[i]);
            }
        }
        cout << cnt << "\n";
    }
}
