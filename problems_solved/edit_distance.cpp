#include<bits/stdc++.h>
using namespace std;
#define ll long long
string X;
string Y;
int n, m;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, X);
    getline(cin, Y);
    n = X.length();
    m = Y.length();
    vector<vector<int>> distance(n+1, vector<int>(m+1, INT16_MAX));
    distance[0][0] = 0;
    for (int i = 0 ; i <= n ; i ++ ) {
        for (int j = 0 ; j <= m ; j ++ ) {
            if (i == 0 && j == 0) continue;
            if (j >= 1) {
                distance[i][j] = min(distance[i][j], distance[i][j-1] + 1);
            }
            if (i >= 1) {
                distance[i][j] = min(distance[i][j], distance[i-1][j] + 1);
            }
            if (i>= 1 && j >= 1) {
                int cost = 0;
                if (X[i-1] != Y[j-1]) cost = 1;
                distance[i][j] = min(distance[i][j], distance[i-1][j-1] + cost);
            }
        }
    }

    cout << distance[n][m] << '\n';
}
