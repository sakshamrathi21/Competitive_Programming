#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
    
vector<int> moves;
vector<bool> arr;

bool if_possible(int l) {
    if (l < 0) return false;
    if (!arr[l]) return true;
    return false;
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int move;
    for (int i = 0 ; i < n ; i ++ ) {
        arr.push_back(false);
    }
    for (int i = 0 ; i < k ; i ++ ) {
        cin >> move;
        moves.push_back(move);
        arr[moves[i] - 1] = true;
    }
    for (int i = 0 ; i < n ; i ++ ) {
        if (!arr[i]) {
            bool possible = false;
            for (int j = 0 ; j < k ; j ++ ) {
                if (if_possible(i - moves[j])) {
                    possible = true;
                    break;
                }
            }
            if (possible) arr[i] = true;
        }
    }

    for (int i = 0 ; i < n ; i ++ ) {
        if (arr[i]) cout <<'W';
        else cout << 'L';
    }
    return 0;

}
