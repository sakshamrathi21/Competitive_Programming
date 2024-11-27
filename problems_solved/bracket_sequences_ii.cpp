#include<bits/stdc++.h>
using namespace std;
#define ll long long
int target;
int mod = 1e9 + 7;

int modified_catalan(int right, int up) {
    if (right == target && up == target) return 1;
    if (up > right) return 0;
    if (right > target || up > target) return 0;
    return (modified_catalan(right + 1, up) + modified_catalan(right, up + 1))%mod;
}

const int MOD = 1000000007;

vector<int> factorial_values;


int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int factorial(int n) {
    int result = 1;
    factorial_values.push_back(result);
    for (int i = 1; i <= n; ++i) {
        result = mul(result, i);
        // cout << result << endl;
        factorial_values.push_back(result);
    }
    return result;
}

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

    int numerator = factorial_values[n];
    // cout << numerator << endl;
    int denominator = mul(factorial_values[k], factorial_values[n-k]);

    int result = mul(numerator, modInverse(denominator));
    return result;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n%2 == 1) {
        cout << 0;
        return 0;
    }
    string s;
    getline(cin, s);
    int right = 0, up = 0;
    char k;
    target = n/2;
    while (cin >> k) {
        if (k == '(') right ++;
        else up ++;
        if (up > right) {
            cout << 0;
            return 0;
        }
    }

    int trial = factorial(n);
    int result = (binomialCoefficient(n-up-right, n/2 - up)-binomialCoefficient(n-up-right, n/2-up+1) + mod)%mod;
    // for (int i = right + n/2 ; i < n ; i ++ ) {
    //     result -= binomialCoefficient(i - up - right - 1, n/2 - up - 1)%mod;
    // }
    // cout << (result +2*mod)%mod << endl;
    cout << result ;
    
}
