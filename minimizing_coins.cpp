#include<bits/stdc++.h>
using namespace std;



int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num_coins;
    int desired_sum;
    cin >> num_coins >> desired_sum;
    
    int coin;
    vector<int> all_coins;
    for (int i = 0 ; i < num_coins ; i ++ ) {
        cin >> coin;
        all_coins.push_back(coin);
    }

    vector<long long> sum_ways(desired_sum + 1, 1e9);
    sum_ways[0] = 0;
    for (int i = 1 ; i <= desired_sum ; i ++ ) {
        for (int j = 0 ; j < num_coins ; j ++ ) {
            if (i-all_coins[j] >= 0) {
                sum_ways[i] = min(sum_ways[i], sum_ways[i-all_coins[j]] + 1);
            }
        }
    }
    if (sum_ways[desired_sum] == 1e9) cout << -1 << endl;
    else cout << sum_ways[desired_sum] << endl;

}
