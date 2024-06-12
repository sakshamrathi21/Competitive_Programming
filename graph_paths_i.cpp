#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int md = 1000000007;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < b[0].size(); j++) 
            for ( int k = 0; k < a.size(); k++) 
                (c[i][j] += a[i][k]*b[k][j]%md)%=md;
    return c;
}

vector<vector<int>> exp(vector<vector<int>> x, unsigned int y){
    vector<vector<int>> res(x.size(), vector<int>(x.size()));
    for ( int i = 0; i < x.size(); i++) 
        res[i][i] = 1;

    while(y>0){
        if (y&1) {
            res = mul(res,x);
        }
        y=y>>1; 
        x = mul(x,x);
    }
    return res;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));
    while (m--) {
        int x, y;
        cin >> x >> y;
        adjacency_matrix[x-1][y-1] += 1;
    }
    // cout << "hello " << endl;
    // vector<vector<int>> num_paths = exp(adjacency_matrix, k);
    cout << exp(adjacency_matrix, k)[0][n-1];
}