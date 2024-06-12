#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_integers, target_sum;
    cin >> num_integers >> target_sum;
    vector<int> all_integers(num_integers);
    for (int i = 0 ; i < num_integers ; i ++ ) {
        cin >> all_integers[i];
    }

    map<long long, vector<long long>> all_sums_mod_x;

    all_sums_mod_x[0].push_back(0);
    long long prefix_sum = 0;

    for (int i = 0 ; i < num_integers ; i ++) {
        prefix_sum += all_integers[i];
        all_sums_mod_x[prefix_sum%target_sum].push_back(prefix_sum/target_sum);
    }

    int count = 0;

    for (auto map_element : all_sums_mod_x) {
        for (int i = 1 ; i < map_element.second.size() ; i ++ ) {
            if (map_element.second[i]-map_element.second[i-1] == 1) count ++;
        }
    }
    cout << count << endl;
}
