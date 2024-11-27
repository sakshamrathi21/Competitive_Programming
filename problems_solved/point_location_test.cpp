#include<bits/stdc++.h>
using namespace std;
#define ll long long

void locate_point(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll determinant = 0;
    determinant += x1*y2-x1*y3 - y1*x2 + y1*x3 + x2*y3 - x3*y2;
    if (determinant == 0) cout << "TOUCH" << '\n';
    if (determinant > 0) cout << "LEFT" << '\n';
    if (determinant < 0) cout << "RIGHT" << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    ll x1, x2, x3, y1, y2, y3;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        locate_point(x1, y1, x2, y2, x3, y3);
    }
}
