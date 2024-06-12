#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x;
vector<ll> a;
ll total_sum = 0;

int subset_generator(vector<int> current_subset, ll current_index) {
    // cout << current_subset.size() << endl;
    if (current_index >= n) return 0;
    ll sum = 0;
    for (ll i = 0 ; i < current_subset.size() ; i ++ ) {
        sum += current_subset[i];
    }
    ll count = 0;
    if (sum == x) {
        count ++;
        // cout << " hello " << current_subset.size() << endl;
    }
    if (total_sum - sum == x) {
        if (n%2 == 0 && current_subset.size() == n/2) count --;
        count ++;
    }
    if (current_subset.size() > (n+1)/2) return count;
    if (sum > x) return 0;
    else if (current_subset.size() <= (n+1)/2-1) {
        for (ll i = current_index ; i < n ; i ++ ) {
            current_subset.push_back(a[i]);
            count += subset_generator(current_subset, i);
            current_subset.pop_back();
        }
    }
    return count;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;
    ll t;
    
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> t;
        a.push_back(t);
        total_sum += t;
    }
    vector<int> current_subset;
    cout << subset_generator(current_subset, 0);
}
