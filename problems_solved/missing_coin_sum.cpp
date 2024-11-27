#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_coins;
    cin >> num_coins ;

    vector<int> coins;

    int a;
    for (int i = 0 ;i < num_coins ; i ++ ) {
        cin >> a;
        coins.push_back(a);
    }

    sort(coins.begin(), coins.end());
    long long currSum = 0;

    for (int i = 0 ; i < num_coins ; i ++ ) {
        if (coins[i] > currSum + 1) {
            cout << currSum + 1 << endl;
            return 0;
        }
        currSum += coins[i];
    }

    cout << currSum + 1 << endl;
}