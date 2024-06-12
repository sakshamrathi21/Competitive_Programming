/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun  5 17:34:41 IST 2024
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
        int q;
        cin >> q;
        int curr_l = -1, curr_r = -1;
        while (q--) {
            int et;
            cin >> et;
            if (et == 1) {
                int a, b, n;
                cin >> a >> b >> n;
                if (curr_l == -1 && curr_r == -1) {
                    if (n == 1) {
                        curr_l = 1;
                        curr_r = a;
                    }
                    else {
                        curr_l = (n-2)*(a-b)+a+1;
                        curr_r = (n-1)*(a-b)+a; 
                    }
                    cout << 1 << " ";
                }
                else {
                    int new_l = (n-2)*(a-b)+a+1;
                    int new_r = (n-1)*(a-b)+a;
                    if (n == 1) {
                        new_l = 1;
                        new_r = a;
                    }
                    else {
                        new_l = (n-2)*(a-b)+a+1;
                        new_r = (n-1)*(a-b)+a; 
                    }
                    if (max(new_l, curr_l) <= min(new_r, curr_r)) {
                        curr_l = max(new_l, curr_l);
                        curr_r = min(new_r, curr_r);
                        cout << 1 << " ";
                    }
                    else cout << 0 << " ";
                }
            }
            else {
                int a, b;
                cin >> a >> b;
                if (curr_l == -1 && curr_r == -1) {
                    cout << -1 << " ";
                }
                else {
                    int ln = -1, rn = -1;
                    if (curr_l <= a) ln =1;
                    else {
                        if ((curr_l-a)%(a-b) == 0) ln = (curr_l-a)/(a-b)+1;
                        else ln = (curr_l-a)/(a-b)+2;
                    }
                    if (curr_r <= a) rn =1;
                    else {
                        if ((curr_r-a)%(a-b) == 0) rn = (curr_r-a)/(a-b)+1;
                        else rn = (curr_r-a)/(a-b)+2;
                    }
                    if (ln == rn) cout << ln << " ";
                    else cout << -1 << " ";
                }
            }
        }
        cout << "\n";
    }
}
