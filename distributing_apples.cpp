#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1000000007;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

// Function to calculate n!
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = mul(result, i);
    }
    return result;
}

// Function to calculate modular inverse of a number
int modInverse(int a) {
    // Using Fermat's Little Theorem
    // If MOD is a prime number, you can use (a^(MOD-2)) % MOD
    // If MOD is not prime, you may need to use Extended Euclidean Algorithm
    // to find the modular inverse
    // For simplicity, we assume MOD is prime in this example
    int b = MOD - 2;
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = mul(result, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return result;
}

// Function to calculate n choose k modulo MOD
int binomialCoefficient(int n, int k) {
    if (k > n) {
        return 0; // Invalid input
    }

    int numerator = factorial(n);
    int denominator = mul(factorial(k), factorial(n - k));

    int result = mul(numerator, modInverse(denominator));
    return result;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << binomialCoefficient(n+m-1, m);
}
