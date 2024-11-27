#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n+m+1];
        int b[n+m+1];
        for (int i = 0 ; i < n+m+1 ; i ++) cin >>a[i];
        for (int i = 0 ; i < n+m+1 ; i ++) cin >>b[i];
        int testers_full = -1;
        int ts = 0;
        int nt = 0, np = 0, ci=-1;
        for (int i = 0 ; i < m+n ; i ++){
            // cout << i << " hello " << np << " " << nt << " " << m << " " << n << endl;
            if (np == n) {
                ts += b[i];
                nt++;
                if (ci == -1) ci = i;
                if (testers_full == -1) testers_full = 0;
            }
            else if (nt == m) {
                ts += a[i];
                np++;
                if (testers_full == -1) testers_full = 1;
                if (ci == -1) ci = i;
            }
            else if (a[i]>b[i]) {
                np++;
                ts += a[i];
            }
            else {
                ts += b[i];
                nt++;
            }
        }
        int b_index = m+n;
        for (int i = ci ; i < n+m+1 ; i ++) {
            if (testers_full && b[i]>a[i]) {
                b_index = i;
                break;
            } 
            else if (!testers_full && a[i]>b[i]) {
                b_index = i;
                break;
            }
        }
        // cout << ci << " hello " << b_index << endl;
        for (int i = 0 ; i < ci ; i ++) {
            if (testers_full && a[i]>b[i]) {
                cout << (ts-a[i]+a[n+m]) << " ";
            }
            else if (testers_full && b[i]>a[i]) {
                cout << (ts-b[i]+b[b_index]-a[b_index]+a[m+n]) << " ";
            }
            else if (!testers_full && a[i] > b[i]) {
                cout << (ts-a[i]+a[b_index]-b[b_index]+b[m+n]) << " ";
            }
            else {
                cout << (ts-b[i]+b[n+m]) << " ";
            }
        }
        for (int i = ci ; i < n+m ; i ++) {
            if (testers_full) {
                cout << (ts-a[i]+a[n+m]) << " ";
            }
            else cout << (ts-b[i]+b[n+m]) << " ";
        }
        cout << ts << "\n";
    }
}
