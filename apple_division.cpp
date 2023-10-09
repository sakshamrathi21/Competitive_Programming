#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long minWeightDifference(const vector<long long>& weights, long long index, long long group1, long long group2) {
    // Base case: all apples have been assigned to either group1 or group2
    if (index == weights.size()) {
        return abs(group1 - group2);
    }

    // Recursive case: current apple can be assigned to either group1 or group2
    long long diff1 = minWeightDifference(weights, index + 1, group1 + weights[index], group2);
    long long diff2 = minWeightDifference(weights, index + 1, group1, group2 + weights[index]);

    return min(diff1, diff2);
}

int main() {
    int n;
    cin >> n;

    vector<long long> weights(n);
    for (long long i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    long long result = minWeightDifference(weights, 0, 0, 0);
    cout << result << endl;

    return 0;
}
