/**
 *    Author: Saksham Rathi
 *    Created: Sun Dec 15 09:21:23 IST 2024
**/


#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100000;

constexpr auto precompute() {
    array<int, MAX_N + 1> results = {};
    int cur = 1, ans = 1;
    for (int n = 1; n <= MAX_N; n++) {
        while (cur < n) {
            cur = cur * 2 + 2;
            ans++;
        }
        results[n] = ans;
    }
    return results;
}

constexpr auto results = precompute();

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << results[n] << '\n';
    }
    return 0;
}

