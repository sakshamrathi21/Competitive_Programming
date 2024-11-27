#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    ll ans = 0;
    unordered_map<ll, ll> mp;
    ll start = 0;
    ll end = 0;
    ll unique = 0;
    while(end < n) {
        mp[arr[end]]++;
        if(mp[arr[end]] == 1) unique++; 
        if(unique > k) {
            ans+=((end-start)*(end-start+1))/2;
            while(start <= end && unique > k) {
                mp[arr[start]]--;
                if(mp[arr[start]] == 0) { unique--; }
                start++;
            }
            ans-=((end-start)*(end-start+1))/2;
        }
        end++;
    }
    ans+=((end-start)*(end-start+1))/2;
    cout << ans << "\n";
}
