#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int length, breadth;
    cin >> length >> breadth;
    if (length == breadth) {
        cout << 0 << '\n';
        return 0;
    }
    // if (length < breadth) {
    //     int temp = breadth;
    //     breadth = length;
    //     length = temp;
    // }

    vector<vector<int>> minimum_cuts(length + 1, vector<int>(breadth + 1, 0));

    for (int i = 0 ; i <= min(length, breadth) ; i ++) {
        minimum_cuts[i][i] = 0;
    }

    for (int i = 1 ; i <= length ; i ++ ) {
        for (int j = 1 ; j <= breadth ; j ++ ){
            if (i == j) continue;
            int best = 1e5;
            for (int k = 1 ; k <= (j+1)/2  && k < j ; k ++ ) {
                best = min (best, minimum_cuts[i][j-k] + minimum_cuts[i][k] + 1);
            }
            for (int k = 1 ; k <= (i+1)/2  && k < i; k ++ ) {
                best = min(best, minimum_cuts[i-k][j] + minimum_cuts[k][j] + 1);
            }
            minimum_cuts[i][j] = best;
        }
    }

    cout << minimum_cuts[length][breadth] << '\n';
    return 0;
}
