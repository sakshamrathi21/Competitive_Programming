/**
 *    Author: Saksham Rathi
 *    Created: Sat May 24 16:06:32 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        stack<int> st;
        int whether_stack_got_empty = -1;
        for (int i = 0 ; i < n ; i ++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else 
            {
                st.pop();
                if (whether_stack_got_empty == -1 && st.empty())
                {
                    whether_stack_got_empty = i;
                    // cout << " hello " << whether_stack_got_empty << endl;
                }
            }
        }
        if (whether_stack_got_empty != n - 1)
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }

    }
}
