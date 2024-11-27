/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun  7 10:10:25 IST 2024
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
        string s;
        cin >> s;
        vector<int> len;
        int curr = 1;
        for (int i = 1 ; i < s.length() ; i ++) {
            if (s[i] == s[i-1]) curr++;
            else {
                len.push_back(curr);
                curr = 1;
            }
        }
        len.push_back(curr);
        int prod = 0;
        // cout << len[0] << endl;
        for (int i = 0 ; i < len.size() ; i ++) {prod+= (len[i]-1); prod%=998244353;}
        cout << prod%998244353 << " ";
        int ft = 1;
        for (int i = 2 ; i <= s.length()-len.size() ; i ++) {ft*=i; ft%=998244353;}
        cout << (prod*ft)%998244353 << "\n";
    }
}
