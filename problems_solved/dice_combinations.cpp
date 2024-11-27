#include<bits/stdc++.h>
using namespace std;

int total_count = 0 ;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum;
    cin >> sum;
    if (sum <= 7) {
    vector <int> all_sums(7, 0);
    all_sums[0] = 1;
    all_sums[1] = 2;
    all_sums[2] = 4;
    all_sums[3] = 8;
    all_sums[4] = 16;
    all_sums[5] = 32;
    all_sums[6] = 63;
    cout << all_sums[sum-1] << endl;
    return 0;
    }
    vector <long long> all_sums(sum, 0);
    all_sums[0] = 1;
    all_sums[1] = 2;
    all_sums[2] = 4;
    all_sums[3] = 8;
    all_sums[4] = 16;
    all_sums[5] = 32;
    all_sums[6] = 63;
    for (int i = 7 ; i < sum ; i ++ ) {
        all_sums[i] = 2*all_sums[i-1] - all_sums[i-7];
        if (all_sums[i] < 0) all_sums[i] += 1000000007;
        all_sums[i] %= 1000000007;
    }
    cout << all_sums[sum-1]%(1000000007) << endl;
    return 0;
}
