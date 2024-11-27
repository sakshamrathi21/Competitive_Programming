/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 18 08:13:32 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> factors(100000);


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1 ; i <= 100000 ; i ++) {
        for (int j = 1 ; j <= i ; j ++) {
            if (i%j == 0) factors[i].push_back(j);
        }
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int left = 0, right = n-1;
        int cnt = 0;
        vector<int> freq(m, 0);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < factors[a[i]].size() ; j ++) {
                freq[factors[a[i]][j]]++;
                if (freq[factors[a[i]][j]] == 1) cnt++;
            }
        }

        if (cnt != m) {
            cout << "-1\n";
            continue;
        }
        int diff = -1;
        while (left < right) {
            if (cnt == m) {
                for (int i = 0 ; i < factors[a[left]].size() ; i ++) {
                    freq[factors[a[left]][i]]--;
                    if (freq[factors[a[left]][i]] == 0) cnt--;
                }
                if (cnt == m) {
                    left++;
                    continue;
                }
                else {
                    for (int i = 0 ; i < factors[a[left]].size() ; i ++) {
                        freq[factors[a[left]][i]]--;
                        if (freq[factors[a[left]][i]] == 0) cnt--;
                    }
                }
            }
            else {

            }
        }

    }
}
