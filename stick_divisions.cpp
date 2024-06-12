#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int i = 0 ; i < n ; i ++ ) {
        int a;
        cin >> a;
        PQ.push(a);
    }

    int ans = 0;
    for (int i = 1 ; i < n ; i ++ ) {
        int a = PQ.top();
        PQ.pop();
        int b = PQ.top();
        PQ.pop();
        PQ.push(a+b);
        ans += (a+b);
    }
    cout << ans;
    return 0;
}
