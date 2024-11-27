/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 11 21:08:01 IST 2024
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
        int x = 0;
        vector<pair<int, int>> ans;
        if (n <= 9 ) {
            for (int b = 1 ; b <= 10000 ; b ++) {
                for (int a = b ; a <= b+6 && a<= 10000 ; a++) {
                    int ch = a*n-b;
                    string sh = to_string(ch);
                    if (sh.length() != a-b) continue;
                    bool poss = true;
                    for (int i = 0 ; i < sh.length() ; i ++) {
                        if (sh[i] != '0'+n) {
                            poss = false;
                            break;
                        }
                    }
                    if (!poss) continue;
                    x++;
                    ans.push_back(make_pair(a, b));
                }
            }
        }
        else if (n <= 99) {
            for (int b = 1 ; b <= 10000 ; b ++) {
                if (b%2) {
                    for (int a = (b+1)/2 ; a<= 10000 && a<= (b+9)/2 ; a++) {
                        int ch = a*n-b;
                        string sh = to_string(ch);
                        if (sh.length() != 2*a-b) continue;
                        
                        bool poss = true;
                        for (int i = 0 ; i+1 < sh.length()-1 ; i +=2) {
                            if (sh[i] != '0'+n/10 || sh[i+1] != '0'+n%10) {
                                poss = false;
                                break;
                            }
                        }
                        // if (b == 2519) cout << ch << " hello " << poss << a << endl;
                        if (sh[sh.length()-1] != '0'+n/10) poss = false;
                        if (!poss) continue;
                        x++;
                        ans.push_back(make_pair(a, b));
                    }
                }
                else {
                    for (int a = b/2 ; a <= 10000 && a <= b/2+4 ; a ++) {
                        int ch = a*n-b;
                        string sh = to_string(ch);
                        if (sh.length() != 2*a-b) continue;
                        bool poss = true;
                        for (int i = 0 ; i+1 < sh.length() ; i +=2) {
                            if (sh[i] != '0'+n/10 || sh[i+1] != '0'+n%10) {
                                poss = false;
                                break;
                            }
                        }
                        if (!poss) continue;
                        x++;
                        ans.push_back(make_pair(a, b));
                    }
                }
            }
        }
        else {
            for (int b = 1 ; b <= 10000 ; b ++) {
                for (int a = b/3 ; a <= (b+8)/3 ; a++) {
                    if (3*a-b < 0) continue;
                    int ch = a*n-b;
                    string sh = to_string(ch);
                    if (sh.length() != 2*a-b) continue;
                    bool poss = true;
                    for (int i = 0 ; i+2 < sh.length() ; i +=3) {
                        if (sh[i] != '0'+n/100 || sh[i+1] != '0'+(n%100)/10 || sh[i+2] != '0'+(n%10)) {
                            poss = false;
                            break;
                        }
                    }
                    if (sh.length()%3 == 1) {
                        if (sh[sh.length()-1] != '1') poss = false;
                    }
                    if (sh.length()%3 == 2 && (sh[sh.length()-2]!='1' || sh[sh.length()-1]!='0')) poss = false;
                    if (!poss) continue;
                    x++;
                    ans.push_back(make_pair(a, b));
                }
            }
        }
        cout << x << "\n";
        for (int i = 0 ; i < ans.size() ; i ++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
