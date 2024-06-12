#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    ll maxMovies = 0;
    multiset<ll> end_times;
    for (int i = 0 ; i < k ; i ++) {
        end_times.insert(0);
    }
    for (int i = 0 ; i < n ; i ++ ) {
        auto it = end_times.upper_bound(v[i].second);
        if (it == begin(end_times)) continue;
        end_times.erase(--it);
        end_times.insert(v[i].first);
        ++maxMovies;
    }
    cout << maxMovies;
}
