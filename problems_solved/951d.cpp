/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun  6 21:01:38 IST 2024
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
        string s;
        cin >> s;
        if (n >= 2*k) {
            string t1, t2;
            for (int i = 0 ; i < k ; i ++) {
                t1.push_back('0');
                t2.push_back('1');
            }
            if (s.find(t1) == string::npos && s.find(t2) == string::npos) {
                cout << -1 << "\n";
                continue;
            }
            for (int i = 0 ; i < k ; i ++) {
                t1.push_back('1');
                t2.push_back('0');
            }
            
            int f1 = s.find(t1);
            int f2 = s.find(t2);
            // cout <<"hello " << f1 << f2 << endl;;
            if (f1 != string::npos && f1 != 0) {
                cout << f1+k << "\n";
            }
            else if (f2 != string::npos && f2 != 0) {
                // cout << "checkl" << endl;
                cout << f2+k << "\n";
            }
            else {
                // 
                int curr = 1;
                string x1, x2;
                for (int i = 0 ; i < k ; i ++) {
                    x1.push_back('1');
                    x2.push_back('0');
                }
                bool found = true;
                reverse(s.begin(), s.end());
                int f1 = s.find(x1);
                int f2 = s.find(x2);
                if (f1 != string::npos) {
                    int l1 = 0;
                    for (int i = 0 ; i <= f1 ; i ++) {
                        if (s[i] == '1') {
                            found = false;
                            break;
                        }
                        else l1++;
                    }
                    for (int i = n-1 ; i> f1+k ; i--) {
                        if (s[i] == '1') break;
                        else l1++;
                    }
                    if (found && l1 >= k) cout << n-f1 << "\n";
                }
                else if (f2 != string::npos) {
                    int l1 = 0;
                    for (int i = 0 ; i <= f2 ; i ++) {
                        if (s[i] == '0') {
                            found = false;
                            break;
                        }
                        else l1++;
                    }
                    for (int i = n-1 ; i> f2+k ; i--) {
                        if (s[i] == '0') break;
                        else l1++;
                    }
                    if (found && l1 >= k) cout << n-f2 << "\n";
                }
                else found = false;
                if (!found) cout << -1 << "\n";
            } 
        }
        else {
            string t1, t2;
            for (int i = 0 ; i < k ; i ++) {
                t1.push_back('0');
                t2.push_back('1');
            }
            int f1 = s.find(t1);
            int f2 = s.find(t2);
            if (f1 != string::npos) {
                cout << f1+k << "\n";
            }
            else if (f2 != string::npos) {
                cout << f2+k << "\n";
            }
            else {
                cout << -1 << "\n";
            } 
        }
    }
}
