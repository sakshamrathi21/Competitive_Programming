/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 20 19:31:38 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> a;

int powcal(int x, int p) {
    int cnt = 0;
    while (x%p == 0) {
        x/= p;
        cnt++;
    }
    return cnt;
}
vector<vector<int>> dp;
vector<vector<char>> path;
int mp(int row, int col, int p) {
    if (dp[row][col] != -1) return dp[row][col];
    if (row == n-1 && col == n-1) {path[row][col] = 'U' ;return dp[row][col] = powcal(a[row][col], p);}
    if (row == n-1) {
        path[row][col] = 'R';
        return dp[row][col] = powcal(a[row][col], p) + mp(row, col+1, p);
    }
    if (col == n-1) {
        path[row][col] = 'D';
        return dp[row][col] = powcal(a[row][col], p) + mp(row+1, col, p);
    }
    int x1 = powcal(a[row][col], p) + mp(row, col+1, p);
    int x2 = powcal(a[row][col], p) + mp(row+1, col, p);
    if (x1 < x2) {
        path[row][col] = 'R';
        return dp[row][col] = x1;
    }
    path[row][col] = 'D';
    return dp[row][col] = x2;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.assign(n, vector<int>(n));
    int zi = -1, zj = -1;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            cin >> a[i][j]; 
            if (a[i][j] == 0) {
                zi = i; 
                zj = j; 
                a[i][j] = 10;
            }
        }
    }
    dp.assign(n, vector<int>(n, -1));
    path.assign(n, vector<char>(n));
    int c1 = mp(0, 0, 2);
    
    string s1;
    int i = 0, j = 0;
    while (path[i][j] != 'U') {
        s1.push_back(path[i][j]);
        if (path[i][j] == 'R') j++;
        else i++;
    }
    dp.assign(n, vector<int>(n, -1));
    int c2 = mp(0, 0, 5);
    string s2;
    i = 0, j = 0;
    while (path[i][j] != 'U') {
        s2.push_back(path[i][j]);
        if (path[i][j] == 'R') j++;
        else i++;
    }
    // cout << s2.length() << " hello" << endl;
    if (zi != -1 && c1 > 1 && c2 > 1) {
        cout << 1 << "\n";
        for (int i = 0 ; i < zi ; i ++) cout << "D";
        for (int j = 0 ; j < zj ; j ++) cout << "R";
        for (int i = zi+1 ; i < n ; i ++) cout << "D";
        for (int j = zj+1 ; j < n ; j ++) cout << "R";
        return 0;
    }
    if (c1 < c2) cout << c1 << "\n" << s1;
    else cout << c2 << "\n" << s2;
}
