#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int lst = a.back();
        int cnt = 1;
        a.pop_back();
        while (!a.empty() && lst == a.back()) {
            cnt++;
            a.pop_back();
        }
        while (!a.empty()) {
            int delta = a.back() - lst;
            if (k < delta*cnt) break;
            k -= delta*cnt;
            lst = a.back();
            while (!a.empty() && lst == a.back()) {
                cnt++;
                a.pop_back();
            }
        }
        lst += k/cnt;
        k %= cnt;
        cnt -= k;
        cout << lst*n - cnt +1 << "\n";
    }
}
