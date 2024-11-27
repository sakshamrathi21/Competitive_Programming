#include<bits/stdc++.h>
using namespace std;
#define ll long long

int neighbourX[4] = {0, 0, 1, -1};
int neighbourY[4] = {1, -1, 0, 0};

int n, m, answer = 0;
int vis[1010][1010];
char grid[1010][1010];

bool isValid(int y, int x) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= n) return false;
    if (x >= m) return false;
    if (grid[y][x] == '#') return false;
    return true;
}

void DFS(int y, int x) {
    vis[y][x] = 1;
    for (int i = 0 ; i < 4 ; i ++ ) {
        int newX = x + neighbourX[i];
        int newY = y + neighbourY[i];
        if (isValid(newY, newX)) {
            if (!vis[newY][newX]) {
                DFS(newY, newX);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++ ) {
        for (int j = 0 ; j < m ; j ++ ) {
            cin >> grid[i][j];
            vis[i][j] = 0;
        }
    }

    for (int i = 0 ; i < n ; i ++ ) {
        for(int j = 0 ; j < m ; j ++ ) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                DFS(i, j);
                answer ++;
            }
        }
    }
    cout << answer << '\n';
}
