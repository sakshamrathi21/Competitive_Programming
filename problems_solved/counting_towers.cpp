#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num_test_cases;
    cin >> num_test_cases;
    int input_number;
    vector<int> all_test_numbers(num_test_cases);
    int maximum_number = 0;
    for (int i = 0 ; i < num_test_cases ; i ++ ) {
        cin >> input_number;
        all_test_numbers[i] = input_number;
        maximum_number = max(maximum_number, input_number);
    }
    input_number = maximum_number;
    vector<pair<ll, ll> > required_values(input_number + 1);
    // cout << required_values.size() << input_number << endl;
    required_values[0].first = 0;
    required_values[0].second = 0;
    required_values[1].first = 1;
    required_values[1].second = 1;
    for (int i = 2 ; i <= input_number ; i ++ ) {
        required_values[i].first = (2*required_values[i-1].first + required_values[i-1].second)%(1000000007);
        required_values[i].second = (required_values[i-1].first + 4*required_values[i-1].second)%(1000000007);
        // cout << required_values[i].first << required_values[i].second << endl;
    }

    for (int i = 0 ; i < num_test_cases ; i ++ ) {
        cout << (required_values[all_test_numbers[i]].first + required_values[all_test_numbers[i]].second)%(1000000007) << '\n';
    }
}
