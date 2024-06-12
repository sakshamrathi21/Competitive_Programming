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
        int mat[2][n];
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0 ; i < n ; i ++) {
            mat[0][i] = s1[i]-'0';
            mat[1][i] = s2[i]-'0';
        }
        vector<vector<int>> nxt(2, vector<int>(n));
        vector<vector<int>> cnt(2, vector<int>(n));
        for (int i = n - 1 ; i >= 0 ; i --){
            cnt[1][i] = 1;
        }
        for (int i = n - 1 ; i >= 0 ; i --) {
            
        }
    }
}
