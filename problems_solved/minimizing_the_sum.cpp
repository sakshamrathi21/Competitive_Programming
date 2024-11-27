#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp_cal(int n, int k) {
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> a[i];
    }
    if (n == 1) return a[0];
    for (int i = 0 ; i < k ; i ++ ) {
        int max_diff = 0;
        int element_update = -1;
        if ((a[0]-a[1]) > 0){max_diff = a[0]-a[1]; element_update = 0;}
        if ((a[n-1]-a[n-2])>max_diff) {max_diff = a[n-1]-a[n-2]; element_update = n-1;}
        // int max_diff = max(a[0]-a[1], 0);
        for (int j = 1 ; j < n-1; j ++) {
            if ((a[j]-a[j-1]) > max_diff) {
                max_diff = a[j]-a[j-1];
                element_update = j;
            }
            if ((a[j]-a[j+1]) > max_diff) {
                max_diff = a[j]-a[j+1];
                element_update = j;
            }
        }
        if (element_update != -1) {
            a[element_update] -= max_diff;
        }
    }
    int sum = 0;
    for (int i = 0 ; i < n ; i ++ ) {
        sum += a[i];
    }
    return sum;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n, k;
    for (int i = 0 ; i < t ; i ++) {
        cin >> n >> k;
        cout << dp_cal(n, k) << endl;
    }
    
}
