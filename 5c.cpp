/**
 *    Author: Saksham Rathi
 *    Created: Mon Jun 24 17:16:41 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    // cout << " hello " << s << endl;
    int n = s.length();
    vector<int> c(n, -100), d(n, -100);
    // int c[s.length()], d[s.length()];
    stack<int> st;
    for (int i = 0 ; i < s.length() ; i ++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) {
                c[i] = -1;
                d[i] = -1;
            }
            else {
                d[i] = st.top();
                st.pop();
                c[i] = d[i];
                if (d[i] >= 1 && c[d[i]-1]!=-1 && c[d[i]-1] != -100) c[i] = c[d[i]-1];
            }
        }
    }
    int max_len = 0;
    int curr_cnt = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (s[i] == ')' && c[i]!=-1 && c[i]!=-100) {
            if (i-c[i]+1 > max_len) {
                curr_cnt = 1;
                max_len = i-c[i]+1;
            }
            else if (i-c[i]+1 == max_len) curr_cnt++;
        }
    }
    // for (int i = 0 ; i < n ; i ++) {
    //     cout << c[i] << " ";
    // }

    // cout << " hello " << max_len << endl;
    if (max_len == 0) cout << "0 1";
    else cout << max_len << " " << curr_cnt;
    
}
