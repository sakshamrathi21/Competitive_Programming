#include<bits/stdc++.h>
using namespace std;

int k;

bool array_division_possible(vector<int> all_numbers, long long sum_required) {
    int subarray_count = 0;
    long long current_sum = 0;
    for (auto x : all_numbers) {
        if (x > sum_required) return false;
        if (x + current_sum > sum_required) {
            subarray_count++;
            current_sum = 0;
        }
        current_sum += x;
    }
    if (current_sum > 0) subarray_count ++;
    return subarray_count <= k;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> k;
    int number;
    long long max_sum = 0;
    vector<int> all_numbers;
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> number;
        all_numbers.push_back(number);
        max_sum += number;
    }

    long long low = 0;
    long long high = max_sum;
    while (low < high) {
        long long mid = (low + high) / 2;
        if (array_division_possible(all_numbers, mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low << '\n';
}
