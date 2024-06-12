/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 20:48:50 IST 2024
**/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> max_locations(int t, vector<vector<long long>>& test_cases) {
    vector<int> results;
    
    for (int i = 0; i < t; ++i) {
        long long x = test_cases[i][0];
        long long y = test_cases[i][1];
        long long z = test_cases[i][2];
        long long k = test_cases[i][3];
        long long max_count = 0;
        
        vector<tuple<long long, long long, long long>> factors;
        for (long long a = 1; a * a * a <= k; ++a) {
            if (k % a == 0) {
                long long ak = k / a;
                for (long long b = 1; b * b <= ak; ++b) {
                    if (ak % b == 0) {
                        long long c = ak / b;
                        factors.push_back(make_tuple(a, b, c));
                    }
                }
            }
        }
        
        for (auto& factor : factors) {
            long long a, b, c;
            tie(a, b, c) = factor;
            if (a <= x && b <= y && c <= z)
                max_count = max(max_count, (x - a + 1) * (y - b + 1) * (z - c + 1));
            if (b <= x && a <= y && c <= z)
                max_count = max(max_count, (x - b + 1) * (y - a + 1) * (z - c + 1));
            if (c <= x && b <= y && a <= z)
                max_count = max(max_count, (x - c + 1) * (y - b + 1) * (z - a + 1));
            if (a <= x && c <= y && b <= z)
                max_count = max(max_count, (x - a + 1) * (y - c + 1) * (z - b + 1));
            if (b <= x && c <= y && a <= z)
                max_count = max(max_count, (x - b + 1) * (y - c + 1) * (z - a + 1));
            if (c <= x && a <= y && b <= z)
                max_count = max(max_count, (x - c + 1) * (y - a + 1) * (z - b + 1));
        }
        
        results.push_back(max_count);
    }
    
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<vector<long long>> test_cases(t, vector<long long>(4));
    
    for (int i = 0; i < t; ++i) {
        cin >> test_cases[i][0] >> test_cases[i][1] >> test_cases[i][2] >> test_cases[i][3];
    }
    
    vector<int> results = max_locations(t, test_cases);
    
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}
