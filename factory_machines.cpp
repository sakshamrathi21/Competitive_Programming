#include<bits/stdc++.h>
using namespace std;

int main () {
    int machines;
    cin >> machines;
    int products;
    cin >> products;

    vector <int> machine_times(machines);

    for (int i = 0; i < machines ; i ++ ) {
        cin >> machine_times[i];
    }

    long long low = 0;
    long long high = 1e18;
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high ) / 2;
        long long sum = 0;
        for (int i = 0 ; i < machines ; i ++ ) {
            sum += mid/machine_times[i];
            if (sum >= products ) break;
        }
        if (sum >= products) {
            high = mid - 1;
            ans = mid;
        }
        else {
            low = mid + 1;
        }
    }
    cout << ans << endl;

}