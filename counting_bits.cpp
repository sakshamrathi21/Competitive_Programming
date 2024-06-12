#include<iostream>
using namespace std;
#define ll long long

ll pow(ll x, int n) {
    if (n == 0) return 1;
    ll result = pow(x, n/2);
    result *= result;
    if (n%2 == 1) result *= x;
    return result;
}

int highest_power_of_two(ll x) {
    if (x == 0 ) return 0;
    int count = 0;
    while (x) {
        x/=2;
        count ++;
    }
    return count - 1;
}

ll bits_count(ll n) {
    // cout << n << endl;
    if (n <= 0) return 0;
    int power = highest_power_of_two(n + 1);
    return (power*pow(2, power - 1) + (n- pow(2, power) + 1) + bits_count(n- pow(2, power)));
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    // cout << highest_power_of_two(n);
    cout << bits_count(n) << endl;
}
