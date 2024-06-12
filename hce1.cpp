#include<bits/stdc++.h>
using namespace std;
#define int long long

int m, n;
vector<vector<int> > dp;
vector<int> s;
vector<int> l;
int sl_sum = 0, s_sum = 0;

int total_trails(int cb, int d) {
    // cout << cb << " hello " << d << " " << dp[cb][d] << endl;
    if (d == 0) {
        if (cb == 1) return 1;
        return 0;
    }
    // 
    if (dp[cb][d] != -1) return dp[cb][d];
    
    int ret_cnt = 0;
    for (int i = 0 ; i < m ; i ++ ) {
        ret_cnt += total_trails(i, d-1)*((s[cb]+l[cb])*(s[i]+l[i])-l[cb]*l[i]);
    }
    dp[cb][d] = ret_cnt;
    return dp[cb][d];
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for (int i = 0 ; i < m ; i ++ ) {
        dp.push_back(vector<int>(n+1, -1));
    }

    for (int i = 0 ; i < m ; i ++) {
        int x;
        cin >> x;
        s.push_back(x);
    }

    for (int i = 0 ; i < m ; i ++) {
        int x;
        cin >> x;
        l.push_back(x);
    }
    dp[0][0] = 1;
    for (int i = 1 ; i < m ; i ++) {
        dp[i][0] = 0;
    }

    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 0 ; j < m ; j ++) {
            int cnt = 0;
            for (int k = 0 ; k < m ; k ++ ) {
                // cout << " hello ";
                cnt += (((s[k]+l[k])*(s[j]+l[j])-(l[k]*l[j]))*dp[k][i-1]%(1000000007));
                // cout << cnt << endl;
            }
            dp[j][i] = cnt%1000000007;
        }
    }

    for (int i = 0 ; i < m ; i ++) {
        (sl_sum += dp[i][n])%1000000007;
    }

    cout << sl_sum%1000000007;

}
