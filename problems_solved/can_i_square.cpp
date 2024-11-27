#include<bits/stdc++.h>
using namespace std;
// #define int long long

int square_search(int x) {
    int low = 0;
    int high = x;
    while (low < high) {
        // cout << low << " hello " <<high<< endl;
        int mid = (low+high)/2;
        if (x == mid*mid) return mid;
        if (x > mid*mid) {
            low = mid;
        }
        else {
            high = mid;
        }
        if (high - low == 1) {
            if (x == low*low) return low;
            else return high;
        }
    }
    return low;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = 0 ;
        for (int i = 0 ; i < n ; i ++) {
            long long x;
            cin >> x;
            sum += x;
        }
        
        if (long(sqrt(sum))*long(sqrt(sum)) == sum) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
