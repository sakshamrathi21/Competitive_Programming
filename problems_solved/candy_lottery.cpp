#include<bits/stdc++.h>
using namespace std;
#define ll long long

long double power (long double p, int n) {
    long double result = 1;
    while (n > 0) {
        if (n & 1) {
            result = (result*p);
        }
        p = (p*p);
        n = n/2;
    }
    return result;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long double k;
    cin >> n >> k;
    long double result = 0;
    for (long double i = 1 ; i <= k ; i ++) {
        // cout << power(i/k, n) << endl;
        result += i*(power(i/k, n) - power((i-1)/k, n));
    }
    cout<<setprecision(6)<<fixed;
    cout << result;
}
