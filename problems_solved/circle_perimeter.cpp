#include<bits/stdc++.h>
using namespace std;
#define int long long

int binary_search(int r, int x) {
    int low = 0;
    int high = 2*r;
    while (low < high) {
        // cout << low << " check" << high << endl;
        int mid = (low+high)/2;
        if (mid*mid == r*r-x*x) return mid;
        if (mid*mid < r*r-x*x) {
            low = mid+1;
        }
        else {
            high = mid;
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
        int r;
        cin >> r;
        int count = 0;
        for (int i = 1 ; i <= r ; i ++) {
            // cout << " hello " << i << " " << r << endl;
            count += 4*(binary_search(r+1, i)-binary_search(r, i));
            // cout << i << " " << binary_search(r+1, i) << " " << binary_search(r, i) << endl;
        }
        // count += 4;
        cout << count << endl;
    }
}
