#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll t[n];
    for (int i = 0 ; i < n ; i ++ ) {
        cin  >> t[i];
    }

    sort(t, t+n);
    ll sum = 0 ;
    for (int i = 0 ; i < n - 1 ; i ++ ) {
        sum += t[i];
    }
    if (sum < t[n-1]) {
        cout << 2*t[n-1] << '\n';
    }
    else {
        cout << sum + t[n-1] << '\n';
    }
}
