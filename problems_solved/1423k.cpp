/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 08:38:02 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxN = 1000005;

vector<int> pbn(1000005);
vector<bool> visited(1000005);

void pc(void) {
    for (int k = 2 ; k < 1e6+5 ; k++) {
        if (visited[k]) continue;
        for (int i = 2*k ; i < 1e6+5 ; i+=k) visited[i] = true;
    }
    pbn[0] = 0;
    pbn[1] = 0;
    for (int i = 2 ; i < 1e6+5 ; i ++) {
        pbn[i] = (pbn[i-1]+(1-visited[i]));
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pc();
    while (t--) {
        int n;
        cin >> n;
        cout << pbn[n]-pbn[sqrt(n)]+1 << "\n";

    }
}
