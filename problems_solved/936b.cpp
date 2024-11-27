#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int power(int s, int k){
    if (k == 0) return 1;
    if (k == 1) return s;
    int ps = power(s, k/2);
    if (k%2 == 0) {
        return ((ps%MOD)*(ps%MOD)%MOD);
    }
    return (((ps%MOD)*(ps%MOD)%MOD)*s%MOD);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) cin >>a[i];
        int max_cnt_sum = 0;
        int min_val = 1e9, max_val = -1e9;
        for (int i = 0 ; i < n ; i ++) {
            min_val = min(min_val, a[i]);
            max_val = max(max_val, a[i]);
        }
        if (max_val > 0) {
            int cs = 0;
            for (int i = 0 ; i < n ; i ++) {
                cs += a[i];
                max_cnt_sum = max(max_cnt_sum, cs);
                if (cs < 0) cs = 0;
            }
        } 
        int ts = 0;
        for (int i = 0 ; i < n ; i ++) ts+=a[i]%MOD;
        if (k ==0 ) {
            cout << (ts%MOD) << "\n";
        }
        else {
            // cout << (-11)%MOD << endl;
             cout << (((ts%MOD)-(max_cnt_sum%MOD)+(power(2, k)*max_cnt_sum%MOD)+MOD)%MOD) << "\n";
        }
    }
}
