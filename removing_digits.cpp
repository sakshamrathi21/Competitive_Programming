#include<bits/stdc++.h>
using namespace std;

int max_digit(int n) {
    int max_digit = n%10;
    while (n >= 1) {
        n /= 10;
        max_digit = max(max_digit, n%10);
    }
    return max_digit;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int minimum_steps = 0;
    // cout << "HELLO " << max_digit(20) << endl;
    while (n >= 1) {
        n -= max_digit(n);
        minimum_steps ++;
    }
    cout << minimum_steps << endl;
}
