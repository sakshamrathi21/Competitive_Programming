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
        cin >> n;
        
        vector<int> values(n);
        for (int i = 0 ; i < n ; i ++ ) {
            cin >> values[i];
        }
        if (n == 1) {
            cout << "second" << endl;
            continue;
        }
        int xor_product = values[1];
        for (int i = 3 ; i < values.size() ; i += 2) {
            xor_product ^= values[i];
        }
        if (xor_product) cout << "first" << endl;
        else cout << "second" << endl;
    }
}
