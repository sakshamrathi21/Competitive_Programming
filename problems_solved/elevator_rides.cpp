#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int weights[n];
    for (int i = 0 ; i < n ; i ++ ) cin >> weights[i];
    pair<int, int> best[1<<n];
    best[0] = {1, 0};
    for (int s = 1 ; s < (1 << n) ; s ++ ) {
        best[s] = {n+1, 0};
        for (int p = 0 ; p < n ; p ++ ) {
            if (s & (1<<p)) {
                auto option = best[s^(1<<p)];
                if (option.second + weights[p] <= x) option.second += weights[p];
                else {
                    option.first ++;
                    option.second = weights[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    cout << best[(1<<n)-1].first;
    return 0;
}
