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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    map<char, int> frequency;
    for (auto ch : s){
        frequency[ch] ++;
    }
    int prod = factorial(s.length());
    for (auto x : frequency) {
        prod = mul(prod, modInverse(factorial_values[x.second]));
    }

    cout << prod;


    
}
