#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> xy;
    ll x, y;
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> x >> y;
        xy.push_back({x, y});
    }

    ll result = 0;

    for (int i = 0 ; i < n ; i ++ ) {
        result += xy[i%n].first*xy[(i+1)%n].second - xy[i%n].second*xy[(i+1)%n].first;
    }
    cout << abs(result) << '\n';
}
