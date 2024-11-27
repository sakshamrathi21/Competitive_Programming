#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int a[n], b[n];
        a[0] = 1, b[0] = 0;
        for (int i = 1 ; i < n ; i ++) {
            a[i] = a[i-1];
            b[i] = b[i-1];
            if (s[i] == '(') a[i]++;
            else b[i]++;
        }
        int curr = 1;
        while (curr < n-1) {
            int next;
            for (next = curr+1 ; next < n-1 ; next ++) {
                if (b[curr-1]+a[next]-a[curr-1] > a[curr-1]+b[next]-b[curr-1]) break;
            }
            if
        }
    } 
}
