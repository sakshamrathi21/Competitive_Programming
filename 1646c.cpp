/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  9 10:00:48 IST 2024
**/
 
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
int wpt(int n) {
    int curr = 1;
    while (curr < n) curr*=2;
    if (curr == n) return curr;
    else return curr/2;
}
vector<int> ft(16);
vector<int> subt(1<<15, 0);
vector<int> subs(1<<15, 0);
int fact(int num) {
    int i = 0;
    while (i < ft.size() && num > ft[i]) i++;
    if (ft[i] == num) return ft[i];
    else return ft[i-1];
}
 
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    ft[0] = 1;
    for (int i = 1 ; i < 16 ; i ++) {
        ft[i] = ft[i-1]*i;
    }
    for (int i = 0 ; i < (1<<15) ; i ++ ){
        for (int j = 0 ; j < 15 ; j ++) {
            if (i & (1<<j)) {subt[i] += ft[j]; subs[i]++;}
        }
    }
    while (t--) {
        int n;
        cin >> n;
        int ms = LLONG_MAX;
        for (int i = 0 ; i < subt.size() ; i ++ ) {
            if (subt[i] > n) continue;
            ms = min(ms, __builtin_popcountll(n-subt[i])+subs[i]);
        }
        cout << ms << "\n";
    }
}