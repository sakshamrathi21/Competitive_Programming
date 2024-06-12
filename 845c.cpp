/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun  8 22:06:50 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0 ; i < n ; i ++) {
            int x, y;
            cin >> x >> y;
            a.push_back(make_pair(x, 1));
            a.push_back(make_pair(y+1, -1));
        }
        sort(a.begin(), a.end());
        int cnt = 0;
        bool poss = true;
        for (int i = 0 ; i < a.size() ; i ++) {
            if (cnt > 2) {
                poss = false;
                break;
            }
            if (a[i].second == 1) cnt++;
            else cnt--;
        }
        if (poss) cout << "YES";
        else cout << "NO";
    }
}
