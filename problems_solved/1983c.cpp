/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul  8 15:53:29 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int tot = 0, req;
pair<bool, vector<int>> f(vector<int>&a, vector<int>&b, vector<int>&c) {
    int n = a.size();
    int al = 0, bo = 0, ch = 0, cnt1 = 0 , cnt2 = 0, cnt3 = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (bo >= req && al >= req) {ch+=c[i]; cnt3++;}
        else if (al >= req) {bo += b[i]; cnt2 ++;}
        else {al += a[i]; cnt1++;}
    }
    if (al >= req && bo >= req && ch >= req) {
        vector<int> res;
        res.push_back(1);
        res.push_back(1+cnt1-1);
        res.push_back(1+cnt1);
        res.push_back(1+cnt1+cnt2-1);
        res.push_back(1+cnt1+cnt2);
        res.push_back(n);
        return make_pair(true, res);
    }
    vector<int> res = {0, 0, 0, 0, 0, 0};
    return make_pair(false, res);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> b[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> c[i];
        }
        tot = 0;
        for (int i = 0 ; i < n ; i ++) tot += a[i];
        if (tot%3) req = tot/3+1;
        else req = tot/3;
        pair<bool, vector<int>> check = f(a, b, c);
        if (check.first) {
            for (int i = 0 ; i < 6 ; i ++) {
                cout << check.second[i] << " ";
            }
            cout << "\n";
            continue;
        }     
        check = f(a, c, b);
        if (check.first) {
            cout << check.second[0] << " " << check.second[1] << " " << check.second[4] << " " << check.second[5] << " " << check.second[2] << " " << check.second[3];
            cout << "\n";
            continue;
        }     
        check = f(b, a, c);
        if (check.first) {
            cout << check.second[2] << " " << check.second[3] << " " << check.second[0] << " " << check.second[1] << " " << check.second[4] << " " << check.second[5];
            cout << "\n";
            continue;
        }     

        check = f(b, c, a);
        if (check.first) {
            cout << check.second[4] << " " << check.second[5] << " " << check.second[0] << " " << check.second[1] << " " << check.second[2] << " " << check.second[3];
            cout << "\n";
            continue;
        }  

        check = f(c, a, b);
        if (check.first) {
            cout << check.second[2] << " " << check.second[3] << " " << check.second[4] << " " << check.second[5] << " " << check.second[0] << " " << check.second[1];
            cout << "\n";
            continue;
        }  
        check = f(c, b, a);
        if (check.first) {
            cout << check.second[4] << " " << check.second[5] << " " << check.second[2] << " " << check.second[3] << " " << check.second[0] << " " << check.second[1];
            cout << "\n";
            continue;
        }  
        cout << "-1\n";
    }
}
