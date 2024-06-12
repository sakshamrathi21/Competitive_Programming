#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        vector<int> b;
        while (x) {
            b.push_back(x%2);
            x/= 2;
        }
        int prev = -1, curr = -1;
        for (curr = 0 ; curr < b.size() ; curr ++){
            if (prev == -1 && b[curr] == 1) {
                prev = curr;
            }
            if (prev != -1 && b[curr] == 0) {
                b[prev] = -1;
                for (int i = prev+1 ; i <curr ; i ++) {
                    b[i] = 0;
                }
                b[curr] = 1;
                prev = -1;
            }
        }
        if (prev != -1) {
           b[prev] = -1;
            for (int i = prev+1 ; i <curr ; i ++) {
                b[i] = 0;
            } 
            b.push_back(1);
        }
        for (int i = 0 ; i < b.size()-1 ; i ++) {
            if (b[i] == 1 && b[i+1] == -1) {
                b[i] = -1;
                b[i+1] = 0;
            }
            else if (b[i] == -1 && b[i+1] == 1) {
                b[i] = 1;
                b[i+1] = 0;
            }
        }
        if (b[b.size()-1] == 0) b.pop_back();
        cout << b.size() << "\n";
        for (int i = 0 ; i < b.size() ; i ++){
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}
