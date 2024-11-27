#include<bits/stdc++.h>
using namespace std;
#define ll long long

int highest_power_of_two_in_factorial (int x) {
    ll current_power = 2;
    int result = 0;
    while (current_power <= x) {result += (x/current_power); current_power *= 2;}
    return result;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; i ++ ) cin >> a[i];
    int n_1_power = highest_power_of_two_in_factorial(n-1);
    int xor_product = a[0];
    // cout << " check " << highest_power_of_two_in_factorial(2) << endl;;
    for (int i = 1 ; i < n ; i ++ ) {
        // cout << n_1_power - highest_power_of_two_in_factorial(i) - highest_power_of_two_in_factorial(n-i-1) << endl;
        if (n_1_power - highest_power_of_two_in_factorial(i) - highest_power_of_two_in_factorial(n-i-1) == 0) xor_product ^= a[i]; 
    }
    cout << xor_product << endl;
}
