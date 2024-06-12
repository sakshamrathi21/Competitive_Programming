#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num_coins;
    cin >> num_coins;
    vector<int> all_coins(num_coins);
    for (int i = 0 ; i < num_coins ; i ++ ) {
        cin >> all_coins[i];
    }

    int max_sum = 1e5;
    vector<vector<bool>> is_possible(num_coins + 1, vector<bool>(max_sum+1, false));
    is_possible[0][0] = true;
    for (int i = 1; i <= num_coins ; i ++ ) {
        for (int j = 0 ; j <= max_sum ; j ++ ){
            is_possible[i][j] = is_possible[i-1][j];
            int previous_sum = j - all_coins[i-1];
            if (previous_sum >= 0 && is_possible[i-1][previous_sum]) {
                is_possible[i][j] = true;
            }
        }
    }
    vector<int> possible_sums;
    for (int i = 1 ; i <= max_sum ; i ++ ){
        if (is_possible[num_coins][i]) {
            possible_sums.push_back(i);
        }
    }

    cout << possible_sums.size() << '\n';

    for (int sum: possible_sums) {cout << sum << " ";}

}
