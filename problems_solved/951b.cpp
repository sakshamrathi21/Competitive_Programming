/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun  6 20:03:15 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> binForm(int x) {
    vector<int> rs;
    while (x > 0) {
        rs.push_back(x%2);
        x /= 2;
    }
    // reverse(rs.begin(), rs.end());
    return rs;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        vector<int> rsx = binForm(x);
        vector<int> rsy = binForm(y);
        int l = min(rsx.size(), rsy.size());
        
        // for (int i = 0 ; i < rsx.size() ; i ++) cout << rsx[i] << " ";
        // cout << "\n";
        // for (int i = 0 ; i < rsy.size() ; i ++) cout << rsy[i] << " ";
        // // cout << rsy.size() << " hello " << endl;
        vector<int> cm;
        for (int i = 0 ; i < l ; i ++) {
            if (rsx[i] == rsy[i]) {
                cm.push_back(1);
                // cout << " hello " << i << endl;
            }
            else cm.push_back(0);
        }
        if (rsx.size() > rsy.size()) {
            for (int i = l ; i < rsx.size() ; i ++) {
                if (rsx[i] == 0) {
                    cm.push_back(1);
                }
                else cm.push_back(0);
            }
        }
        else {
            for (int i = l ; i < rsy.size() ; i ++) {
                if (rsy[i] == 0) {
                    cm.push_back(1);
                }
                else cm.push_back(0);
            }
        }
        // cout << " hello " << cm.size() << endl;
        int currCount = 0;
        for (int i = 0 ; i < cm.size() ; i ++) {
            if (cm[i] == 1) currCount++;
            else break;
            // maxCount = max(maxCount, currCount);
        }
        cout << std::fixed << std::setprecision(0) << pow(2, currCount) << "\n";
    }
}
