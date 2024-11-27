#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool is_possible(vector<int> values) {
    int xor_product = values[0];
    for (int i = 1 ; i < values.size() ; i ++ ) {
        xor_product ^= values[i];
    }
    // cout << xor_product << endl;
    if (xor_product) return false;
    return true; 
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        // vector<int> values(n);
        int xor_product = (x%4);
        n--;
        while (n--) {
            cin >> x;
            xor_product ^= (x%4);
        }
        if (xor_product == 0) cout << "second" << endl;
        else cout << "first" << endl;
    }
}
