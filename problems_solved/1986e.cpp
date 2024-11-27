/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 23 20:54:57 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        // map<int, int> cnt;
        map<int, vector<int>> modk;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i]%k == 0) modk[k].push_back(a[i]);
            else modk[a[i]%k].push_back(a[i]);
        }
        int odd = -1;
        bool poss = true;
        int tot = 0;
        for (auto &e: modk) {
            
            if (e.second.size()%2 == 1) {
                if (odd == -1) odd = e.first;
                else {
                    poss = false;
                    break;
                }
            }
            sort(e.second.begin(), e.second.end());
            if (e.second.size() == 1) continue;
            int cnt = 0;
            if (e.second.size()%2 == 1) {
                vector<int> odd_sum(e.second.size(), 0);
                vector<int> even_sum(e.second.size(), 0);
                even_sum[1] = (e.second[1]-e.second[0])/e.first;
                for (int i = 2 ; i+1 < e.second.size() ; i += 2) {
                    even_sum[i] = even_sum[i-1];
                    even_sum[i+1] = even_sum[i] + (e.second[i+1]-e.second[i])/e.first;
                }
                for (int i = 1 ; i+1 < e.second.size() ; i+= 2) {
                    odd_sum[i] = odd_sum[i-1];
                    odd_sum[i+1] = odd_sum[i] + (e.second[i+1]-e.second[i])/e.first;
                }
                cnt = LLONG_MAX;
                for (int i = 1 ; i < e.second.size() - 1; i ++) {
                    if (i%2) {
                        cnt = min(cnt, even_sum[i-1]+odd_sum[e.second.size()-1]-odd_sum[i]+e.second[i+1]-e.second[i-1]);
                    }
                    else {
                        cnt = min(cnt, even_sum[i-1]+odd_sum[e.second.size()-1]-odd_sum[i]);
                    }
                    cnt = min(cnt, even_sum[e.second.size()-2]);
                    cnt = min(cnt, odd_sum[e.second.size()-1]);
                }
            }
            else {
                for (int i = 0 ; i+1 < e.second.size() ; i += 2) {
                    // cout << "hello" << e.first << endl;
                    cnt += (e.second[i+1]-e.second[i])/e.first;
                }
            }
            tot += cnt;
        }
        if (poss) {
            cout << tot << "\n";
        }
        else {
            cout << "-1\n";
        }

    }
}
