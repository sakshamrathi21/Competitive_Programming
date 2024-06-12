#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >>n;
        // cout << "check " << n << endl;
        bool found_odd = false;
        while (n--) {
            int x;
            cin >> x;
            if (x%2 == 1) {found_odd = true;}
        }
        if (found_odd) cout << "first" << endl;
        else cout << "second" << endl;
    }
}
