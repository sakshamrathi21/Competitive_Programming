/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 21 20:00:40 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fb;

void precmp() {
    fb.push_back(1);
    fb.push_back(1);
    int prev = 1;
    int curr = 2;
    while (curr < 1e11+1) {
        fb.push_back(curr);
        curr = (curr+prev);
        prev = (curr-prev);
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    precmp();
    while (t--) {
        int k;
        cin >> k;
        vector<int> c(k);
        int sum = 0;
        for (int i = 0 ; i < k ; i ++) {
            cin >> c[i];
            sum += c[i];
        }
        int i;
        for (i = 0 ; i < fb.size() ; i ++) {
            sum -= fb[i];
            if (sum <= 0) break;
        }
        if (sum < 0) {
            cout << "NO\n";
            continue;
        }
        set<pair<int, int>> s;
        for (int i = 0 ; i < k ; i ++) {
            s.insert(make_pair(c[i], i));
        }
        bool poss = true;
        int prev = -1;
        while (s.size() > 0 && i >= 0) {
            pair<int, int> curr = *s.rbegin();
            
            s.erase(curr);
            if (curr.first < fb[i]) {
                poss = false;
                break;
            }
            // cout << curr.first << " hello " << curr.second << s.size() << endl;
            if (curr.second == prev) {
                pair<int, int> curr2;
                if (s.size() > 0) curr2 =  *s.rbegin();
                else {
                    poss = false;
                    break;
                }
                if (curr2.first < fb[i]) {
                    poss = false;
                    break;
                }
                s.erase(curr2);
                s.insert(curr);
                curr2.first -= fb[i];
                i--;
                prev = curr2.second;
                if (curr2.first > 0) s.insert(curr2);
            }
            else {
                curr.first -= fb[i];
                i--;
                prev = curr.second;
                if (curr.first > 0) s.insert(curr);
            }
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
