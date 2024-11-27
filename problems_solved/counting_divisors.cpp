#include<bits/stdc++.h>
using namespace std;
#define ll long long

void num_divisors_list (int n, vector<int> &num_divisors, int current_prime_number) {
    
    bool found = false;
    if (n == 1) return;
    
    // cout <<  << " chc" << endl;
    for (int i = current_prime_number + 1 ; i <= sqrt(n) ; i ++ ){
        // cout << "Hello world" << endl;
        if (n % i == 0 ) {
            // cout << n << i << endl;
            found = true;
            int count = 0;
            while ( n % i == 0) {
                n = n/i;
                // cout << n << endl;
                count ++;
            }
            num_divisors.push_back(count);
            // cout << count << " check " << n << i << endl;
            if (n == 1) return;
            num_divisors_list(n, num_divisors, i);
            return;
            // if (n == 1) return;
        }
    }
    if (!found) {
        num_divisors.push_back(1);
    }
    return;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++ ) {
        int x;
        cin >> x;
        vector<int> num_divisors;
        int product = 1;
        num_divisors_list(x, num_divisors, 1);
        for (int i = 0 ; i < num_divisors.size() ; i ++ ) {
            product *= (num_divisors[i] + 1);
        }
        cout << product << '\n';
    }
    // vector<int> num_divisors;
    // int n = 18;
    // num_divisors_list(n, num_divisors, 1);
    // // cout << num_divisors.size() << endl;
    // // cout << num_divisors[2] << endl;
}
