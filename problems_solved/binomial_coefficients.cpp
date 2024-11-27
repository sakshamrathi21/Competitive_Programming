#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
    vector<pair<int, int>> pairs;
    int a, b;
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> a >> b;
        pairs.push_back({a, b});
    }

    int max_number = (*max_element(pairs.begin(), pairs.end())).first;
    int trial = factorial(max_number);
    // cout << trial;

    for (int i = 0 ; i < n ; i ++ ) {
        cout << binomialCoefficient(pairs[i].first, pairs[i].second) << '\n';
    }


}
