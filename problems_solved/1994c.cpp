/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 18 20:30:28 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dp;
int x;

int binSearh(vector<int>&p, int val, int low, int high) {
    // cout << " hello " << val << low << high << endl;
    if (high-low <= 1) {
        if (low < p.size() && p[low] >= val) return low;
        if (high < p.size() && p[high] >= val) return high;
        return -1;
    }
    // for (int i = low; i < high ; i ++) {
    //     cout << p[i] << " ";
    // }
    // cout << " hello " << val << endl;
    int mid = (low+high)/2;
    if (p[mid] == val) return mid;
    if (p[mid] < val) return binSearh(p, val, mid+1, high);
    return binSearh(p, val, low, mid);
}

int dc(vector<int> &a, vector<int> &p, int pos) {
    if (pos >= a.size()) return 0; 
    if (dp[pos] != -1) return dp[pos];
    if (a[pos] > x) {
        return dp[pos] = dc(a, p, pos+1);
    }
    int ind;
    if (pos == 0) ind = binSearh(p, x+1, pos+1, a.size());
    else ind = binSearh(p, x+p[pos-1]+1, pos+1, a.size());
    // cout << " hello " << pos << ind << endl;
    if (ind == -1) return dp[pos] = (a.size()-pos);
    return dp[pos] = (ind-pos)+dc(a, p, ind+1);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<int> p(n);
        p[0] = a[0];
        for (int i = 1; i < n ; i ++) {
            p[i] = p[i-1] + a[i];
        }
        dp.assign(n, -1);
        for (int i = 0 ; i < n ; i ++) {
            dc(a, p, i);
        }
        int sum = 0;
        for (int i = 0 ; i < n ; i ++) {
            sum += dp[i];
            // cout << " check " << dp[i] << endl;
        }
        cout << sum << "\n";
    }
}
