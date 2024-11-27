/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 23 19:43:42 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int d(string&s, int ind) {
    vector<int> nums;
    for (int i = 0 ; i < ind ; i ++) nums.push_back(s[i]-'0');
    string c;
    c.push_back(s[ind]);
    c.push_back(s[ind+1]);
    nums.push_back(stoi(c));
    for (int i = ind+2 ; i < s.length() ; i ++) nums.push_back(s[i]-'0');
    int res = 0;
    for (int i = 0 ; i < nums.size() ; i ++) {
        if (nums[i] == 1) continue;
        res += nums[i];
    }
    return res;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool zr = false;
        if (s.length() == 2) {cout << stoi(s) << "\n"; continue;}
        if (s.length() == 3 && s[1] == '0') {
            string c;
            c.push_back(s[1]);
            c.push_back(s[2]);
            int x = s[0]-'0';
            int y = stoi(c);
            cout << min(x+y, x*y) << "\n";
            // cout << max(s[0], s[2]) << "\n";
            continue;
        }
        for (int i = 0 ; i < n ; i ++) if (s[i] == '0') zr = true;
        
        if (zr) {
            cout << "0\n";
            continue;
        }
        int m = LLONG_MAX;
        for (int ind = 0 ; ind < n-1 ; ind ++) {
            m = min(d(s, ind), m);
        }
        cout << m << "\n";
    }
}
