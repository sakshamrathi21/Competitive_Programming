#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    long double prob[64][64][k + 1];
    //first for robot, second for position, third for number of steps
    for (int i = 0 ; i < 64 ; i ++ ) {
        for (int j = 0 ; j < 64 ; j ++) {
            for (int t = 0 ; t <= k ; t ++) {
                prob[i][j][t] = 0;
            }
        }
    }

    for (int i = 0 ; i < 64 ; i ++ ) {
        prob[i][i][0] = 1;
    }
    for (int t = 1 ; t <= k ; t ++) {
        for (int i = 0 ; i < 64 ; i ++ ) {
            for (int j = 0 ; j < 64 ; j ++) {
                long double count = 0;
                if (j >= 8) count++;
                if (j <= 55) count ++;
                if (j%8 != 7) count ++;
                if (j%8 != 0) count ++;
                // cout << count << endl;
                if (j >= 8) prob[i][j-8][t] += (1/count)*prob[i][j][t-1];
                if (j <= 55) prob[i][j+8][t] += (1/count)*prob[i][j][t-1];
                if (j%8 != 7) prob[i][j+1][t] += (1/count)*prob[i][j][t-1];
                if (j%8 != 0) prob[i][j-1][t] += (1/count)*prob[i][j][t-1];

                // if (j >= 8) prob[i][j][t] += (1/count)*prob[i][j-8][t-1];
                // if (j <= 55) prob[i][j][t] += (1/count)*prob[i][j+8][t-1];
                // if (j%8 != 7) prob[i][j][t] += (1/count)*prob[i][j+1][t-1];
                // if (j%7 != 0) prob[i][j][t] += (1/count)*prob[i][j-1][t-1];
                // if (count == 0) cout << " hello world";
            }
        }
    }

    long double empty_prob[64];

    for (int i = 0 ; i < 64 ; i ++ ) {
        empty_prob[i] = 1;
    }

    

    for (int i = 0 ; i < 64 ; i ++ ) {
        for (int j = 0 ; j < 64 ; j ++ ) {
            // cout << empty_prob[j] << endl;
            empty_prob[j] *= (1-prob[i][j][k]);
            // cout << empty_prob[j] << endl;
        }
    }

    long double result = 0;

    for (int i = 0 ; i < 64 ; i ++ ) {
        result += empty_prob[i];
    }
    cout<<setprecision(6)<<fixed;
    cout << result;
}
