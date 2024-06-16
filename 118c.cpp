/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 10:54:19 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(const pair<int, int> &b, const pair<int, int> &c) {
    if (b.first != c.first) return b.first < c.first;
    return b.second > c.second;
}

pair<int, string> cs(string s, int ind, int m, int n) {
    vector<pair<int, int>> a;
        
        for (int i = 0 ; i < 10 ; i ++) {
            if (i == ind) continue;
            a.push_back(make_pair(abs(ind-i), i));
        }
        
        sort(a.begin(), a.end(), cmp);
        // cout << " hello " << a[1].second << endl;
        int cost = 0;
        int curr = 0;
        for (int i = 0 ; i < a.size() ; i++) {
            if (curr >= m) break;
            // cout << a[i].second << " hello " << curr << m << endl;
            if (a[i].second > ind) {
                for (int j = 0 ; j < n ; j ++) {
                    if (s[j] == ('0'+a[i].second)) {
                        // cout << "check " << j << i << endl;
                        curr++;
                        s[j] = '0'+ind;
                        cost += a[i].first;
                        if (curr >= m) break;
                    }
                }
            }
            else {
                for (int j = n-1 ; j >= 0 ; j --) {
                    if (s[j] == ('0'+a[i].second)) {
                        curr++;
                        s[j] = '0'+ind;
                        cost += a[i].first;
                        if (curr >= m) break;
                    }
                }
            }
        }
    return make_pair(cost, s);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        // cout << " hello " << s << endl;
        vector<int> freq(10);
        for (int i = 0 ; i < n ; i ++) {
            freq[s[i]-'0']++;
        }
        int m = LLONG_MAX;
        for (int i = 0 ; i < 10 ; i ++) {
            if (m > (k-freq[i])) {
                m = k-freq[i];
            }
        }
        if (m == 0) {
            cout << 0 << "\n" << s << "\n";
            return 0;
        }
        int minC = LLONG_MAX;
        string currS;
        for (int i = 0 ; i < 10 ; i ++) {
            pair<int, string> l = cs(s, i, k-freq[i], n);
            if (l.first < minC) {
                minC = l.first;
                currS = l.second;
            }
            if (l.first == minC){
                if (l.second < currS) currS = l.second;
            }
        }
        cout << minC << " \n" << currS << "\n"; 
        
    }
}
