#include<bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num_coins, desired_sum;
    cin >> num_coins >> desired_sum;
    vector<int> all_coins;
    int coin;
    for (int i = 0 ; i < num_coins ; i ++ ) {
        cin >> coin;
        all_coins.push_back(coin);
    }
    vector<long long> count_each_sum(1e6, 0);
    count_each_sum[0] = 0;
    for (int j = 0 ; j < num_coins; j ++ ) {
        count_each_sum[all_coins[j]] = 1;
    }
    for (int i = 1 ; i <= desired_sum ; i ++ ) {
        for (int j = 0 ; j < num_coins ; j ++ ) {
            if (i - all_coins[j] >= 0) {
                count_each_sum[i] += count_each_sum[i - all_coins[j]];
            }
        }
        if (count_each_sum[i] < 0) {
                count_each_sum[i] += 1000000007;
        } 
        count_each_sum[i] %= 1000000007;
    }
    cout << count_each_sum[desired_sum]%1000000007 << endl;
}
