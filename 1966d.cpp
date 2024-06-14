/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 13 18:28:07 IST 2024
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
        vector<int> a;
        for (int i = 0 ; i <= 19 ; i ++ ) {
            a.push_back(pow(2, i));
        }
        int curr = 1;
        while (pow(2, curr) < k) curr++;
        if (pow(2, curr) > k) curr--;
        a.erase(a.begin()+curr);
        a.push_back(k-pow(2, curr));
        a.push_back(k+1);
        a.push_back(k+pow(2, curr)+1);
        cout << a.size() << "\n";
        for (auto x : a) cout << x << " ";
        cout << "\n";
    }
}
