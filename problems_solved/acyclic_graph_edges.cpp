#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    while (M--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << a << " " << b << endl;
    }

}
