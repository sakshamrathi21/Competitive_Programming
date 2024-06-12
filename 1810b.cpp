/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun  5 18:36:06 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool possible = true;
        if (n%2 == 0) {cout << -1 << "\n"; continue;}
        int hp = 0;
        while (pow(2, hp) < n) hp++;
        if (hp > 40 || hp < 1) {cout << -1 << "\n"; continue;}
        int left = n-pow(2, hp-1);
        int right = pow(2, hp)-n;
        if (left < )
    }
}
