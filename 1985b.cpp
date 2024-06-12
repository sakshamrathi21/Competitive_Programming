/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 20:11:00 IST 2024
**/


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
        int max_sum = -1, max_k;
        for (int x = 2 ; x <= n ; x ++) {
            int curr_sum = 0;
            for (int i = x ; i <= n ; i +=x) {
                curr_sum += i;
            }
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_k = x;
            }
        }
        cout << max_k << "\n";

    }
}
