#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_integers;
    cin >> num_integers;

    vector<int> all_integers(num_integers);
    for (int i = 0 ; i < num_integers ; i ++ ) {
        cin >> all_integers[i];
    }

    vector<long long> prefix_mod(num_integers, 0);
    long long prefix_sum = 0;
    prefix_mod[prefix_sum] ++;
    for (int i = 0 ; i < num_integers ; i ++ ){
        prefix_sum += all_integers[i];
        if (prefix_sum < 0) {
            prefix_sum += 1e9 * num_integers;
        }
        prefix_sum %= num_integers;
        prefix_mod[prefix_sum] ++;
    }

    long long count = 0;

    for (int i = 0 ; i < num_integers ; i ++ ) {
        count += prefix_mod[i]* ( prefix_mod[i] - 1) /2;
    }

    cout << count << endl;
}