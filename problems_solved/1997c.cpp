/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul 30 20:57:30 IST 2024
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<pair<char, int>> st;
        for (int i = 0 ; i < n ; i ++ ) {
            if (s[i] == '_') {
                if (!st.empty()) {
                    if (st.top().first == '(') {
                        s[i] = ')';
                        st.pop();
                    }
                    else {
                        s[i] = ')';
                        s[st.top().second]= '(';
                        st.pop();
                    }
                }
                else {
                    s[i] = '(';
                    st.push(make_pair(s[i], i));
                }
            }
            else if (s[i] == '(') {
                st.push(make_pair('(', i));
            }
            else {
                st.pop();
            }
        }
        stack<int> sp;
        int cost = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (s[i] == '(' ) {
                sp.push(i);
            }
            else {
                cost += (i - sp.top());
                sp.pop();
            }
        }
        cout << cost << "\n";
    }
}
