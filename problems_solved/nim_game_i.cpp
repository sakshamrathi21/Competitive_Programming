#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
        n--;
        int xor_product = x;
        while (n--) {
            cin >> x;
            xor_product^= x;
        }
        if (xor_product) cout <<"first" << endl;
        else cout << "second" << endl;
    }
}
