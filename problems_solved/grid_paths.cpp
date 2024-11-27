#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gridSize;
vector<vector<bool> > grid;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> gridSize;

    for (int i = 0 ; i <= gridSize ; i ++ ) {
        vector<bool> row(gridSize + 1, false);
        grid.push_back(row);
    }

    for (int i = 1 ; i <= gridSize ; i ++ ) {
        for (int j = 1 ; j <= gridSize ; j ++ ) {
            char character_t;
            cin >> character_t;
            if (character_t == '.') grid[i][j] = true;
            else grid[i][j] = false;
        }
    }

    vector<vector<int> > num_paths;
    for (int i = 0 ; i <= gridSize ; i ++ ) {
        vector<int> paths(gridSize + 1, 0);
        num_paths.push_back(paths);
    }
    num_paths[1][1] = 1;

    for (int i = 1 ; i <= gridSize ; i ++ ) {
        for (int j = 1 ; j <= gridSize ; j ++ ) {
            if (!grid[i][j]) {
                // cout << " HELLO WORLD" << endl;
                num_paths[i][j] = 0;
                continue;
            }
            if (i == 1 && j == 1) continue;
            num_paths[i][j] = (num_paths[i-1][j] + num_paths[i][j-1])%(1000000007);
        }
    }

    cout << num_paths[gridSize][gridSize]%(1000000007) << '\n' ;
}
