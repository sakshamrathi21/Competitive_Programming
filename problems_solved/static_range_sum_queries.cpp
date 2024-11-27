#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll sum[n+1];
    sum[0] = 0;
    int num;
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> num;
        sum[i+1] = sum[i] + num;
    }
    int a, b;
    for (int i = 0 ; i < q ; i ++ ) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
}
