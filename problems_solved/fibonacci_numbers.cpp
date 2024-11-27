#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;

map<ll, ll> F;

long long fibonacci_calculator(long long n) {
    // cout << "Hello " << n << endl;
    if (F.count(n)) return F[n];
    if (n%2 == 0) {
        return F[n] = (fibonacci_calculator(n/2)*((fibonacci_calculator(n/2 + 1) + fibonacci_calculator(n/2 - 1))%(mod)))%mod;
    }
    else {
        return F[n] = ((fibonacci_calculator((n-1)/2 + 1)*fibonacci_calculator((n-1)/2 + 1))%mod + (fibonacci_calculator((n-1)/2)*fibonacci_calculator((n-1)/2))%mod)%mod;
    }

}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;
    cout << fibonacci_calculator(n) << '\n';
}
