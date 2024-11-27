#include<bits/stdc++.h>
using namespace std;
#define ll long long

int josephus(int children, int position) {
    // cout << children << position << endl;
    if (children == 1) return 1;
    if (position*2 <= children) return 2*position;
    if (children%2 == 0) {
        return (2*josephus(children/2, position - children/2) - 1)%children; 
    }
    else {
        int k = (2*josephus(children/2 + 1, position - children/2) - 3);
        if (k == -1) return children;
        else return k;
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    int n, k;
    while (q--) {
        cin >> n >> k;
        cout << josephus(n, k) << '\n';
    }
    
}
